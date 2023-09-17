#define CATCH_MAIN_CONFIG

#include "vector.h"
#include "catch.hpp"

uint32_t multiplication (uint32_t a, uint32_t b) {
    return a*b;
}

TEST_CASE("01") {
 	REQUIRE(multiplication(2,3) == 6);
	REQUIRE(multiplication(100,5) == 500);
	size_t a = 3, b = 4;
        size_t c = a*b;
	REQUIRE(multiplication(a,b) == c);
}

TEST_CASE("02") {
	REQUIRE(multiplication(11,11) == 111);
	REQUIRE(true);
}