
#include "giste-core/plugin.h"

#include "tokenize.h"


namespace giste { namespace core {

	std::shared_ptr<Plugin> instantiate()
	{
		auto plg = std::make_shared<Plugin>();
		plg->_pipelines.insert(std::make_pair("tokenize", pln::tokenize));
		//plg.regi
		return plg;
	}

}}
