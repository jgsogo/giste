
#include "protozoo-core/config.h"

#include "yaml-cpp/yaml.h"


namespace protozoo { namespace core {

	Config::Config() {}

	Config::~Config() {}

	Config& Config::parse(std::istream& is)
	{
		YAML::Node config = YAML::Load(is);
		static Config cfg;
		return cfg;
	}

}}
