#include <iostream>

#include <vector>
#include <string>

#include "include/LagrangePolynomial.h"

using namespace std;

int main() {

    vector<int> data_y = {1,4,9,16,25};
    vector<int> data_x;
    for(int i=0; i<data_y.size(); i++){
        data_x.push_back(i+1);
    }

    BasisPolynomial bp(data_x);
    vector<poly> basis_polynomials = bp.get_all_basis_polynomials();

    LagrangePolynomial lp;

    vector<LagrangePolynomial::element> result = lp.get_lagrange_polynomial(data_y,basis_polynomials);

    for(int j=0; j<result.size(); j++){
        cout << result[j].multiple << " ";
        for(int i=0; i<data_x.size()-1; i++){
            cout << result[j].p[i] << " ";
        }
        cout << result[j].denominator << endl;

    }


    return 0;

}

