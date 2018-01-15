
#include "version.h"
#include "giste-version.h"

namespace giste { 

	template <>
	enum_handler<core::Version::STAGES>::enum_handler()
	{
		insert("alpha", core::Version::STAGES::ALPHA);
		insert("beta", core::Version::STAGES::BETA);
		insert("rc", core::Version::STAGES::RELEASE_CANDIDATE);
		insert("", core::Version::STAGES::RELEASE);
	}

	namespace core
	{
		namespace _detail
		{
			Version get_current()
			{
				Version ret;
				ret.major = VERSION_MAJOR;
				ret.minor = VERSION_MINOR;
				ret.micro = VERSION_MICRO;
				ret.stage = from_string<Version::STAGES>(VERSION_STAGE);
				ret.stage_version = VERSION_STAGE_NUM;
				return ret;
			}
		}

		bool Version::operator<(const Version& other) const
		{
			return std::make_tuple(major, minor, micro, stage, stage_version)
				 < std::make_tuple(other.major, other.minor, other.micro, other.stage, other.stage_version);
		}

		const Version& Version::current()
		{
			static Version ret = _detail::get_current();
			return ret;
		}

		std::ostream& operator<<(std::ostream& os, const Version& other)
		{
			os << "v" << other.major << "." << other.minor << "." << other.micro;
			switch (other.stage)
			{
				case Version::STAGES::ALPHA:
					os << "-alpha." << other.stage_version;
					break;
				case Version::STAGES::BETA:
					os << "-beta." << other.stage_version;
					break;
				case Version::STAGES::RELEASE_CANDIDATE:
					os << "-rc." << other.stage_version;
					break;
				case Version::STAGES::RELEASE:
					os << "";
					break;
				default:
					throw std::invalid_argument("Version::STAGES value not recognized.");
			}
			return os;
		}

	}
}

