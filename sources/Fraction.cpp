
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

#include "Fraction.hpp"
using namespace ariel;


// Constructors
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
}

Fraction::Fraction(double value) {
    numerator = int(value * 1000 + 0.5);
    denominator = 1000;
}

// Arithmetic operators
Fraction Fraction::operator+(const Fraction &other) const {
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
    return *this;
}

Fraction Fraction::operator*(const Fraction &other) const {
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
    return *this;
}

// Comparison operators
bool Fraction::operator==(const Fraction &other) const {
    return (*this <= other) && (*this >= other);
}

bool Fraction::operator!=(const Fraction &other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction &other) const {
    return other < *this;
}

bool Fraction::operator<=(const Fraction &other) const {
    return !(other < *this);
}

bool Fraction::operator>=(const Fraction &other) const {
    return !(*this < other);
}

Fraction& Fraction::operator++() {
    numerator += denominator;  // Adds 1 to the fraction (numerator += denominator)
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;  // Subtracts 1 from the fraction (numerator -= denominator)
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    --(*this);
    return temp;
}

// Stream operators
ostream& ariel::operator<<(ostream &out, const Fraction &fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

istream& ariel::operator>>(istream &in, Fraction &fraction) {
    int num, denom;
    char delimiter;
    in >> num >> delimiter;
    if (delimiter == '/') {
        in >> denom;
    } else {
        in.putback(delimiter);
        in >> denom;
    }
    fraction = Fraction(num, denom);
    return in;
}

// Operator overloads for double and Fraction
Fraction operator+(const Fraction &fraction, double floatingPoint) {
    Fraction temp(floatingPoint);
    return fraction + temp;
}

Fraction operator+(double floatingPoint, const Fraction &fraction) {
    return fraction + floatingPoint;
}

Fraction operator-(const Fraction &fraction, double floatingPoint) {
    Fraction temp(floatingPoint);
    return fraction - temp;
}

Fraction operator-(double floatingPoint, const Fraction &fraction) {
    Fraction temp(floatingPoint);
    return temp - fraction;
}

Fraction operator*(const Fraction &fraction, double floatingPoint) {
    Fraction temp(floatingPoint);
    return fraction * temp;
}

Fraction operator*(double floatingPoint, const Fraction &fraction) {
    return fraction * floatingPoint;
}

Fraction operator/(const Fraction &fraction, double floatingPoint) {
    if (floatingPoint == 0.0) {
        throw invalid_argument("Division by zero");
    }
    Fraction temp(floatingPoint);
    return fraction / temp;
}

Fraction operator/(double floatingPoint, const Fraction &fraction) {
    if (fraction.getNumerator() == 0) {
        throw invalid_argument("Division by zero");
    }
    Fraction temp(floatingPoint);
    return temp / fraction;
}