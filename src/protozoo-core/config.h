
#pragma once

#include <istream>
#include "core_export.h"


namespace protozoo { namespace core {

	class CORE_EXPORT Config
	{
		protected:
			Config();
			~Config();

		public:
			static Config& parse(std::istream& is);
	};

}}