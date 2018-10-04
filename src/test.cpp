//
// Created by junaidrahim on 21/9/18.
//

#include <iostream>

#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>

#include "../include/LagrangePolynomial.h"
#include "../include/CodeGenerator.h"

void generate_all_programs(vector<LagrangePolynomial::element> &result, string &path);

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

    // if in doubt, /**/ it out
    string path;
    char pwd[256];
    getcwd(pwd, 255);
    path = pwd;

    generate_all_programs(result,path);

    return 0;
}

void generate_all_programs(vector<LagrangePolynomial::element> &result,string &path){
    CodeGenerator cg(result);
    CodeGenerator::code_arr all_programs = cg.generate_all_lang_code();

    ofstream outfile;
    string file_path = path+"/program_hw.";
    
    cout << "\n" ;

    for(int i=0; i<6; i++){
        outfile.open(file_path + all_programs.languages[i]);
        cout << "Writing " << all_programs.languages[i]
             << " file to " << file_path + all_programs.languages[i] << endl;
        outfile << all_programs.code[i] << endl;
        outfile.close();
    }
}
