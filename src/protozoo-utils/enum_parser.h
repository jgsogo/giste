
#pragma once

#include <typeinfo>
#include <map>
#include <assert.h>
#include <sstream>
#include "protozoo-utils/str_conversion.h"


namespace protozoo {

	template <typename T>
	class enum_handler
	{
		enum_handler();

		public:
			static const enum_handler<T>& instance()
			{
				static const enum_handler<T> ret;
				return ret;
			}

			void insert(const std::string& id, const T value)
			{
				assert(_reverse.find(value) == _reverse.end()); // Only one preferred per item.
				_values.insert(std::make_pair(id, value));
				_reverse.insert(std::make_pair(value, id));
			};

			void alternate(const T value, const std::string& id)
			{
				assert(_reverse.find(value) != _reverse.end()); // It must be an alternate (a preferred must be given first)
				assert(_values.find(id) == _values.end()); // It cannot be a preferred value
				assert(_alternates.find(id) == _alternates.end()); // Alternate already set!
				_alternates[id] = value;
			};

			T from_string(const std::string& id) const
			{
				auto it = _values.find(id);
				if (it != _values.end())
				{
					return it->second;
				}
				auto it_alternate = _alternates.find(id);
				if (it_alternate != _alternates.end())
				{
					return it_alternate->second;
				}
				std::ostringstream os; os << "Value-string '" << id << "' not found in enum '" << typeid(T).name() << "'.";
				throw std::runtime_error(os.str());
			};

			const std::string& to_string(T id) const
			{
				auto it = _reverse.find(id);
				if (it != _reverse.end())
				{
					return it->second;
				}
				std::ostringstream os; os << "Value-type '" << static_cast<typename std::underlying_type<T>::type>(id) << "' not found in enum '" << typeid(T).name() << "'.";
				throw std::runtime_error(os.str());
			};

		protected:
			std::map<std::string, T> _values; // TODO: boost::bimap? <- do not want to expose a boost dependency
			std::map<T, std::string> _reverse;
			std::map<std::string, T> _alternates; // From other strings to enums.
	};

	//  - specialized for enum types
	template <typename T>
	T from_string(const std::string& value)
	{
		return enum_handler<T>::instance().from_string(value);
	}

	template <typename T>
	std::string to_string(const T& value)
	{
		return enum_handler<T>::instance().to_string(value);
	}

}
