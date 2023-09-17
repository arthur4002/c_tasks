#include <iostream>
#include "vector.h"

int main() {
    Vector a(5);
    for (int i = 0; i<20; i+=2) {
        a.push_back(std::rand() % 100);
    }
    a.PrintVector();
    a.pop_back();
    a.pop_back();
    a.PrintVector();

    a.QuickSort();
    std::cout << "After sort" << std::endl;
    a.PrintVector();


    return 0;
}