#include <iostream>
#include "Money.h"

#pragma pack(push, 1)
class MoneyPacked {
    long h;
    byte k;
};
#pragma pack(pop)

int main() {
    // Демонстрація конструкторів
    Money m1;                // без аргументів
    Money m2(100, 50);       // ініціалізації
    Money m3 = m2;           // копіювання

    std::cout << "m1: " << m1 << " | m2: " << m2 << " | m3: " << m3 << std::endl;

    // Масив об'єктів
    Money wallet[3] = { Money(10, 99), Money(20, 50), Money() };
    std::cout << "Масив wallet[0]: " << wallet[0] << std::endl;

    // Ввід та операції
    std::cout << "\nВведіть суму (грн коп): ";
    std::cin >> m1;

    std::cout << "Після інкременту (++m1): " << ++m1 << std::endl;

    Money diff = m2 - m1;
    std::cout << "Різниця (m2 - m1): " << diff << std::endl;

    Money mult = m2 * 2.5;
    std::cout << "Множення (m2 * 2.5): " << mult << std::endl;

    // Порівняння
    if (m2 > m1) std::cout << "m2 більше за m1" << std::endl;

    // Перевірка розміру
    std::cout << "\n--- Розмір класу ---" << std::endl;
    std::cout << "Звичайний розмір: " << sizeof(Money) << " bytes" << std::endl;
    std::cout << "Розмір з #pragma pack(1): " << sizeof(MoneyPacked) << " bytes" << std::endl;

    return 0;
}