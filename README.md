# Program Homework Solver

Ever seen questions of the kind __"Write a program that prints the series 1,3,5,7..."__

Thus thought of writing a program that automates this stuff. 
A program in which you enter a series of integers and it generates the source code you need to output that series
in multiple programming languages

The mathematical method used was Lagranges Interpolation Method.


## Lagranges Interpolation Method

Given a set of k + 1 data points


![data points](https://wikimedia.org/api/rest_v1/media/math/render/svg/5e4f064b4751bb32d87cc829aca1b2b2f38d4a6d)

where no two  ![x_j](https://wikimedia.org/api/rest_v1/media/math/render/svg/5db47cb3d2f9496205a17a6856c91c1d3d363ccd) are the same, the interpolation polynomial in the Lagrange form is a linear combination

![Lagrange polynomial](https://wikimedia.org/api/rest_v1/media/math/render/svg/d07f3378ff7718c345e5d3d4a57d3053190226a0)

of Lagrange basis polynomials
![Basis Polynomial](https://wikimedia.org/api/rest_v1/media/math/render/svg/6e2c3a2ab16a8723c0446de6a30da839198fb04b)

Read more at [Lagrange Interpolation Method (Wikipedia)](https://en.wikipedia.org/wiki/Lagrange_polynomial)

## How to compile and run

Requirements :
* Cmake
* make
* GCC

How to Compile:
* cd into the project directory 
* run `cmake .`
* then run `make`

The binary `program-homework-solver` will be compiled in the directory

Use `./program-homework-solver` to run the binary.

## DEMO

<p>
    <img src="https://cdn.rawgit.com/junaidrahim/program-homework-solver/51052947/recording.svg">
</p>

