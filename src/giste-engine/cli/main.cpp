
#include <iostream>

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>


int main(int argc, char** argv)
{
	try
	{
		// Program options
		boost::filesystem::path config_file;

		// Work on program options
		namespace po = boost::program_options;
		po::options_description desc("Program usage", 1024, 512);
		desc.add_options()
			("config,c", po::value<boost::filesystem::path>(&config_file)->required(), "Config file to use")
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

		if (!boost::filesystem::exists(config_file))
		{
			std::cerr << "Config file " << config_file << " does not exists or it is inaccesible." << std::endl;
			return -1;
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Unhandled exception reached top of main: "
		          << e.what() << ". Application will now exit" << std::endl;
		return -1;
	}

	return 0;
}

