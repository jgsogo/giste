
#include "str_conversion.h"

namespace giste {

	//  - specialized for std::string
	template <> std::string from_string<std::string>(const std::string& value) { return value; }
	template <> std::string to_string<std::string>(const std::string& value) { return value; }

}
