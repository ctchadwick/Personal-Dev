
#include <boost/make_shared.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/chrono.hpp>

#include <strtk.hpp>

#include <spdlog/spdlog.h>

#include "PHDelegate.hpp"
#include "PHSignal.hpp"

#include "credentials3.hpp"
#include "hi-res-time2.hpp"
#include "fast-log2.hpp"

#include "tws-cmdline.hpp"

#include "idobos-trigger-agent.hpp"
// --------------------------------------------------------------------------------------------------

typedef Instruments::RealTimeBarData RTBar;
typedef std::vector<RTBar> RTBarVec;
typedef Instruments::BarData BAR;
typedef std::vector<BAR> BarVec;

// --------------------------------------------------------------------------------------------------
void file_to_rtbars(const std::string& file, RTBarVec& bars)
{
	//std::cout << file << std::endl;
	
	const boost::posix_time::ptime time_epoch{boost::gregorian::date{1970,1,1}, boost::posix_time::time_duration{0,0,0}};
	const boost::posix_time::time_duration st{7,25,0};	
	const boost::posix_time::time_duration et{15,30,0};
	
	std::vector<std::string> strbars;
	mcm_assorted::for_each_line(file, strbars);
	
	bool skip = true;
	for(auto&& sbar : strbars)
	{
		if(skip)
		{
			//skip header
			skip = false;
			continue;
		}
		
		RTBar b;
		// Datetime,Open,High,Low,Close,Volume,Avg,BarCnt
		// 20180430  10:00:00,67.66,67.69,67.65,67.69,112,67.671,60
		std::string sts;
		strtk::parse(sbar, ",", sts, b.open, b.high, b.low, b.close, b.volume, b.average, b.barCount);
				
		boost::gregorian::date day{BLCui(sts.substr(0,4)), BLCui(sts.substr(4,2)), BLCui(sts.substr(6,2))};
		boost::posix_time::time_duration bartd{BLCui(sts.substr(10,2)), BLCui(sts.substr(13,2)), BLCui(sts.substr(16,2))};
		boost::posix_time::ptime bartime{day, bartd};
		boost::posix_time::ptime bst{day, st};	
		boost::posix_time::ptime bet{day, et};	
				
		b.ibtimestamp = (bartime - time_epoch).total_seconds() + 4*3600;
		b.set_time();
		b.conid = 1;
		
		if(bartime < bst || bartime > bet)
			continue;
		
		bars.emplace_back(b);
	}
} 

// --------------------------------------------------------------------------------------------------
struct _logger
{
	_logger()
	{
		CLOG = spdlog::get("console");
	}
	
	~_logger() 
	{
	}
	
	void print(const std::string& msg)
	{
		CLOG->info(msg);
	}
	
	std::shared_ptr<spdlog::logger> CLOG;
};

// --------------------------------------------------------------------------------------------------
void run_backtest(const std::string& file, int& ordseed, double& equity, bool track_trades_hdr, std::ofstream& ofs, std::ofstream& tlofs)
{
	AlgoParameters AP;
	AP.cid = 1;
	AP.stralgo = "idobos";
	AP.is_testing = true;
		
	IntradayOBOSTriggerAgent agent(AP, tlofs);
	agent.setup();
	agent.initialize_trade_tracking(track_trades_hdr);
			
	RTBarVec bars;
	file_to_rtbars(file, bars);
			
	//boost::random::mt19937 RNG;
	//boost::random::uniform_int_distribution<> off(0,2);
	// take first 480 bars and initialize agent
	BarVec regbars;
	size_t index = 0;
	int cutoff = std::min(100, (int)bars.size());
	for(size_t i = 0; i < cutoff; i++)
	{
		BAR b;
		b.from_realtimebar(bars[i]);
		regbars.push_back(b);
		index++;
	}
	
	if(!agent.initialize(regbars, ordseed, equity))
		return;
	
	for(size_t i = index; i < bars.size(); i++)
		agent.update_from_5sec_bar(bars[i]);
		
	agent.close_position("eod+");	
	std::for_each(agent.m_trades.begin(), agent.m_trades.end(), [&ofs](auto&& p)
	{ 
		ofs << p.second.first.print_csv() << std::endl;
	});

	equity = agent.m_equity;
}

// --------------------------------------------------------------------------------------------------
void execute_bulk_backtest(const std::string& mfifile, _logger& logger)
{
	// load master-file-detail
	// expecting: header for first line
	// 00:File:			cleaned/CLM8-5sec-20180503.csv,
	// 01:Nfile:		13,
	// 02:SetStart:		2018-05-03 09:34:30,
	// 03:SetEnd:		2018-05-03 16:34:30,
	// 04:SetLength:	5041,
	// 05:SetNGaps:		0,
	// 06:SetNDups:		0,
	// 07:Range:		T08:30/T15:00,
	// 08:HasFullRange:	FALSE,
	// 09:RngDiff:		762,
	// 10:RngStart:		2018-05-03 09:34:30,
	// 11:RngEnd:		2018-05-03 15:00:55,
	// 12:RngLength:	3918,
	// 13:RngNGaps:	0,
	// 14:RngNDups:	0,
	// 15:Usable:		TRUE,
	// 16:ForTraining:	FALSE,
	// 17:Notes:	

	std::ofstream ofs("trades.csv");
	std::ofstream tlofs("tradelifetimes.csv");
	TradePosition tp;
	ofs << tp.print_header() << std::endl;
		
	int fcnt = 1;
	std::vector<std::string> mfis;
	mcm_assorted::for_each_line(mfifile, mfis);
	bool skip_header = true;
	int ordseed = 1;
	double equity = 3000.00;
	double extract = 0;
	bool track_trades_hdr = true;
	
	for(auto&& f : mfis)
	{
		if(skip_header)
		{
			skip_header = false;
			continue;
		}
		
		std::vector<std::string> sv;
		strtk::parse(f, ",", sv);
				
		if(sv.size() < 17)
			continue;
		
		if(sv[16] != "TRUE")
		{
			//logger.print(fmt::format("{:s}|is training:{:s}", sv[0], sv[16]));
			run_backtest(sv[0], ordseed, equity, track_trades_hdr, ofs, tlofs);
			track_trades_hdr = false;
			fcnt++;
			ordseed += 20;
		}
		
		if(equity > 10000.00)
		{	
			extract += 7000.0;
			equity -= 7000.00;
			logger.print(fmt::format("Extracted 7000.0, cnt:{:d}", fcnt));
		}
	}
	
	logger.print(fmt::format("Nfiles:{:d} Total pnl:{:f} extr:{:f}", fcnt, equity, extract));
}

// ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	CommandArguments2 ARGS;
	if(handle_cmd_input2(argc, argv, ARGS) != 0)
		return 1;
	
	Credentials CREDS;
	if(!CREDS.hasgroup("consolelog"))
	{
		CREDS["consolelog.id"] = "console";
		CREDS["consolelog.pattern"] = "[%T.%e][%l] %v";
		CREDS["consolelog.level"] = "debug";
	}

	std::shared_ptr<spdlog::logger> CLOG = spdlog::stdout_color_mt(CREDS["consolelog.id"]);
	CLOG->set_pattern(CREDS["consolelog.pattern"]);
	CLOG->set_level(spdlog::level::from_str(CREDS["consolelog.level"]));
	_logger logger;
		
	execute_bulk_backtest(ARGS.mfi, logger);
	
	return 0;
}
