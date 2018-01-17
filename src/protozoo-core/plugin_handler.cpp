
#include "plugin_handler.h"

#include <sstream>
#include <boost/dll/import.hpp> // for import_alias
#include <boost/function.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


namespace giste { namespace core {

	PluginHandler::PluginHandler()
	{
		spdlog::get("giste")->debug("PluginHandler created");
	}
	PluginHandler::~PluginHandler()
	{
		spdlog::get("giste")->debug("PluginHandler destroyed");
		_pipelines.clear();
	}

	void PluginHandler::load(const std::string& directory)
	{
		auto logger = spdlog::get("giste");
		logger->debug("PluginHandler::load(directory='{}')", directory);
		boost::filesystem::path plugins_directory(directory);
		if (!boost::filesystem::is_directory(directory))
		{
			logger->warn("Not a directory or inaccesible ({})", directory);
			throw std::runtime_error("Not a directory");
		}

		// Go ahead for everyfile in dir
		boost::function<pluginapi_create_t> creator;

		for (auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(directory), {}))
		{
			logger->debug("Load plugin at {}", entry);
			creator = boost::dll::import_alias<pluginapi_create_t>(  // type of imported symbol must be explicitly specified
				entry,                                               // path to library
				"instantiate",                                       // symbol to import
				boost::dll::load_mode::append_decorations            // do append extensions and prefixes
				);

			_plugins.push_back(creator);
			std::shared_ptr<Plugin> plugin = creator();
			logger->info("Plugin NONAME {} loaded (giste core {})", plugin->get_plugin_version(), plugin->get_core_version());

			for (auto& item : plugin->get_available())
			{
				logger->debug("Register pipeline '{}'", item);
				auto it = _pipelines.insert(std::make_pair(item, plugin));
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
		spdlog::get("giste")->debug("PluginHandler::build(id='{}')", id);
		auto it = _pipelines.find(id);
		if (it != _pipelines.end())
		{
			return it->second->build(id);
		}
		std::ostringstream os; os << "Pipeline '" << id << "' not available.";
		throw std::runtime_error(os.str());
	}


}}
