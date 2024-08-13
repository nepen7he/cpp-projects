#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <cstdlib>
#include <iostream>
#include <numeric>

class RationalDivisionByZero : public std::runtime_error {
public:
    RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
    }
};

class Rational {
private:
    int32_t numerator_;
    int32_t denominator_;

public:
    Rational();
    Rational(int32_t numerator);  // NOLINT
    Rational(int32_t numerator, int32_t denominator);

    int32_t GetNumerator() const;
    int32_t GetDenominator() const;
    void SetNumerator(int32_t numerator);
    void SetDenominator(int32_t denominator);

    void Reduce();

    friend std::istream &operator>>(std::istream &is, Rational &rational);
    friend std::ostream &operator<<(std::ostream &out, const Rational rational);
};
bool operator==(const Rational &rt_first_num, const Rational &rt_second_num);
bool operator!=(const Rational &rt_first_num, const Rational &rt_second_num);
bool operator>(const Rational &rt_first_num, const Rational &rt_second_num);
bool operator>=(const Rational &rt_first_num, const Rational &rt_second_num);
bool operator<(const Rational &rt_first_num, const Rational &rt_second_num);
bool operator<=(const Rational &rt_first_num, const Rational &rt_second_num);

Rational operator+(const Rational &rt_first_num);
Rational operator-(const Rational &rt_first_num);
Rational &operator++(Rational &rt_first_num);
Rational &operator--(Rational &rt_first_num);
Rational operator++(Rational &rt_first_num, int);
Rational operator--(Rational &rt_first_num, int);
Rational operator+(const Rational &rt_first_num, const Rational &rt_second_num);
Rational operator-(const Rational &rt_first_num, const Rational &rt_second_num);
Rational operator*(const Rational &rt_first_num, const Rational &rt_second_num);
Rational operator/(const Rational &rt_first_num, const Rational &rt_second_num);
Rational &operator+=(Rational &rt_first_num, const Rational &rt_second_num);
Rational &operator-=(Rational &rt_first_num, const Rational &rt_second_num);
Rational &operator*=(Rational &rt_first_num, const Rational &rt_second_num);
Rational &operator/=(Rational &rt_first_num, const Rational &rt_second_num);

#endif  // RATIONAL_RATIONAL_H
