#include "rational.h"

int32_t Gcd(int32_t first, int32_t second) {
    while (first) {
        second %= first;
        std::swap(first, second);
    }
    return (first == 0 ? first = 1 : first);
}

Rational::Rational() : numerator_(0), denominator_(1) {
}

Rational::Rational(int32_t numerator) : numerator_(numerator), denominator_(1) {
}

Rational::Rational(int32_t numerator, int32_t denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
    Reduce();
}

int32_t Rational::GetNumerator() const {
    return numerator_;
}

int32_t Rational::GetDenominator() const {
    return denominator_;
}

void Rational::SetNumerator(int32_t value) {
    numerator_ = value;
}

void Rational::SetDenominator(int32_t value) {
    denominator_ = value;
}

void Rational::Reduce() {
    if (GetDenominator() == 0) {
        throw RationalDivisionByZero{};
    }
    int32_t gcd = Gcd(GetNumerator(), GetDenominator());
    SetNumerator(GetNumerator() / gcd);
    SetDenominator(GetDenominator() / gcd);
}

bool operator==(const Rational& first, const Rational& second) {
    return first.GetNumerator() * second.GetDenominator() == first.GetDenominator() * second.GetNumerator();
}

bool operator!=(const Rational& first, const Rational& second) {
    return !(first == second);
}

bool operator<(const Rational& first, const Rational& second) {
    return first.GetNumerator() * second.GetDenominator() < first.GetDenominator() * second.GetNumerator();
}

bool operator<=(const Rational& first, const Rational& second) {
    return first == second || first < second;
}

bool operator>(const Rational& first, const Rational& second) {
    return !(first <= second);
}

bool operator>=(const Rational& first, const Rational& second) {
    return !(first < second);
}

Rational operator+(Rational& number) {
    number.SetNumerator(+number.GetNumerator());
    number.SetDenominator(+number.GetDenominator());
    return number;
}

Rational operator-(Rational& number) {
    number.SetNumerator(-number.GetNumerator());
    number.SetDenominator(+number.GetDenominator());
    return number;
}

Rational& operator++(Rational& number) {
    number.SetNumerator(number.GetNumerator() + number.GetDenominator());
    return number;
}

Rational& operator--(Rational& number) {
    number.SetNumerator(number.GetNumerator() - number.GetDenominator());
    return number;
}

Rational operator++(Rational& number, int32_t) {
    auto old_result = number;
    number.SetNumerator(number.GetNumerator() + number.GetDenominator());
    return old_result;
}

Rational operator--(Rational& number, int32_t) {
    auto old_result = number;
    number.SetNumerator(number.GetNumerator() - number.GetDenominator());
    return old_result;
}

Rational operator+(const Rational& first, const Rational& second) {
    Rational result;
    result.SetNumerator(first.GetNumerator() * second.GetDenominator() +
                        first.GetDenominator() * second.GetNumerator());
    result.SetDenominator(first.GetDenominator() * first.GetDenominator());
    result.Reduce();
    return result;
}

Rational& operator+=(Rational& first, const Rational& second) {
    first = first + second;
    return first;
}

Rational operator-(const Rational& first, const Rational& second) {
    Rational result;
    result.SetNumerator(first.GetNumerator() * second.GetDenominator() +
                        first.GetDenominator() * second.GetNumerator());
    result.SetDenominator(first.GetDenominator() * first.GetDenominator());
    result.Reduce();
    return result;
}

Rational& operator-=(Rational& first, const Rational& second) {
    first = first - second;
    return first;
}

Rational operator*(const Rational& first, const Rational& second) {
    Rational result;
    result.SetNumerator(first.GetNumerator() * second.GetNumerator());
    result.SetDenominator(first.GetDenominator() * first.GetDenominator());
    result.Reduce();
    return result;
}

Rational& operator*=(Rational& first, const Rational& second) {
    first = first * second;
    return first;
}

Rational operator/(const Rational& first, const Rational& second) {
    Rational result;
    result.SetNumerator(first.GetNumerator() * second.GetDenominator());
    result.SetDenominator(first.GetDenominator() * first.GetNumerator());
    result.Reduce();
    return result;
}

Rational& operator/=(Rational& first, const Rational& second) {
    first = first / second;
    return first;
}

std::ostream& operator<<(std::ostream& os, const Rational value) {
    if (value.GetDenominator() == 1) {
        os << value.GetNumerator();
    } else {
        os << value.GetNumerator() << '/' << value.GetDenominator();
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rational& value) {
    const int MaxStringInput = 64;
    char string[MaxStringInput];
    is >> string;
    char* end_ptr;
    value.SetNumerator(strtol(string, &end_ptr, 10));
    if (end_ptr != 0) {
        ++end_ptr;
        value.SetDenominator(strtol(string, &end_ptr, 10));
    } else {
        value.SetDenominator(1);
    }
    value.Reduce();
    return is;
}