#pragma once
#include <iostream>

namespace ariel {
    class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        // Constructors
        Fraction(int num, int denom);  
        Fraction(double value);  // Constructor with double value
        
        // Getter methods
        int getNumerator() const {return numerator;}
        int getDenominator() const{return denominator;}

        // Overloaded arithmetic operators
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;

        // Overloaded comparison operators
        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;

        // Overloaded increment and decrement operators
        /* '&' is used to return a reference*/
        // Pre-increment (prefix)
        Fraction& operator++();  
        Fraction& operator--(); 
        // Post-increment (postfix)
        Fraction operator++(int);  
        Fraction operator--(int);  

        // Friend stream operators
        /* The 'friend' keyword is used because these operators need access to private member variables */
        friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
        friend std::istream& operator>>(std::istream &in, Fraction &fraction);

    };
}

// Operator overloads for double and Fraction
ariel::Fraction operator+(const ariel::Fraction &fraction, double floatingPoint);
ariel::Fraction operator+(double floatingPoint, const ariel::Fraction &fraction);
ariel::Fraction operator-(const ariel::Fraction &fraction, double floatingPoint);
ariel::Fraction operator-(double floatingPoint, const ariel::Fraction &fraction);
ariel::Fraction operator*(const ariel::Fraction &fraction, double floatingPoint);
ariel::Fraction operator*(double floatingPoint, const ariel::Fraction &fraction);
ariel::Fraction operator/(const ariel::Fraction &fraction, double floatingPoint);
ariel::Fraction operator/(double floatingPoint, const ariel::Fraction &fraction);
