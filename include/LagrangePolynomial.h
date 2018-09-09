//
// Created by junaidrahim on 9/9/18.
//

#ifndef PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H
#define PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H


#include <vector>
#include <string>

#include "poly.h"
#include "BasisPolynomial.h"

using namespace std;

class LagrangePolynomial {
public:
    LagrangePolynomial(vector<int> data_points,vector<poly> basis_polynomials);

};



#endif //PROGRAM_HOMEWORK_SOLVER_LAGRANGEPOLYNOMIAL_H
