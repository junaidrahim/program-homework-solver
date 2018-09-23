cmake_minimum_required(VERSION 3.10)
project(program_homework_solver)

set(CMAKE_CXX_STANDARD 11)

add_executable(

program_homework_solver
main.cpp
src/BasisPolynomial.cpp
include/BasisPolynomial.h
src/poly.cpp include/poly.h
src/LagrangePolynomial.cpp
include/LagrangePolynomial.h
src/CodeGenerator.cpp
include/CodeGenerator.h )