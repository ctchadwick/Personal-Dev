/*
 * \file amain.cpp
 * \brief 
 *
 * \author C.T. Chadwick: Monadnock Capital Management, LP
 * \date 2019-09
 */
// -------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>

#include "hi-res-time2.hpp"
#include "fast-log2.hpp"
#include "credentials3.hpp"
#include "thread-pooler2.hpp"

// -------------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------
inline void modify_for_prog(Credentials &CREDS)
{
	std::string lfbase = CREDS["info_and_logging.base_directory"];
	boost::filesystem::create_directory(boost::filesystem::path(lfbase));
	lfbase.push_back('/');

	if(!CREDS.hasgroup("consolelog"))
	{
		CREDS["consolelog.id"] = "console";
		CREDS["consolelog.pattern"] = "[%T.%e][%l] %v";
		CREDS["consolelog.level"] = "debug";
	}
}

// -------------------------------------------------------------------------------------------------------------------------
LONG WINAPI VectoredHandlerT(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
	std::cerr << "[SEH-EXCEPTION]: application terminating due to unknown issue" << std::endl;
	TerminateProcess(GetCurrentProcess(), -1);
    return EXCEPTION_CONTINUE_EXECUTION;
}

// -------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
//	PVOID ht1 = AddVectoredExceptionHandler(1, ApplicationVectoredExceptionHandlder);
//    BOOST_SCOPE_EXIT(&ht1)
//	{
//    	RemoveVectoredExceptionHandler(ht1);
//    }
//    BOOST_SCOPE_EXIT_END

	// -----------------------------------------------------------------------
	// introduction header
	SetConsoleTitle("AProg");

	// -----------------------------------------------------------------------
	// handle configuration file loading, setup global objects
	std::string cnfgpath = argc == 2 ? argv[1] : "";
	std::string cnfg_file = cnfgpath.empty() ? "prog.ini" : cnfgpath;

	Credentials CREDS;

	if(!CREDS.load_ini_cnfg(cnfg_file))
		if(!CREDS.load_ini_cnfg("../" + cnfg_file))
			return 1;

	modify_for_prog(CREDS);

	HiResTime2::HiResTimer HRT;

	std::shared_ptr<spdlog::logger> CLOG = spdlog::stdout_color_mt(CREDS["consolelog.id"]);
	CLOG->set_pattern(CREDS["consolelog.pattern"]);
	CLOG->set_level(spdlog::level::from_str(CREDS["consolelog.level"]));

	try
	{
		// -----------------------------------------------------------------------
		// start up the main portion of the application
		ASIOThdPool ATP(2);
		ATP.run();

		//ApplicationManager AM(ATP, HRT, "MSE");
		//AM.set_times("00:00:30", "23:59:00");
		//AM.run();

		FastLog2::StandardLogger LOG;
		LOG.initialize_yyyymm("prog", CREDS["info_and_logging.log_file"]);
		LOG.add_date_line("Initialized prog");

		// -----------------------------------------------------------------------
		// set up
		
		
		CLOG->info("finished config...");
		ATP.join();
	}
	catch(std::exception& err)
	{
		CLOG->error(err.what());
		return 1;
	}
	catch(...)
	{
		CLOG->error("Terminated from other exception type.");
		return 2;
	}

	// -----------------------------------------------------------------------
	return 0;
}
