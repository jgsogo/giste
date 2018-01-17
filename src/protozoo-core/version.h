
#pragma once

#include <cstdint>
#include <ostream>

#include "core_export.h"
#include "giste-utils/enum_parser.h"
#include "giste-utils/str_conversion.h"


namespace giste
{ 
	namespace core
	{
		struct Version
		{
			enum STAGES : char { ALPHA, BETA, RELEASE_CANDIDATE, RELEASE };
		
			uint32_t major, minor, micro;
			STAGES stage;
			uint32_t stage_version;
		
			bool operator<(const Version& other) const;
			static const Version& current();
		};

		std::ostream& operator<<(std::ostream& os, const Version& other);
	}

	template <> CORE_EXPORT enum_handler<core::Version::STAGES>::enum_handler();
	//template <> CORE_EXPORT std::string to_string<core::Version::STAGES>(const core::Version::STAGES&);
	//template <> CORE_EXPORT core::Version::STAGES from_string<core::Version::STAGES>(const std::string&);

}

