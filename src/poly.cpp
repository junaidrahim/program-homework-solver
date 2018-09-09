//
// Created by junaidrahim on 9/9/18.
//

#include "../include/poly.h"

void poly::add_to_numerator(std::string n) {
    numerators.push_back(n);
}

void poly::add_to_denominator(int d) {
    denominators.push_back(d);
}