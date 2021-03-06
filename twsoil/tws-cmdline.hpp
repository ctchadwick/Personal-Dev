// -------------------------------------------------------------------------------------------------------------------------

#ifndef TWS_CMDLINE_HPP_
#define TWS_CMDLINE_HPP_
// -------------------------------------------------------------------------------------------------------------------------

#include <boost/program_options.hpp>

#include "mcm-assorted.hpp"


// ------------------------------------------------------------------------------------------------------
namespace TWSOptions
{
	// -----------------------------------------------------------------------
	enum
	{
		error, 		
		help,
		archive,
		history,
		history_only,
		today,
		histogram,
		live,
		morning
	};
	
	// -----------------------------------------------------------------------
	inline const int32 from_string(const std::string& s)
	{
		if(s == "help")	return help;
		if(s == "archive") return archive;
		if(s == "history") return history;
		if(s == "history-only") return history_only;
		if(s == "today") return today;
		if(s == "histogram") return histogram;
		if(s == "live") return live;
		if(s == "morning") return morning;
		return error;
	}
}

// ------------------------------------------------------------------------------------------------------
struct CommandArguments
{
	// -----------------------------------------------------------------------
	CommandArguments()
	: config_file("tws.ini"), expiry(-1.0), mode(TWSOptions::error), with_websocket(false), details("")
	{}

	// -----------------------------------------------------------------------
	std::string					config_file;
	double						expiry;
	int32						mode;
	bool						with_websocket;
	std::string					details;
};

// ------------------------------------------------------------------------------------------------------
inline int handle_cmd_input(int argc, char* argv[], CommandArguments& args)
{
	namespace po = boost::program_options;
	try
	{
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "usage instructions")
			("config", po::value<std::string>(), "config file to use, default is tws.ini")
			("mode", po::value<std::string>(), "run mode, one of archive|today|histogram|live|pseudo")
			("history-only", po::value<std::string>(), "get daily data history as db-symb;YYYYMMDD;resolution eg: CLU9;20190801;5 secs")
			("expiry", po::value<std::string>(), "auto expiration time in HH:MM:SS 24-hr format, default is 17:01:00")
			("with-ws", "run the affiliated websocket")
			;

		po::variables_map vm;
	    po::store(po::parse_command_line(argc, argv, desc), vm);
	    po::notify(vm);

	    if(vm.empty())
	    {
	    	std::cout << desc << std::endl;
	    	return 2;
	    }

		//for(po::variables_map::iterator it = vm.begin(); it != vm.end(); ++it)
	    for(auto&& p : vm)
		{
		    if(p.first == "help")
		    {
		    	std::cout << desc << std::endl;
		    	return 2;
		    }

		    if(p.first == "config")
		    	args.config_file = p.second.as<std::string>();

		    if(p.first == "mode")
				args.mode = TWSOptions::from_string(p.second.as<std::string>());
				
			if(p.first == "history-only")
			{	
				args.mode = TWSOptions::from_string(p.first);
				args.details = p.second.as<std::string>();
			}
			
		    if(p.first == "expiry")
		       	args.expiry = strtime_to_double(p.second.as<std::string>());
	
		    if(p.first == "with-ws")
		    	args.with_websocket = true;
	    }

	    return 0;

	}
	catch(std::exception& e)
	{
		std::cerr << "error: " << e.what() << std::endl;
		return 1;
	}
	catch(...)
	{
		std::cerr << "unknown exception" << std::endl;
		return 1;
	}

	return 1;
}


// ------------------------------------------------------------------------------------------------------
struct CommandArguments2
{
	// -----------------------------------------------------------------------
	CommandArguments2()
	: mfi("master-file-info.csv"),
	thresh(1000)
	{}

	// -----------------------------------------------------------------------
	std::string					mfi;
	int							thresh;
};

// ------------------------------------------------------------------------------------------------------
inline int handle_cmd_input2(int argc, char* argv[], CommandArguments2& args)
{
	namespace po = boost::program_options;
	try
	{
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "usage instructions")
			("mfi", po::value<std::string>(), "master file info csv file to use, default is master-file-info.csv")
			("thresh", po::value<int>(), "threshold for volume bar generation, default is 1000")
			;

		po::variables_map vm;
	    po::store(po::parse_command_line(argc, argv, desc), vm);
	    po::notify(vm);

	    if(vm.empty())
	    {
	    	std::cout << desc << std::endl;
	    	return 2;
	    }

	    for(auto&& p : vm)
		{
		    if(p.first == "help")
		    {
		    	std::cout << desc << std::endl;
		    	return 2;
		    }

		    if(p.first == "mfi")
		    	args.mfi = p.second.as<std::string>();
			
			if(p.first == "thresh")
				args.thresh = p.second.as<int>();
	    }

	    return 0;

	}
	catch(std::exception& e)
	{
		std::cerr << "error: " << e.what() << std::endl;
		return 1;
	}
	catch(...)
	{
		std::cerr << "unknown exception" << std::endl;
		return 1;
	}

	return 1;
}




#endif
