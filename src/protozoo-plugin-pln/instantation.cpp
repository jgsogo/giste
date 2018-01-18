
#include "protozoo-core/plugin.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "tokenize.h"


namespace protozoo { namespace core {

	std::shared_ptr<Plugin> instantiate()
	{
		auto console = spdlog::get("protozoo");
		//! TODO: Get some 'config' for logger. console->set_level(log_level);
		console->debug("Instantation of Plugin '{}'", "protozoo_pln");

		auto plg = std::make_shared<Plugin>();
		plg->_pipelines.insert(std::make_pair("tokenize", pln::tokenize));
		//plg.regi
		return plg;
	}

}}
