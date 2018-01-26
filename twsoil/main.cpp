
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

		//std::shared_ptr<TWSTrackingDatabase> TDB = std::make_shared<TWSTrackingDatabase>(CREDS, ATP);
		//TDB->load_contracts_file();
		
		std::shared_ptr<BasicWebsocketServer> WSSERV;
		if(ARGS.with_websocket)
		{
			WSSERV = std::make_shared<BasicWebsocketServer>(CREDS, ATP);
			//TDB->sig_notify_webserver.Connect(WSSERV.get(), &BasicWebsocketServer::send_msg);
		}
		
		//std::shared_ptr<TWSClient> std::make_shared<TWSClient>(CREDS, TDB, ATP);
		
		switch(ARGS.mode)
		{
		case TWSOptions::archive:
			CLOG->info("TWSOptions::archive");
//			TWS.initialize();
//			TWS.run();
//			TWS.req_mrk_data();
//			//TWS.req_realtime_bars(cntr, 5, show_items, use_rth);
//			//TWS.req_realtime_bars();
//			TWS.req_mrk_depth();
			break;
		case TWSOptions::history:
			CLOG->info("TWSOptions::history");
//			TWS->initialize(true);
//			TWS->run();
//			TWS->req_current_time();
//			TWS->req_historical_data();
			break;
		case TWSOptions::details:
			CLOG->info("TWSOptions::details");
//			TWS.initialize(true);
//			TWS.run();
//			TWS.req_current_time();
//			TWS.req_contract_data();
			break;
		case TWSOptions::live:
			CLOG->info("TWSOptions::live");
//			TWS.initialize();
//			TWS.run();
//			TWS.req_mrk_data();
//			//TWS.req_realtime_bars(cntr, 5, show_items, use_rth);
//			//TWS.req_realtime_bars();
//			TWS.req_mrk_depth();
			break;
		case TWSOptions::pseudo:
			CLOG->info("TWSOptions::pseudo");
//			TWS.initialize();
//			TWS.run();
//			TWS.req_mrk_data();
//			//TWS.req_realtime_bars(cntr, 5, show_items, use_rth);
//			//TWS.req_realtime_bars();
//			TWS.req_mrk_depth();
			break;
		default:
			break;
		}

		ATP.join();
	}
	catch(...)
	{
		std::cerr << " exception..." << std::endl;
	}

	return 0;
}

