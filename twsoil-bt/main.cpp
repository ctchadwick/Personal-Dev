
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

#include "vwap-signal-agent.hpp"


typedef Instruments::RealTimeBarData RTBar;
typedef std::vector<RTBar> RTBarVec;

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
		
		if(bartime < bst || bartime > bet)
			continue;
		
		bars.emplace_back(b);
	}
} 

struct _logger
{
	_logger()
	{
		//CLOG = spdlog::get("console");
	}
	void print(const std::string& msg)
	{
		//CLOG->warn(msg);
		std::cout << msg << std::endl;
	}
	
	//std::shared_ptr<spdlog::logger> CLOG;
};

const std::string run_backtest(const std::string& file, int32 wind, double ltgt)
{
	VWAPSignalAgent VWAP(wind, file);
	VWAP.set_trade_parameters(0.6, ltgt, 0.02, 0.04, true);
	
	RTBarVec bars;
	file_to_rtbars(file, bars);
	
	boost::random::mt19937 RNG;
	boost::random::uniform_int_distribution<> off(0,2);
	
	for(auto&& bar : bars)
	{
		VWAP.update_bidask(bar.close - off(RNG)*0.01, bar.close + off(RNG)*0.01);
		VWAP.update_from_5sec_bar(bar);
	}
	
	VWAP.close_cur_position();
	VWAP.save_trades();
	return VWAP.print_csv();
}

void execute_bulk_backtest()
{
	std::vector<std::string> files = {
		"CL-5sec-20180430.csv", "CL-5sec-20180502.csv", "CL-5sec-20180503.csv",
		"CL-5sec-20180508.csv", "CL-5sec-20180509.csv", "CL-5sec-20180510.csv"
//		"CL-5sec-20180511.csv", "CL-5sec-20180515.csv", "CL-5sec-20180516.csv",
//		"CL-5sec-20180517.csv", "CL-5sec-20180523.csv", "CL-5sec-20180524.csv",
//		"CL-5sec-20180525.csv", "CL-5sec-20180529.csv", "CL-5sec-20180530.csv",
//		"CL-5sec-20180601.csv", "CL-5sec-20180604.csv", "CL-5sec-20180605.csv",
//		"CL-5sec-20180606.csv", "CL-5sec-20180607.csv", "CL-5sec-20180608.csv",
//		"CL-5sec-20180611.csv", "CL-5sec-20180612.csv", "CL-5sec-20180613.csv",
//		"CL-5sec-20180614.csv", "CL-5sec-20180615.csv", "CL-5sec-20180618.csv"
		};
	
	for(auto&& f : files)
		std::cout << run_backtest(f, 1, 0.1) << std::endl;
}

// ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
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
	
//	VWAPSignalAgent VWAP(10, "BT-sma");
//	VWAP.set_trade_parameters(0.6, 0.06, 0.01, 0.02, true);
//	
//	//DEPTH->sig_notify_depth_balance.Connect(VWAP003.get(), &VWAPSignalAgent::update_bidask_balance);
//	//VWAP.sig_notify_msg.Connect(&logger, &_logger::print);
//	
//	RTBarVec bars;
//	file_to_rtbars(argv[1], bars);
//		
//	for(auto&& bar : bars)
//	{
//		//CLOG->warn(bar.print());
//		VWAP.update_bidask(bar.close - 0.01, bar.close + 0.01);
//		VWAP.update_from_5sec_bar(bar);
//	}
//	
//	VWAP.close_cur_position();
//	VWAP.save_trades();
//	//CLOG->warn(VWAP.print());
//	logger.print(VWAP.print_csv(true));
	
	execute_bulk_backtest();
	
	return 0;
}