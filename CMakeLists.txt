cmake_minimum_required(VERSION 3.6)
project(BalancesSerial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.cpp matrix_inverse.cpp BalanceCalculator.cpp BalanceCalculator.h BalanceCalculatorParallel.cpp BalanceCalculatorParallel.h)
add_executable(BalancesSerial ${SOURCE_FILES})