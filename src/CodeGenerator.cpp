//
// Created by junaidrahim on 19/9/18.
//

#include "../include/CodeGenerator.h"

CodeGenerator::CodeGenerator(vector<LagrangePolynomial::element> p) {
    CodeGenerator::lagrange_polynomial = p;
    CodeGenerator::func = get_polynomial_string();
}


string CodeGenerator::get_polynomial_string() {

//    1 x-2 x-3 2
//    4 x-1 x-3 -1      =>  int f(int x) = ((1*(x-2)*(x-3))/2) + ((4*(x-1)*(x-3))/-1) + ((9*(x-1)*(x-2))/2)
//    9 x-1 x-2 2                   this can be used in each language's source

    string result;

    for(int i=0; i<lagrange_polynomial.size(); i++){
        string polynomial; //*(x-2)*(x-3)

        for(int j=0; j<lagrange_polynomial[i].p.size(); j++){
            polynomial += "*(" + lagrange_polynomial[i].p[j] +")";
        }

        string m = to_string(lagrange_polynomial[i].multiple);
        string d = to_string(lagrange_polynomial[i].denominator);

        // result will be something like ((1*(x-2)*(x-3))/2) => (m=1),(d=2)

        result += "((" + m + polynomial + ")/" + d + ")";

        if(i!=lagrange_polynomial.size()-1){
            result += "+";
        }

    }

    return result;
}

CodeGenerator::code_arr CodeGenerator::generate_all_lang_code() {
    code_arr result;

    result.languages = {"c","cpp","py","go","js","java"}; // keeping these the same as the extensions

    result.code.push_back(generate_c_code());
    result.code.push_back(generate_cpp_code());
    result.code.push_back(generate_python_code());
    result.code.push_back(generate_go_code());
    result.code.push_back(generate_js_code());
    result.code.push_back(generate_java_code());

    return result;
}


string CodeGenerator::generate_c_code() {
    string code =
            "// Generated by program-homework-solver\n\n"
            "#include <stdio.h>"
            "\n\n"
            "int f(int x){\n"
            "\tint answer = " + CodeGenerator::func + ";\n"
            "\treturn answer;\n"
            "}\n\n"
            "void main(){"
            "\n\n"
            "\tfor(int i=0; i<20; i++){\n"
            "\t\tprintf(\"%d \",f(i));\n"
            "\t}\n"
            "}";


    return code;
}


string CodeGenerator::generate_cpp_code() {
    string func = get_polynomial_string();
    string code =
            "// Generated by program homework solver"
            "\n\n"
            "#include <iostream>\n\n"
            "using namespace std;\n\n"
            "int64_t f(int x) {\n"
            "\tint64_t answer =" + CodeGenerator::func + ";\n"
            "\treturn answer;\n"
            "}\n\n"
            "int main(){\n"
            "\tfor(int i=0; i<20; i++){\n"
            "\t\tcout << f(i) << endl;\n"
            "\t}\n"
            "\treturn 0;\n"
            "}";

    return code;
}


string CodeGenerator::generate_python_code() {
    string code =
            "# Generated by program-homework-solver \n\n"
            "def f(x):\n"
            "\tanswer = " + CodeGenerator::func + "\n"
            "\treturn answer\n"
            "\nfor i in range(0,20):\n"
            "\tprint(f(i))\n";

    return code;
}


string CodeGenerator::generate_go_code() {
    string code =
            "// Generated by program-homework-solvern\n\n"
            "package main"
            "\n\n"
            "import(\"fmt\")\n"
            "\nfunc f(x int64) int64 {\n"
            "\tanswer := " + CodeGenerator::func +"\n"
            "\treturn answer;\n"
            "}\n\n"
            "func main(){\n"
            "\n\tvar i int64;"
            "\n\tfor i=0; i<20; i++ {\n"
            "\t\tfmt.Println(f(i))\n"
            "\t}\n"
            "\n}";

    return code;
}

string CodeGenerator::generate_js_code() {
    string code =
            "// Generated by program-homework-solver \n\n"
            "function f(x){\n"
            "\tlet answer = "+CodeGenerator::func+"\n"
            "\treturn answer\n"
            "}\n\n"
            "for(i=0; i<20; i++){\n"
            "\tconsole.log(f(i))\n"
            "}";

    return code;
}

string CodeGenerator::generate_java_code() {
    string code =
            "// Generated by program-homework-solver \n\n"
            "class test{\n\n"
            "\tpublic int f(int x){\n"
            "\t\tint answer = " + CodeGenerator::func +";\n"
            "\t\treturn answer;\n"
            "}\n\n"
            "\tpublic static void main(String args[]){\n"
            "\t\ttest t = new test();\n"
            "\t\tfor(int i=0; i<20; i++){\n"
            "\t\t\tSystem.out.println(t.f(i));\n"
            "\t\t}\n"
            "\n\t}"
            "\n}";

    return code;
}