#pragma once
#include <boost/log/trivial.hpp>

namespace cys {
namespace logger {
namespace type {
	class Trivial {
	public:
		Trivial() = default;
		~Trivial() = default;
		Trivial(const Trivial& tv) = default;
		Trivial(Trivial&& tv) noexcept = default;
		Trivial& operator=(const Trivial& tv) = default;
		Trivial& operator=(Trivial&& tv) noexcept = default;

	public:
		template <class Contents, class Severity>
		void print(Contents&& contents) {
			BOOST_LOG_TRIVIAL(trace) << contents;
		}
	};
}
}
}