//
// Created by junaidrahim on 9/9/18.
//

#ifndef PROGRAM_HOMEWORK_SOLVER_POLY_H
#define PROGRAM_HOMEWORK_SOLVER_POLY_H

#include <vector>
#include <string>

class poly {
public:
    std::vector<std::string> numerators;
    std::vector<int> denominators;

    void add_to_numerator(std::string n);
    void add_to_denominator(int d);
};


#endif //PROGRAM_HOMEWORK_SOLVER_POLY_H
