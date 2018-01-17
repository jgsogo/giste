
#pragma once

#include "core_export.h"
#include "giste-core/plugin.h"


namespace giste { namespace core {

	class CORE_EXPORT PluginHandler
	{
		public:
			PluginHandler();
			~PluginHandler();

			void load(const std::string& directory);
			pipeline_t build(const std::string& id) const;

		protected:
			std::map<std::string, std::shared_ptr<Plugin>> _pipelines;

		private:
			typedef std::shared_ptr<Plugin>(pluginapi_create_t)();
			std::vector<std::function<pluginapi_create_t>> _plugins;
	};

}}
