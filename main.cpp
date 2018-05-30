#include <iostream>
#include "counter.h"

int main() {
    counter<double> c;
    counter a{5};
    counter b{2};
    c = 5;
    std::cout << c << std::endl;

}