cmake_minimum_required(VERSION 3.20)
project(Lab2_3)

set(CMAKE_CXX_STANDARD 14)

# Включаємо модуль для завантаження контенту (Google Test)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: запобігає помилкам з перевизначенням рантайму
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Список файлів логіки (клас Money)
set(MONEY_SOURCES Money.cpp Money.h)

# --- 1. Основна програма ---
add_executable(Lab2_3 main.cpp ${MONEY_SOURCES})

# --- 2. Юніт-тести ---
add_executable(runUnitTests UnitTest.cpp ${MONEY_SOURCES})

# Лінкуємо gtest_main, щоб не писати main() у файлі UnitTest.cpp
target_link_libraries(runUnitTests gtest_main)

# Дозволяємо CLion бачити тести у вкладці "Test"
include(GoogleTest)
gtest_discover_tests(runUnitTests)