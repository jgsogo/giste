
#include "giste-core/plugin.h"

namespace giste { namespace core {

	std::shared_ptr<Plugin> instantiate()
	{
		auto plg = std::make_shared<Plugin>();
		return plg;
	}

}}
