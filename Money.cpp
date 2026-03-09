#include "Money.h"
#include <sstream>
#include <cmath>

Money::Money() : hryvnia(0), kopeck(0) {}

Money::Money(long h, byte k) {
    if (!Init(h, k)) {
        hryvnia = 0;
        kopeck = 0;
    }
}

Money::Money(const Money& other) : hryvnia(other.hryvnia), kopeck(other.kopeck) {}

void Money::setKopeck(byte value) {
    if (value < 100) kopeck = value;
    else kopeck = 0;
}

bool Money::Init(long h, byte k) {
    if (h >= 0 && k < 100) {
        hryvnia = h;
        kopeck = k;
        return true;
    }
    return false;
}

std::string Money::toString() const {
    std::stringstream ss;
    ss << hryvnia << "," << (kopeck < 10 ? "0" : "") << (int)kopeck;
    return ss.str();
}

Money::operator std::string() const {
    return this->toString();
}

void Money::Read() {
    long h;
    int k;
    std::cout << "Введіть гривні: "; std::cin >> h;
    std::cout << "Введіть копійки: "; std::cin >> k;
    if (!Init(h, (byte)k)) {
        std::cout << "Помилка! Дані встановлено в 0." << std::endl;
    }
}

void Money::Display() const {
    std::cout << toString() << " UAH" << std::endl;
}

// Оператори інкременту/декременту
Money& Money::operator++() {
    if (++kopeck >= 100) { kopeck = 0; hryvnia++; }
    return *this;
}

Money Money::operator++(int) {
    Money temp(*this);
    ++(*this);
    return temp;
}

Money& Money::operator--() {
    if (kopeck == 0) {
        if (hryvnia > 0) { kopeck = 99; hryvnia--; }
    } else {
        kopeck--;
    }
    return *this;
}

Money Money::operator--(int) {
    Money temp(*this);
    --(*this);
    return temp;
}

// Арифметика
Money& Money::operator-=(const Money& other) {
    long total1 = hryvnia * 100 + kopeck;
    long total2 = other.hryvnia * 100 + other.kopeck;
    long res = (total1 > total2) ? total1 - total2 : 0;
    hryvnia = res / 100;
    kopeck = res % 100;
    return *this;
}

Money operator-(const Money& m1, const Money& m2) {
    Money res = m1;
    res -= m2;
    return res;
}

Money& Money::operator*=(double factor) {
    long total = (long)(round((hryvnia * 100 + kopeck) * factor));
    hryvnia = total / 100;
    kopeck = total % 100;
    return *this;
}

Money operator*(const Money& m, double factor) {
    Money res = m;
    res *= factor;
    return res;
}

// Порівняння
bool operator<(const Money& m1, const Money& m2) {
    return (m1.hryvnia < m2.hryvnia) || (m1.hryvnia == m2.hryvnia && m1.kopeck < m2.kopeck);
}
bool operator==(const Money& m1, const Money& m2) { return m1.hryvnia == m2.hryvnia && m1.kopeck == m2.kopeck; }
bool operator!=(const Money& m1, const Money& m2) { return !(m1 == m2); }
bool operator>(const Money& m1, const Money& m2) { return m2 < m1; }

// Ввід/Вивід
std::ostream& operator<<(std::ostream& out, const Money& m) {
    out << m.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Money& m) {
    long h; int k;
    in >> h >> k;
    if (!m.Init(h, (byte)k)) m.Init(0, 0);
    return in;
}

Money& Money::operator=(const Money& other) {
    hryvnia = other.hryvnia;
    kopeck = other.kopeck;
    return *this;
}