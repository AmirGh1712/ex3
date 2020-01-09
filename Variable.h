//
// Created by amir on 01/01/2020.
//

#ifndef EX3_11_VARIABLE_H
#define EX3_11_VARIABLE_H

#include <string>

class Variable {
private:
    int value;
    std::string sim;
public:
    Variable(int val, std::string s) {
        this->value = val;
        this->sim.assign(s);
    }
};


#endif //EX3_11_VARIABLE_H
