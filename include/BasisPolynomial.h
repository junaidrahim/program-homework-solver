//
// Created by junaidrahim on 9/9/18.
//

#ifndef PROGRAM_HOMEWORK_SOLVER_BASISPOLYNOMIAL_H
#define PROGRAM_HOMEWORK_SOLVER_BASISPOLYNOMIAL_H

#include <vector>
#include <string>

#include "poly.h"

using namespace std;

class BasisPolynomial {
private:
    vector<int> data_points;

public:
    BasisPolynomial(vector<int> data);
    vector<poly> get_all_basis_polynomials();
};
#endif //PROGRAM_HOMEWORK_SOLVER_BASISPOLYNOMIAL_H
