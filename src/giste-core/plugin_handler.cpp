
#include "plugin_handler.h"

#include <sstream>
#include <boost/dll/import.hpp> // for import_alias
#include <boost/function.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>


namespace giste { namespace core {

	PluginHandler::PluginHandler() {}
	PluginHandler::~PluginHandler() {}

	void PluginHandler::load(const std::string& directory)
	{
		boost::filesystem::path plugins_directory(directory);
		if (!boost::filesystem::is_directory(directory))
		{
			throw std::runtime_error("Not a directory");
		}

		// Go ahead for everyfile in dir
		typedef std::shared_ptr<Plugin>(pluginapi_create_t)();
		boost::function<pluginapi_create_t> creator;

		for (auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(directory), {}))
		{
			creator = boost::dll::import_alias<pluginapi_create_t>(  // type of imported symbol must be explicitly specified
				entry,                                               // path to library
				"instantiate",                                       // symbol to import
				boost::dll::load_mode::append_decorations            // do append extensions and prefixes
				);

			std::shared_ptr<Plugin> plugin = creator();
			_plugins.push_back(plugin);
			for (auto& item : plugin->get_available())
			{
				auto it = _pipelines.insert(std::make_pair(item, *plugin.get()));
				if (!it.second)
				{
					std::ostringstream os; os << "Pipeline with id '" << item << "' already exists.";
					throw std::runtime_error(os.str());
				}
			}
		}
	}

	pipeline_t PluginHandler::build(const std::string& id) const
	{
		auto it = _pipelines.find(id);
		if (it != _pipelines.end())
		{
			return it->second.build(id);
		}
		std::ostringstream os; os << "Pipeline '" << id << "' not available.";
		throw std::runtime_error(os.str());
	}


}}
