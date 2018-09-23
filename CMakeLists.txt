cmake_minimum_required(VERSION 3.10)
project(program_homework_solver)

set(CMAKE_CXX_STANDARD 11)

add_executable(
    program_homework_solver
    main.cpp # replace this with src/test.cpp if you want to run that
    include/BasisPolynomial.h
    include/LagrangePolynomial.h
    include/CodeGenerator.h
    include/poly.h
    src/poly.cpp
    src/BasisPolynomial.cpp
    src/LagrangePolynomial.cpp
    src/CodeGenerator.cpp )
