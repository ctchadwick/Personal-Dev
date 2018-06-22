
#include <boost/make_shared.hpp>

#include <spdlog/spdlog.h>

#include "PHDelegate.hpp"
#include "PHSignal.hpp"

#include "credentials3.hpp"
#include "thread-pooler2.hpp"
#include "hi-res-time2.hpp"
#include "fast-log2.hpp"

#include "basic-websocket-server2.hpp"

#include "tws-tracker-database4.hpp"
#include "tws-client2.hpp"
#include "tws-cmdline.hpp"

// ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	CommandArguments ARGS;
	if(handle_cmd_input(argc, argv, ARGS) != 0)
		return 1;
			
	Credentials CREDS;
	if(!CREDS.load_ini_cnfg(ARGS.config_file))
		return 1;
	
	if(!CREDS.hasgroup("consolelog"))
	{
		CREDS["consolelog.id"] = "console";
		CREDS["consolelog.pattern"] = "[%T.%e][%l] %v";
		CREDS["consolelog.level"] = "debug";
	}

	std::shared_ptr<spdlog::logger> CLOG = spdlog::stdout_color_mt(CREDS["consolelog.id"]);
	CLOG->set_pattern(CREDS["consolelog.pattern"]);
	CLOG->set_level(spdlog::level::from_str(CREDS["consolelog.level"]));
	
	try
	{
		ASIOThdPool ATP(2);
		ATP.set_logging(CREDS);
		ATP.run();

		std::shared_ptr<TWSTrackingDatabase> TDB = std::make_shared<TWSTrackingDatabase>(CREDS, ATP);
		TDB->load_contracts_file();
		
		boost::shared_ptr<BasicWebsocketServer> WSSERV;
		if(ARGS.with_websocket)
		{
			WSSERV = boost::make_shared<BasicWebsocketServer>(CREDS, ATP);
			//TDB->sig_notify_webserver.Connect(WSSERV.get(), &BasicWebsocketServer::send_msg);
		}
		
		std::shared_ptr<TWSClient> TWS = std::make_shared<TWSClient>(CREDS, *TDB, ATP);
		TDB->sig_notify_subscribe.Connect(TWS.get(), &TWSClient::bulk_subscribe);
		TWS->run();
									
		switch(ARGS.mode)
		{
		case TWSOptions::archive:
			CLOG->info("TWSOptions::archive");
			TWS->req_current_time();
			TWS->fivesec_archive();
			break;
		case TWSOptions::histogram:
			CLOG->info("TWSOptions::histogram");
			TWS->close_after_data(true);
			TWS->req_histogram_data();
			break;
		case TWSOptions::history:
			CLOG->info("TWSOptions::history");
			TWS->close_after_data(true);
			TWS->req_historical_data();
			break;
		case TWSOptions::today:
			CLOG->info("TWSOptions::today");
			TWS->close_after_data(true);
			TWS->get_todays_historical();
			break;
		case TWSOptions::live:
			CLOG->info("TWSOptions::live");
			TWS->req_all_open_orders();
			//TWS->req_auto_open_orders();
			//TWS->req_open_orders();
			//TWS->req_account_updates(true);
			TWS->req_positions();
			TWS->bulk_subscribe();
			TWS->fivesec_archive();
			break;
		case TWSOptions::pseudo:
			CLOG->info("TWSOptions::pseudo");
//			TWS.req_mrk_data();
//			//TWS.req_realtime_bars(cntr, 5, show_items, use_rth);
//			//TWS.req_realtime_bars();
//			TWS.req_mrk_depth();
			break;
		default:
			break;
		}
	
		CLOG->info("Awaiting in main...");
		ATP.join();
	}
	catch(...)
	{
		std::cerr << " exception..." << std::endl;
	}

	return 0;
}

