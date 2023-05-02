#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>
using namespace std;
using namespace ariel;

TEST_CASE("Fraction operator tests") {

    Fraction a(1, 2);
    Fraction b(3, 4);
    Fraction c(0,1);

    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(1,1);
    Fraction f4(3, 1);

    SUBCASE("Construction and simplification") {
        CHECK_NOTHROW(Fraction(6, 8));
        CHECK_THROWS(Fraction(1, 0));
        CHECK(Fraction(6, 8) == Fraction(3, 4));
    }


    SUBCASE("Addition") {

        c = a + b;
        CHECK(c == Fraction(5, 4));

        f3 = f1 + f2;
        CHECK(f3 == Fraction(5, 4));

        f3 = f1 + f4;
        CHECK(f3 == Fraction(7, 2));

        f3 = f2 + f4;
        CHECK(f3 == Fraction(15, 4));
    }

    SUBCASE("Subtraction") {

        c = a - b;
        CHECK(c == Fraction(-1, 4));

        f3 = f1 - f2;
        CHECK(f3 == Fraction(-1, 4));

        f3 = f1 - f4;
        CHECK(f3 == Fraction(-5, 2));

        f3 = f2 - f4;
        CHECK(f3 == Fraction(-9, 4));

    }

    SUBCASE("Multiplication") {

        c = a * b;
        CHECK(c == Fraction(3, 8));

        f3 = f1 * f2;
        CHECK(f3 == Fraction(3, 8));

        f3 = f1 * f4;
        CHECK(f3 == Fraction(3, 2));

        f3 = f2 * f4;
        CHECK(f3 == Fraction(9, 4));
    }


    SUBCASE("Division") {
        c = a / b;
        CHECK(c == Fraction(2, 3));

        f3 = f1 / f2;
        CHECK(f3 == Fraction(2, 3));

        f3 = f1 / f4;
        CHECK(f3 == Fraction(1, 6));

        f3 = f2 / f4;
        CHECK(f3 == Fraction(1, 4));

        CHECK_THROWS(f1 / Fraction(0, 1));
    }

    SUBCASE("Equality") {

        CHECK(a != b);
        CHECK(a == Fraction(1, 2));

        CHECK(f1 != f2);
        CHECK(f1 == Fraction(1, 2));

        CHECK(f2 != f4);
        CHECK(f4 == Fraction(3, 1));

    }

    SUBCASE("Comparison") {

        CHECK(a < b);
        CHECK(b > a);
        CHECK(a <= b);
        CHECK(b >= a);

        CHECK(f1 < f2);
        CHECK(f2 > f1);
        CHECK(f1 <= f2);
        CHECK(f2 >= f1);

        CHECK(f1 < f4);
        CHECK(f4 > f1);
        CHECK(f1 <= f4);
        CHECK(f4 >= f1);
    }

    SUBCASE("Increment and Decrement") {

        ++a;
        CHECK(a == Fraction(3, 2));
        --a;
        CHECK(a == Fraction(1, 2));

        ++f1;
        CHECK(f1 == Fraction(3, 2));
        --f1;
        CHECK(f1 == Fraction(1, 2));

        ++f2;
        CHECK(f2 == Fraction(7, 4));
        --f2;
        CHECK(f2 == Fraction(3, 4));

    }

    SUBCASE("I/O Operators") {

        stringstream ss;
        ss << a;
        CHECK(ss.str() == "1/2");
        ss.clear();
        ss.str("3 5");
        ss >> c;
        CHECK(c == Fraction(3, 5));
        ss.clear();

        Fraction f_in(2, 5);

        ss << f_in;
        CHECK(ss.str() == "2/5");
        Fraction f_out(1,1);
        ss >> f_out;
        CHECK(f_out == Fraction(2, 5));

    }

    SUBCASE("Fraction-float mixed operations") {
        float a = 0.5;

        c = a + a;
        CHECK(c == Fraction(1, 1));

        c = a - a;
        CHECK(c == Fraction(0, 1));

        c = a * a;
        CHECK(c == Fraction(1, 4));

        c = a / a;
        CHECK(c == Fraction(1, 1));

        f3 = f1 + 0.5;
        CHECK(f3 == Fraction(1, 1));

        f3 = f2 + 0.25;
        CHECK(f3 == Fraction(1, 1));

        f3 = f1 - 0.5;
        CHECK(f3 == Fraction(0, 1));

        f3 = f2 - 0.25;
        CHECK(f3 == Fraction(1, 2));

        f3 = f1 * 2.0;
        CHECK(f3 == Fraction(1, 1));

        f3 = f2 * 0.5;
        CHECK(f3 == Fraction(3, 8));

        f3 = f1 / 0.5;
        CHECK(f3 == Fraction(1, 1));

        f3 = f2 / 2.0;
        CHECK(f3 == Fraction(3, 8));

        CHECK_THROWS(f1 / 0.0);
    }

}

TEST_CASE("Fraction edge cases") {

    Fraction a(0, 1);
    Fraction b(1, 1);

    SUBCASE("Zero numerator") {
        CHECK(a == Fraction(0, 3));
        CHECK(a + b == Fraction(1, 1));
        CHECK(a - b == Fraction(-1, 1));
        CHECK(a * b == Fraction(0, 1));
        CHECK_THROWS(a / Fraction(0, 1));
        CHECK_THROWS(a / 0.0);
    }

    SUBCASE("One numerator and denominator") {
        CHECK(b == Fraction(2, 2));
        CHECK(b + a == Fraction(1, 1));
        CHECK(b - a == Fraction(1, 1));
        CHECK(b * a == Fraction(0, 1));
    }

}
