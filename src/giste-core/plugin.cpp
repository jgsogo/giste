
#include "plugin.h"
#include <sstream>
#include <boost/filesystem/path.hpp>


namespace giste { namespace core {

	Plugin::Plugin()
	{
		// TODO: Get plugin version from...
	}

	Plugin::~Plugin()
	{
	}

	const Version& Plugin::get_core_version() const
	{
		return Version::current();
	}

	const Version& Plugin::get_plugin_version() const
	{
		return _version;
	}

	std::vector<std::string> Plugin::get_available() const
	{
		std::vector<std::string> ret;
		std::transform(_pipelines.begin(), _pipelines.end(), std::back_inserter(ret), [](const auto& item){ return item.first;});
		return ret;
	}

	pipeline_t Plugin::build(const std::string& id) const
	{
		auto it = _pipelines.find(id);
		if (it != _pipelines.end())
		{
			return it->second;
		}
		std::ostringstream os; os << "Pipeline '" << id << "' not available.";
		throw std::runtime_error(os.str());
	}

}}
