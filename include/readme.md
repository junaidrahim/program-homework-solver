# What's in this folder ?

The project directory looks like :

```bash
├── CMakeLists.txt
├── header.png
├── include
│   ├── BasisPolynomial.h
│   ├── CodeGenerator.h
│   ├── LagrangePolynomial.h
│   ├── poly.h
│   └── readme.md
├── src
│   ├── BasisPolynomial.cpp
│   ├── CodeGenerator.cpp
│   ├── LagrangePolynomial.cpp
│   ├── poly.cpp
│   └── test.cpp
└── tests
    ├── CMakeLists.txt
    ├── readme.md
    └── src
        ├── catch.hpp
        └── test_phs.cpp
├── LICENSE
├── main.cpp
├── README.md
├── recording.svg

4 directories, 20 files
```


## poly.h

1. For a data set of say 5 tuples, there will be 5 Basis polynomials, each basis polynomial will be a summation of 4 terms
2.  A basis polynomial looks like => (x-2)/3 * (x-4)/4 * (x-8)/21 * (x-10)/54
3.  "poly" class is used to represent this single polynomial.
4.  A `vector<string>` holds the numerators => `{"x-2","x-4","x-8","x-10"}` and a `vector<int>` holds the denominators => `{3,4,21,54}`

It is just used as a data type, the operations using this type is given in the ```BasisPolynomial.h```


## BasisPolynomial.h

1. what this class does is it takes the x values as input in the constructor and then returns all the basis polynomials in the as a `vector<poly>`
2. It essentially represents this function as a `vector<poly>`
![Basis Polynomial](https://wikimedia.org/api/rest_v1/media/math/render/svg/6e2c3a2ab16a8723c0446de6a30da839198fb04b)


  

## LagrangePolynomial.h

1. The lagrange polynomial is the main function that generates the series
2. It is expressed as sum_of(y[i] * basis_polynomial[i])
3. A single element of the lagrange polynomial looks like => `5 * ((x-2)(x+3)(x-6)/23)`
4. So a struct element is declared that represents the element

`{int multiple; vector<string> polynomials; int denominator}`
5.  And the get_lagrange_polynomials returns a `vector<element>` that represents the summation


## CodeGenerator.h

1.  It takes the `vector<element>` as a constructor input and generates a string compatible with all the programming languages.
2. `vector<element>` looks like 
 ```
 {  
	{4, {"x-3","x-4","x-5"} ,3}
	{13, {"x-4","x-2","x-7"}, 4},
	{3, {"x-6","x-1","x-9"}, 7}
}
```
3.The code generator converts that into something like:

``` ((4*(x-3)*(x-4)*(x-5))/3)+((13*(x-4)*(x-2)*(x-7))/4)+((3*(x-6)*(x-1)*(x-9))/7)```

4.And then use the boilerplate code and that function to generate the source code in
*c*  *cpp*  *python*  *js*  *go*  *java*

The code of these header files is in src/folder