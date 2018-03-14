
#include <iostream>

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "log_level_param.hpp"
#include "protozoo-core/config.h"
#include "protozoo-core/plugin_handler.h"


int main(int argc, char** argv)
{
	try
	{
		// Program options
		boost::filesystem::path config_file("config.yaml");

		// Work on program options
		namespace po = boost::program_options;
		po::options_description desc("Program usage", 1024, 512);
		desc.add_options()
			("config,c", po::value<boost::filesystem::path>(&config_file)->required()->default_value(config_file), "Config file to use")
			("log-level,l", po::value<log_level>()->default_value(log_level(spdlog::level::info)), std::string("log level (" + log_level::options() + ")").c_str())
			("help", "Print help message")
			;

		po::variables_map vm;
		try
		{
			po::store(po::parse_command_line(argc, argv, desc), vm);
			if (vm.count("help"))
			{
				std::cout << desc << std::endl;
				return 0;
			}
			po::notify(vm);
		}
		catch (po::required_option& e)
		{
			std::cerr << "Required option missing: " << e.what() << "\n\n";
			std::cout << desc << std::endl;
			return -1;
		}
		catch(po::error& e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
			std::cerr << desc << std::endl;
			return -1;
		}

		// Get logger level (initialize also child loggers)
		spdlog::level::level_enum log_level = vm["log-level"].as<::log_level>()._level;
		auto console = spdlog::stdout_color_mt("protozoo");
		console->set_level(log_level);

		if (!boost::filesystem::exists(config_file))
		{
			console->error("Config file {} does not exist or it is inaccesible.", config_file);
			std::cerr << "Config file " << config_file << " does not exists or it is inaccesible." << std::endl;
			return -1;
		}

		// TODO: Playing around
		std::ifstream infile(config_file.string());
		protozoo::core::Config& cfg = protozoo::core::Config::parse(infile);
        cfg.

		protozoo::core::PluginHandler plg_handler;
		plg_handler.load("C:/Users/e047439/src/giste/install/plugins");

	}
	catch(std::exception& e)
	{
		std::cerr << "Unhandled exception reached top of main: "
		          << e.what() << ". Application will now exit" << std::endl;
		return -1;
	}

	return 0;
}

