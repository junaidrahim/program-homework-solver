//
// Created by junaidrahim on 19/9/18.
//

#ifndef PROGRAM_HOMEWORK_SOLVER_CODEGENERATOR_H
#define PROGRAM_HOMEWORK_SOLVER_CODEGENERATOR_H

#include "LagrangePolynomial.h" // this has <vector> and <string> included

using namespace std;

class CodeGenerator {
private:
    vector<LagrangePolynomial::element> lagrange_polynomial;

    string get_polynomial_string();

public:
    struct code_arr{
        vector<string> code;
        vector<string> languages;
    };

    CodeGenerator(vector<LagrangePolynomial::element> p);


    code_arr generate_all_lang_code();

    string generate_c_code();
    string generate_cpp_code();
    string generate_python_code();
    string generate_go_code();
    string generate_js_code();
    string generate_java_code();
};


#endif //PROGRAM_HOMEWORK_SOLVER_CODEGENERATOR_H
