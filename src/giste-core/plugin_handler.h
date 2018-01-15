
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
			std::vector<std::shared_ptr<Plugin>> _plugins;
			std::map<std::string, const Plugin&> _pipelines;
	};

}}
