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
		today,
		histogram,
		live,
		pseudo 	
	};
	
	// -----------------------------------------------------------------------
	inline const int32 from_string(const std::string& s)
	{
		if(s == "help")	return help;
		if(s == "archive") return archive;
		if(s == "history") return history;
		if(s == "today") return today;
		if(s == "histogram") return histogram;
		if(s == "live") return live;
		if(s == "pseudo") return pseudo;
		return error;
	}
}

// ------------------------------------------------------------------------------------------------------
struct CommandArguments
{
	// -----------------------------------------------------------------------
	CommandArguments()
	: config_file("tws.ini"), expiry(-1.0), mode(TWSOptions::error), with_websocket(false)
	{}

	// -----------------------------------------------------------------------
	std::string					config_file;
	double						expiry;
	int32						mode;
	bool						with_websocket;
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
			("mode", po::value<std::string>(), "run mode, one of archive|history|today|histogram|live|pseudo")
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

#endif
