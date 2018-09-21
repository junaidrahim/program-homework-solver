#include <iostream>

#include <vector>
#include <string>
#include <fstream>

#include "include/LagrangePolynomial.h"
#include "include/CodeGenerator.h"

using namespace std;

int main() {

    vector<int> data_y = {0,5,10,15,20};
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


    CodeGenerator cg(result);

    ofstream outfile;

    CodeGenerator::code_arr all_programs = cg.generate_all_lang_code();

    string file = "/home/junaidrahim/Desktop/test/test.";

    for(int i=0; i<6; i++){
        outfile.open(file+all_programs.languages[i]);
        outfile << all_programs.code[i] << endl;
        outfile.close();
    }



    return 0;


}

