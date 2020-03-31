#pragma once
#include "const.h"
#include <type_traits>

namespace cys {
namespace logger {
	class Core {
	public:
		Core() = default;
		template <class Type, typename std::enable_if_t<std::is_same_v<std::decay_t<Type>,
			cys::logger::LoggerType>>* = nullptr>
		Core(Type&& type) 
		{
		}
		~Core() = default;
		Core(const Core& core) = default;
		Core(Core&& core) noexcept = default;
		Core& operator=(const Core& core) = default;
		Core& operator=(Core&& core) noexcept = default;

	private:


	public:
		bool create();
		template <class Contents, class Severity>
		bool print(Contents&& contents, Severity&& severity) {
			return true;
		}
		bool destroy();
	};
}
}