//
// Created by junaidrahim on 9/9/18.
//

#ifndef PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H
#define PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H

#include "../include/BasisPolynomial.h" // this has <vector> and <string> included

using namespace std;

class LagrangePolynomial {
private:
    int64_t find_product(vector<int> data);

public:
    struct element{
        int64_t multiple;
        vector<string> p; // the polynomials
        int64_t denominator;
    };

    vector<element> get_lagrange_polynomial(vector<int> data_points, vector<poly> basis_polynomial);
};



#endif //PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H
