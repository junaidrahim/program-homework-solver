cmake_minimum_required(VERSION 3.10)
project(phs_tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    phs_tests 
    src/catch.hpp
    ../include/poly.h
    ../include/BasisPolynomial.h
    ../include/CodeGenerator.h
    ../include/LagrangePolynomial.h

    ../src/poly.cpp
    ../src/BasisPolynomial.cpp
    ../src/LagrangePolynomial.cpp
    ../src/CodeGenerator.cpp

    src/test_phs.cpp
    )
