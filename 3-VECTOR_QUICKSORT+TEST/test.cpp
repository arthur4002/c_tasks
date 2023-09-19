#define CATCH_CONFIG_MAIN

#include "vector.h"
#include "catch.hpp"
#include <algorithm>

bool compare_massive_and_vector(Vector& a, u64 * b) {
	size_t size = a.get_size();
	for (u64 i = 0; i < size; i++){
		if (b[i]!=a.get_element(i)){
			return false;
		}
	}
	return true;
}
TEST_CASE("Testing quicksort") {
 	const u64 cases = 10; // Number of tests
 	const u64 elements_count = 10;
 	
	for (u64 i = 0; i < cases; i++) {
		u64 * massive = new u64[elements_count];
 		Vector list(elements_count);

		for (u64 j = 0; j < elements_count; j++) { // Generating data
			u64 temp = std::rand() % 100;
			massive[j]=temp;
			list.push_back(temp);
		}
		list.QuickSort();
		std::sort(massive, massive + elements_count);
	
		REQUIRE(compare_massive_and_vector(list, massive));
		delete [] massive;
	}
    
	
}
