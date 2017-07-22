cmake_minimum_required(VERSION 3.7)
project(BigInteger)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BasicArithmatic.cpp BasicMultiplication.cpp)
add_executable(BigInteger ${SOURCE_FILES})