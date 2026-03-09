#include <gtest/gtest.h>
#include "Money.h"

// Перевірка конструкторів
TEST(MoneyTest, Initialization) {
    Money m(50, 75);
    EXPECT_EQ(m.getHryvnia(), 50);
    EXPECT_EQ(m.getKopeck(), 75);
}

// Перевірка інкременту (префіксного)
TEST(MoneyTest, PrefixIncrement) {
    Money m(10, 99);
    ++m;
    EXPECT_EQ(m.getHryvnia(), 11);
    EXPECT_EQ(m.getKopeck(), 0);
}

// Перевірка віднімання (бінарний оператор)
TEST(MoneyTest, SubtractionOperator) {
    Money m1(10, 50);
    Money m2(5, 60);
    Money res = m1 - m2;
    EXPECT_EQ(res.getHryvnia(), 4);
    EXPECT_EQ(res.getKopeck(), 90);
}

// Перевірка порівняння
TEST(MoneyTest, Comparison) {
    Money m1(10, 50);
    Money m2(10, 50);
    Money m3(11, 0);
    EXPECT_TRUE(m1 == m2);
    EXPECT_TRUE(m3 > m1);
}

// Перевірка toString
TEST(MoneyTest, ToStringFormat) {
    Money m(5, 7);
    EXPECT_EQ(m.toString(), "5,07");
}