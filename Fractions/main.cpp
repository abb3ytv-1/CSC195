#include "Fraction.h"
#include <iostream>

int main() {
    mathlib::Fraction<int> f1{ 18, 5 };
    std::cout << f1 << std::endl;

    mathlib::Fraction<int> f2{ 15, 6 };
    std::cout << f2 << std::endl;
    std::cout << "simplify: " << f2.Simplify() << std::endl;

    std::cout << f1 << " == " << f1 << " result: " << (f1 == f2) << std::endl;
    std::cout << f1 << " > " << f2 << " result: " << (f1 > f2) << std::endl;

    std::cout << f1 << " + " << f2 << " result: " << (f1 + f2) << std::endl;
    std::cout << f1 << " * " << f2 << " result: " << (f1 * f2) << std::endl;

    mathlib::Fraction<int> f3;
    std::cout << "input fraction (numerator - denominator): \n";
    std::cin >> f3;
    std::cout << f3 << std::endl;
    std::cout << f3.ToFloat() << std::endl;

    return 0;
}