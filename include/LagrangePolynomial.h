//
// Created by junaidrahim on 9/9/18.
//

#ifndef PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H
#define PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H


#include "../include/BasisPolynomial.h"
using namespace std;

class LagrangePolynomial {
public:
    struct element{
        vector<string> p;
        int64_t denominator;
        int multiple;
    };

    int64_t find_product(vector<int> data);
    vector<element> get_lagrange_polynomial(vector<int> data_points, vector<poly> basis_polynomial);
};



#endif //PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H
