#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>

#include "include/LagrangePolynomial.h"
#include "include/CodeGenerator.h"

using namespace std;

void generate_all_programs(vector<LagrangePolynomial::element> &result, string &path);

int main() {
    int n;
    cout << "Enter number of terms(n): ";
    cin >> n ;

    if(n<=0){ // If the user enters a character, it will still be 0
        cout << "That's Invalid. Please don't mess around :-(" << endl;
        return 0;
    }

    vector<int> data_y; // f(x)
    vector<int> data_x; // x

    printf("Enter the first n terms of the series: ");
    for(int i=0; i<n; i++){
        int k;
        scanf("%d",&k);
        data_y.push_back(k);
        data_x.push_back(i+1);
    }

    string path;
    cout << "Enter destination for source files [Current folder if empty]:";

    cin.ignore();
    getline(cin,path);
    if (path.empty()){
        char pwd[256];
        getcwd(pwd, 255);
        path = pwd;
    }
    cout << "Using path: " << path << endl;

    BasisPolynomial bp(data_x); // generating basis polynomials
    vector<poly> basis_p = bp.get_all_basis_polynomials();

    LagrangePolynomial lp; // generating the lagrange polynomial
    vector<LagrangePolynomial::element> results = lp.get_lagrange_polynomial(data_y,basis_p);

    generate_all_programs(results,path);
    cout << "\nDone. May the force be with you :-)" << endl;

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


