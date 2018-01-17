
#pragma once

#include "engine_export.h"
#include "giste-core/config.h"


namespace giste { namespace engine {

	class ENGINE_EXPORT Engine {
		public:
			Engine(const core::Config& cfg);
			~Engine();
	};

} }
