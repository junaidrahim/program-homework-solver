cmake_minimum_required(VERSION 3.10)
project(program_homework_solver)

set(CMAKE_CXX_STANDARD 11)

add_executable(program_homework_solver main.cpp BasisPolynomial.cpp include/BasisPolynomial.h poly.cpp include/poly.h LagrangePolynomial.cpp include/LagrangePolynomial.h)