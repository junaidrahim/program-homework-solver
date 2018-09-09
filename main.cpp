#include <iostream>

#include "include/BasisPolynomial.h"

using namespace std;

int main() {

    vector<int> a = {1,2,3,4,5,6};

    BasisPolynomial b(a);

    vector<poly> polynomials = b.get_all_basis_polynomials();

    for(auto i=0; i<5; i++){
        cout << polynomials[5].numerators[i] << " " << polynomials[5].denominators[i] << endl;
    }

}

