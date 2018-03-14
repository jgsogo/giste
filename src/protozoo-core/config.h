
#pragma once

#include <istream>
#include <memory>
#include <filesystem>
#include "core_export.h"


namespace protozoo { namespace core {

	class CORE_EXPORT Config
	{
		protected:
			explicit Config(std::istream& is);
			~Config();

		public:
			static Config& parse(std::istream& is);
			std::vector<std::filesystem::path> plugins_path() const;

		protected:
		    struct Impl;
		    std::unique_ptr<Impl> pImpl;
	};

}}
