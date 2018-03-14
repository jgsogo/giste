
#include "protozoo-core/config.h"

#include "yaml-cpp/yaml.h"


namespace protozoo { namespace core {

    struct Config::Impl
    {
        Impl(std::istream& is) : config(YAML::Load(is)) {}
        YAML::Node config;
    };

	Config::Config(std::istream& is) : pImpl(new Impl(is)) {}

	Config::~Config() = default;

	Config& Config::parse(std::istream& is)
	{
		static Config cfg(is);
		return cfg;
	}

    std::vector<std::filesystem::path> plugins_path() const
    {
        std::vector<std::filesystem::path> ret;
        
        return ret;
    }

}}
