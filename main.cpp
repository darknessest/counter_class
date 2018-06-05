#include <iostream>
#include "counter.h"

int main() {
    counter<double> a;
    counter<double> b;
    while (std::cin >> a >> b)
        std::cout << "a+b = " << a + b << "\t b+a = " << b + a << std::endl
                  << "a-b = " << a - b << "\t b-a = " << b - a << std::endl
                  << "a*b = " << a*b << "\t b-a = " << b*a << std::endl
                  << "\n(deg)" << std::endl
                  << "sin(a) = " << a.sin() << "\t sin(b) = " << b.sin() << std::endl
                  << "cos(a) = " << a.cos() << "\t cos(b) = " << b.cos() << std::endl
                  << "tan(a) = " << a.tan() << "\t tan(b) = " << b.tan() << std::endl
                  << std::endl;
}