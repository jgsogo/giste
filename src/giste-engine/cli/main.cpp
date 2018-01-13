
#include <iostream>

#include <boost/program_options.hpp>


int main(int argc, char** argv)
{
	try
	{
		std::cout << "Giste Engine\n\n";
		
		// Work on program options
		namespace po = boost::program_options;
		po::options_description desc("Giste engine CLI options");
		desc.add_options()
			("help", "Print help messages")
			("config", "Configuration file");

		po::variables_map vm;
		try
		{
			po::store(po::parse_command_line(argc, argv, desc), vm);
			po::notify(vm);
		}
		catch(po::error& e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
			std::cerr << desc << std::endl; 
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

