Whats in this folder ?

1. poly.h
2. BasisPolynomial.h
3. LagrangePolynomial.h
4. CodeGenerator.h

1] poly.h
->  for a data set of say 5 tuples, there will be 5 Basis polynomials, each basis polynomial
    will be a summation of 4 terms
->  a basis polynomial looks like => (x-2)/3 + (x-4)/4 + (x-8)/21 + (x-10)/54
->  "poly" class is used to represent this single polynomial.
->  A vector<string> holds the numerators => {"x-2","x-4","x-8","x-10"} and a
    vector<int> holds the denominators => {3,4,21,54}
It is just used as a data type, the operations using this type is given in the BasisPolynomial.h


2] BasisPolynomial.h
->  what this class does is it takes the x values as input in the constructor and then
    returns all the basis polynomials in the as a vector<poly>


3] LagrangePolynomial.h
->  The lagrange polynomial is the main function that generates the series
->  It is expressed as sum_of(y[i] * basis_polynomial[i])
->  A single element of the lagrange polynomial looks like => 5 * ((x-2)(x+3)(x-6)/23)
->  So a struct element is declared that represents the part
    inside the summation => {int multiple; vector<string> polynomials; int denominator}

-> And the get_lagrange_polynomials returns a vector<element> that represents the summation


4] CodeGenerator.h
->  It takes the vector<element> as a constructor input and generates a string compatible
    with all the programming languages.
->  vector<element> looks like { {4, {"x-3","x-4","x-5"} ,3},
                                 {13, {"x-4","x-2","x-7"}, 4},
                                 {3, {"x-6","x-1","x-9"}, 7}
                               }
->  The code generator converts that into something like:
        ((4*(x-3)*(x-4)*(x-5))/3)+((13*(x-4)*(x-2)*(x-7))/4)+((3*(x-6)*(x-1)*(x-9))/7)
->  And then use the boilerplate code and that function to generate the source code in
    c cpp python js go java


The code of these header files is in src/ folder

