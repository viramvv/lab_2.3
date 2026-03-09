#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>

typedef unsigned char byte; // byte як unsigned char для копійок

class Money {
private:
    long hryvnia;
    byte kopeck;

public:
    // Конструктори
    Money();
    Money(long h, byte k);
    Money(const Money& other);

    // Гетери та сетери з перевіркою
    long getHryvnia() const { return hryvnia; }
    byte getKopeck() const { return kopeck; }
    void setHryvnia(long value) { hryvnia = value; }
    void setKopeck(byte value);


    bool Init(long h, byte k);
    void Read();
    void Display() const;
    std::string toString() const;

    // Перевантаження операторів (Методи класу)
    Money& operator=(const Money& other);
    operator std::string() const; // приведення типу до рядка

    // Інкременти/Декременти (додають/віднімають 1 копійку)
    Money& operator++();    // префіксний
    Money operator++(int);  // постфіксний
    Money& operator--();    // префіксний
    Money operator--(int);  // постфіксний

    // Арифметичні операції (згідно таблиці: += як метод)
    Money& operator-=(const Money& other);
    Money& operator*=(double factor);

    // Дружні функції (для бінарних операцій)
    friend Money operator-(const Money& m1, const Money& m2);
    friend Money operator*(const Money& m, double factor);
    
    // Порівняння
    friend bool operator==(const Money& m1, const Money& m2);
    friend bool operator!=(const Money& m1, const Money& m2);
    friend bool operator>(const Money& m1, const Money& m2);
    friend bool operator<(const Money& m1, const Money& m2);

    // Ввід/Вивід
    friend std::ostream& operator<<(std::ostream& out, const Money& m);
    friend std::istream& operator>>(std::istream& in, Money& m);
};

#endif