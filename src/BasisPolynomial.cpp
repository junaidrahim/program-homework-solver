//
// Created by junaidrahim on 9/9/18.
//

#include "../include/BasisPolynomial.h"
#include "../include/poly.h"
#include "../include/BasisPolynomial.h"

BasisPolynomial::BasisPolynomial(vector<int> data) {
    data_points = data;
}

vector<poly> BasisPolynomial::get_all_basis_polynomials() {

    vector<poly> b_polynomials;

    for(int j=0; j<data_points.size(); j++){
        poly p;

        for(int m=0; m<data_points.size(); m++){
            if(m==j){ continue; }
            else {
                string num = "x" + to_string(-data_points[m]);
                int den = data_points[j] - data_points[m];

                p.add_to_numerator(num);
                p.add_to_denominator(den);
            }
        }

        b_polynomials.push_back(p);
    }

    return b_polynomials;
}
