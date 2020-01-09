//
// Created by amir on 01/01/2020.
//

#include "VarCommand.h"

int VarCommand::execute(string *place) {
    string varName = *(place + 1);
    string sign = *(place + 2);
    string sim = *(place + 3);
    string addr = *(place + 4);
    this->vars[varName] = new Variable(0, addr);
    return 5;
}