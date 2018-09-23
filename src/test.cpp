//
// Created by junaidrahim on 21/9/18.
//

#include <iostream>

#include <vector>
#include <string>
#include <fstream>

#include "../include/LagrangePolynomial.h"
#include "../include/CodeGenerator.h"

void generate_programs(vector<LagrangePolynomial::element> result);

int main(){

    vector<int> data_y = {1,4,9,16,25,36};
    vector<int> data_x = {1,2,3,4,5,6};

    BasisPolynomial bp(data_x);
    // What is poly ?
    // poly => ((x-2)(x-3)/2) => struct {vector<string> numerators,vector<int> denominators}
    vector<poly> basis_polynomials = bp.get_all_basis_polynomials();

    LagrangePolynomial lp;

    // What is element ?
    // (4(x-2)(x-3))/2 => struct {int multiple, vector<string> p, int denominator}
    vector<LagrangePolynomial::element> result = lp.get_lagrange_polynomial(data_y,basis_polynomials);

    for(int j=0; j<result.size(); j++){ //prints the lp in the format 4 (x-2)(x-3) 2
        cout << result[j].multiple << " ";
        for(int i=0; i<data_x.size()-1; i++){
            cout << result[j].p[i] << " ";
        }
        cout << result[j].denominator << endl;
    }

    // if in doubt, /**/ it out
    generate_programs(result);

    return 0;
}

void generate_programs(vector<LagrangePolynomial::element> result){

    CodeGenerator cg(result);
    CodeGenerator::code_arr all_programs = cg.generate_all_lang_code();

    ofstream outfile;
    string file = "/home/junaidrahim/Desktop/test/test.";

    for(int i=0; i<6; i++){
        outfile.open(file+all_programs.languages[i]);
        outfile << all_programs.code[i] << endl;
        outfile.close();
    }

}