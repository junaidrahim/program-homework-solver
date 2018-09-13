//
// Created by junaidrahim on 9/9/18.
//

#include "../include/LagrangePolynomial.h"

int64_t LagrangePolynomial::find_product(vector<int> data) {
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