//
// Created by amir on 01/01/2020.
//

#ifndef EX3_11_VARCOMMAND_H
#define EX3_11_VARCOMMAND_H

#include "Command.h"
#include "Variable.h"
#include <map>

class VarCommand : public Command {
private:
    std::map<string, Variable*> vars;
public:
    virtual int execute(string* place);

};


#endif //EX3_11_VARCOMMAND_H
