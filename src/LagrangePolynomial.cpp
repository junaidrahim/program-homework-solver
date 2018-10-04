//
// Created by junaidrahim on 9/9/18.
//

#include "../include/LagrangePolynomial.h"

/*
->  The lagrange polynomial is the main function that generates the series
->  It is expressed as sum_of(y[i] * basis_polynomial[i])
->  A single element of the lagrange polynomial looks like => 5 * ((x-2)(x+3)(x-6)/23)
->  So a struct element is declared that represents the element
    => {int multiple; vector<string> polynomials; int denominator}

-> And the get_lagrange_polynomials returns a vector<element> that represents the summation
 */


int64_t LagrangePolynomial::find_product(vector<int> data) {
    // returns product of vector<int> data
    int64_t  result = 1;

    for(int i=0; i<data.size(); i++){
        result = result * data[i];
    }
    return result;
}

vector<LagrangePolynomial::element> LagrangePolynomial::get_lagrange_polynomial(vector<int> data_points, vector<poly> basis_polynomial) {
    vector<element> result_polynomial;

    for(int i=0; i<data_points.size(); i++){
        element temp;
        
        temp.p = basis_polynomial[i].numerators;
        temp.denominator = find_product(basis_polynomial[i].denominators);
        temp.multiple = data_points[i];

        result_polynomial.push_back(temp);
    }

    return result_polynomial;
}