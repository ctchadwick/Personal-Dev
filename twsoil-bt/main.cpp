
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

#include "volume-trigger-agent.hpp"
// --------------------------------------------------------------------------------------------------

typedef Instruments::RealTimeBarData RTBar;
typedef std::vector<RTBar> RTBarVec;


// --------------------------------------------------------------------------------------------------
void file_to_rtbars(const std::string& file, RTBarVec& bars)
{
	const boost::posix_time::ptime time_epoch{boost::gregorian::date{1970,1,1}, boost::posix_time::time_duration{0,0,0}};
	const boost::posix_time::time_duration st{8,25,0};	
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
	void print(const std::string& msg)
	{
		CLOG->info(msg);
	}
	
	std::shared_ptr<spdlog::logger> CLOG;
};

// --------------------------------------------------------------------------------------------------
const std::string run_backtest(const std::string& file, double& pnl, _logger& logger)
{
	int32 cid = 1;
	std::tuple<int32, int32, int32> windows = std::make_tuple(12, 60, 120);
	std::tuple<double, double, int32, int32> thresholds = std::make_tuple(6.0, -0.15, 80, 240);
	
	VolumeTriggerAgent agent(cid, windows, thresholds);
	agent.sig_notify_msg.Connect(&logger, &_logger::print);
		
	RTBarVec bars;
	file_to_rtbars(file, bars);
	
//	boost::random::mt19937 RNG;
//	boost::random::uniform_int_distribution<> off(0,2);
	
	for(auto&& bar : bars)
	{
		agent.update_from_5sec_bar(bar);
	}
	
	pnl += agent.m_total_pnl;
	
//	VWAP.close_cur_position();
//	VWAP.save_trades();
	return "";
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

	double pnl = 0.0;
	int fcnt = 1;
	std::vector<std::string> mfis;
	mcm_assorted::for_each_line(mfifile, mfis);
	for(auto&& f : mfis)
	{
		std::vector<std::string> sv;
		strtk::parse(f, ",", sv);
		if(sv.size() < 17)
			continue;
			
		if(sv[16] == "TRUE")
		{
			logger.print(fmt::format("{:s}|is training:{:s}", sv[0], sv[16]));
			run_backtest(sv[0], pnl, logger);
			if(fcnt++ >= 1)
				break;
		}
	}
	
	logger.print(fmt::format("Total pnl:{:f}", pnl));
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