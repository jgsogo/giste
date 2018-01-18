
#pragma once

#include "core_export.h"
#include "protozoo-core/plugin.h"


namespace protozoo { namespace core {

	class CORE_EXPORT PluginHandler
	{
		public:
			PluginHandler();
			~PluginHandler();

			void load(const std::string& directory);
			pipeline_t build(const std::string& id) const;

		protected:
			struct Impl;
			std::unique_ptr<Impl> _impl;

		private:
			typedef std::shared_ptr<Plugin>(pluginapi_create_t)();
			std::vector<std::function<pluginapi_create_t>> _plugins;
	};

}}
