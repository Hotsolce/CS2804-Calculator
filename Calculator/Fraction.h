#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>
#include <cmath>
#include <utility>
#include <sstream>

class Fraction
{
    public:
        Fraction(int numerator, int denominator);
        int Getnumerator() { return m_numerator; }
        void Setnumerator(int val) { m_numerator = val; }
        int Getdenominator() { return m_denominator; }
        void Setdenominator(int val) { m_denominator = val; }

        Fraction operator+(const int other);
        Fraction operator+(const Fraction& other);

        Fraction operator-(const int other);
        Fraction operator-(const Fraction& other);

        Fraction operator*(const int other);
        Fraction operator*(const Fraction& other);

        Fraction operator/(const int other);
        Fraction operator/(const Fraction& other);

        Fraction& operator++();
        Fraction operator++(int);

        Fraction& operator--();
        Fraction operator--(int);

        void operator<<(const Fraction& fraction);

        bool operator==(const Fraction& fraction);
        bool operator!=(const Fraction& fraction);
        bool operator<(const Fraction& fraction);

        operator double();
        operator int();



    protected:
    private:
        int m_numerator;
        int m_denominator;
        void reduce(Fraction& fraction);
        int LCM(int x, int y);
        int GCD(int x, int y);
        Fraction reciprocal(const Fraction& fraction);
};

#endif // FRACTION_H
