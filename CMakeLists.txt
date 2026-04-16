cmake_minimum_required(VERSION 3.10)
project(MoneyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)

# Налаштування тестів
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/heads/main.zip)
FetchContent_MakeAvailable(googletest)

# Ціль 1: ТЕСТИ
add_executable(UnitTest UnitTest.cpp Money.cpp MoneyPublic.cpp)
target_link_libraries(UnitTest gtest_main)

# Ціль 2: ПРОГРАМА (додайте це!)
add_executable(LabRun main.cpp Money.cpp MoneyPublic.cpp)