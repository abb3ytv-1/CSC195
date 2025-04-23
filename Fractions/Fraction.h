#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <type_traits>

namespace mathlib {

    template <typename T>
    T findGCD(T a, T b) {
        while (b != 0) {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    template <typename T>
    T absolute(T value) {
        if constexpr (std::is_signed_v<T>) {
            return (value < 0) ? -value : value;
        }
        else {
            return value;
        }
    }

    template <typename T>
    class Fraction {
    private:
        T numerator;
        T denominator;

    public:
        Fraction(T num = 0, T den = 1) : numerator(num), denominator(den) {
            if (den == 0) {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
        }

        // Arithmetic operators
        friend Fraction operator+(const Fraction& a, const Fraction& b) {
            T num = a.numerator * b.denominator + b.numerator * a.denominator;
            T den = a.denominator * b.denominator;
            Fraction result(num, den);
            return result.Simplify();
        }

        friend Fraction operator-(const Fraction& a, const Fraction& b) {
            T num = a.numerator * b.denominator - b.numerator * a.denominator;
            T den = a.denominator * b.denominator;
            Fraction result(num, den);
            return result.Simplify();
        }

        friend Fraction operator*(const Fraction& a, const Fraction& b) {
            T num = a.numerator * b.numerator;
            T den = a.denominator * b.denominator;
            Fraction result(num, den);
            return result.Simplify();
        }

        friend Fraction operator/(const Fraction& a, const Fraction& b) {
            if (b.numerator == 0) {
                throw std::invalid_argument("Division by zero.");
            }
            T num = a.numerator * b.denominator;
            T den = a.denominator * b.numerator;
            Fraction result(num, den);
            return result.Simplify();
        }

        // Comparison operators
        friend bool operator==(const Fraction& lhs, const Fraction& rhs) {
            return lhs.numerator * rhs.denominator == rhs.numerator * lhs.denominator;
        }

        friend bool operator!=(const Fraction& lhs, const Fraction& rhs) {
            return !(lhs == rhs);
        }

        friend bool operator<(const Fraction& lhs, const Fraction& rhs) {
            T left = lhs.numerator * rhs.denominator;
            T right = rhs.numerator * lhs.denominator;
            T denProduct = lhs.denominator * rhs.denominator;

            if (denProduct > 0) {
                return left < right;
            }
            else {
                return left > right;
            }
        }

        friend bool operator>(const Fraction& lhs, const Fraction& rhs) {
            return rhs < lhs;
        }

        friend bool operator<=(const Fraction& lhs, const Fraction& rhs) {
            return !(lhs > rhs);
        }

        friend bool operator>=(const Fraction& lhs, const Fraction& rhs) {
            return !(lhs < rhs);
        }

        // Stream operators
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
            os << f.numerator << '/' << f.denominator;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Fraction& f) {
            T num, den;
            is >> num;

            while (is.peek() != EOF && !isdigit(is.peek()) && is.peek() != '-') {
                is.ignore();
            }

            is >> den;

            if (den == 0) {
                is.setstate(std::ios::failbit);
                return is;
            }

            f = Fraction(num, den);
            return is;
        }

        // Utility methods
        Fraction Simplify() const {
            T num = numerator;
            T den = denominator;

            T gcd = findGCD(absolute(num), absolute(den));

            T simplified_num = num / gcd;
            T simplified_den = den / gcd;

            if (simplified_den < 0) {
                simplified_num = -simplified_num;
                simplified_den = -simplified_den;
            }

            return Fraction(simplified_num, simplified_den);
        }

        float ToFloat() const {
            return static_cast<float>(numerator) / static_cast<float>(denominator);
        }
    };

} 

#endif 