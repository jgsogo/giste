
#pragma once

#include "engine_export.h"
#include "protozoo-core/config.h"


namespace protozoo { namespace engine {

	class ENGINE_EXPORT Engine {
		public:
			Engine(const core::Config& cfg);
			~Engine();
	};

} }
