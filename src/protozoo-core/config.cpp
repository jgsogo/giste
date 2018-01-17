
#include "giste-core/config.h"

#include "yaml-cpp/yaml.h"


namespace giste { namespace core {

	Config::Config() {}

	Config::~Config() {}

	Config& Config::parse(std::istream& is)
	{
		YAML::Node config = YAML::Load(is);
		static Config cfg;
		return cfg;
	}

}}
