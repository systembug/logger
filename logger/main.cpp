#include "logger.h"
#include "core/type/Trivial.hpp"

int main() {
	cys::logger::create();


	cys::logger::destroy();

	return 0;
}