![HEADER](header.png)

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/923f90f779e14dd7938cbd139d015c0a)](https://app.codacy.com/app/JunaidRahim/program-homework-solver?utm_source=github.com&utm_medium=referral&utm_content=junaidrahim/program-homework-solver&utm_campaign=Badge_Grade_Dashboard)

A simple command line application written in C++ that helps you **generate source code to produce a given
series of integers.** 

You provide a few terms of the series as input and the program will generate for
you, the source code in a few programming languages that prints `n` number of terms
of that particular series.

# Motivation

Ever seen questions of the kind **"Write a program that prints till the nth term of the series 1,3,5,7..."**

Thus thought automating this stuff. 

A program in which you enter any series of integers and hopefully it generates the source code you need to output that series in multiple programming languages.

The mathematical method used is **Lagranges Interpolation Method**.

## Lagranges Interpolation Method

Given a set of k + 1 data points

![data points](https://wikimedia.org/api/rest_v1/media/math/render/svg/5e4f064b4751bb32d87cc829aca1b2b2f38d4a6d)

where no two  ![x_j](https://wikimedia.org/api/rest_v1/media/math/render/svg/5db47cb3d2f9496205a17a6856c91c1d3d363ccd) are the same, the interpolation polynomial in the Lagrange form is a linear combination

![Lagrange polynomial](https://wikimedia.org/api/rest_v1/media/math/render/svg/d07f3378ff7718c345e5d3d4a57d3053190226a0)

of Lagrange basis polynomials
![Basis Polynomial](https://wikimedia.org/api/rest_v1/media/math/render/svg/6e2c3a2ab16a8723c0446de6a30da839198fb04b)

Read more at [Lagrange Interpolation Method (Wikipedia)](https://en.wikipedia.org/wiki/Lagrange_polynomial)

## How to Compile and Run

Requirements : 
    * Cmake
    * make
    * GCC

> You can install these using your preferred package manager in Linux

**How to Compile:**
    * cd into the project directory 
    * run `cmake .`
    * then run `make`

The binary `program-homework-solver` will be compiled in the directory

Use `./program-homework-solver` to run the binary.

Instructions to run the Unit Tests are [here](tests/readme.md)


## DEMO

<p>
    <img src="https://cdn.rawgit.com/junaidrahim/program-homework-solver/51052947/recording.svg">
</p>

<br>

## LICENSE
Copyright (c) **Junaid Rahim**. All rights reserved.

Licensed under the [MIT](LICENSE) License

<br>

[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/for-you.svg)](https://forthebadge.com)
