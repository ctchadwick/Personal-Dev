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
		error 		= 0,
		help		= 1,
		archive		= 2,
		history		= 3,
		live		= 4,
		pseudo		= 5
	};
	
	// -----------------------------------------------------------------------
	inline const int32 from_string(const std::string& s)
	{
		if(s == "help")	return help;
		if(s == "archive") return archive;
		if(s == "history") return history;
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
	std::vector<std::string> 	history_dates;
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
			("histories", po::value<std::string>(), "CSV list of dates for historical data; YYYYMMDD fmt, given in 30sec bars close to close")
			("mode", po::value<std::string>(), "run mode, one of archive|history|live|pseudo")
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
		    	TP.getOS() << desc << std::endl;
		    	return 2;
		    }

		    if(p.first == "config")
		    	args.config_file = p.second.as<std::string>();

		    if(p.first == "histories")
		    {
				strtk::split(strtk::single_delimiter_predicate<std::string::value_type>(','), 
					p.second.as<std::string>(),
					strtk::range_to_type_back_inserter(args.history_dates),
					strtk::split_options::compress_delimiters);
		    }

		    if(it->first == "mode")
		    	args.mode = TWSOptions::from_string(p.second.as<std::string>());

		    if(it->first == "expiry")
		       	args.expiry = strtime_to_double(p.second.as<std::string>());
	
		    if(it->first == "with-ws")
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
