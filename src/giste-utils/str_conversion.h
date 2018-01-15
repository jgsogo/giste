
#pragma once

#include <string>
#include "utils_export.h"


namespace giste {

	// Translations from/to strings.
	template <typename T>
	std::string to_string(const T&); // Nothing by default

	template <typename T>
	T from_string(const std::string&); // Nothing by default

	//  - specialized for std::string
	template <> UTILS_EXPORT std::string from_string<std::string>(const std::string& value);
	template <> UTILS_EXPORT std::string to_string<std::string>(const std::string& value);
}
