//
// Created by junaidrahim on 9/9/18.
//

#include "../include/BasisPolynomial.h"

/*
what this class does is it takes the x values as input in the constructor and then returns all the basis polynomials in the as a `vector<poly>`
Read more about it in /include/readme.md file
*/

BasisPolynomial::BasisPolynomial(vector<int> data) { // constructor
    BasisPolynomial::data_points = data;
}

vector<poly> BasisPolynomial::get_all_basis_polynomials() {
    vector<poly> b_polynomials;

    int data_points_size = BasisPolynomial::data_points.size();

    for(int j=0; j<data_points_size; j++){
        poly p;

        for(int m=0; m<data_points_size; m++){
            if(m==j){ continue; } // according to definition
            else {
                string num = "x" + to_string(-data_points[m]); // eg => "x-4"
                int den = data_points[j] - data_points[m]; // denominator

                p.add_to_numerator(num); // appending
                p.add_to_denominator(den);
            }
        }
        b_polynomials.push_back(p);
    }

    return b_polynomials;
}
