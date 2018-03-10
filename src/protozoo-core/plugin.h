
#pragma once

#include <string>
#include <functional>
#include <vector>
#include <memory>

#include <boost/dll/alias.hpp>

#include "core_export.h"
#include "protozoo-core/version.h"


namespace protozoo { namespace core {

	typedef std::function<std::string (const std::string&)> pipeline_t;

	class CORE_EXPORT Plugin {
		public:
			Plugin();
			~Plugin();

			const Version& get_core_version() const;
			const Version& get_plugin_version() const;

			std::vector<std::string> get_available() const;
			pipeline_t build(const std::string& id) const;

		protected:
			friend CORE_EXPORT std::shared_ptr<Plugin> instantiate();

			Version _version;
			std::map<std::string, pipeline_t> _pipelines;
	};

#ifdef PROTOZOO_PLUGIN

	CORE_EXPORT std::shared_ptr<Plugin> instantiate(); // Implementation required for Plugins.

	BOOST_DLL_ALIAS(
		protozoo::core::instantiate, // <-- this function is exported with...
		instantiate                  // <-- ...this alias name
	)
#endif

} }
