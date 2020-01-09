//
// Created by amir on 30/12/2019.
//

#ifndef EX3_11_PRINTCOMMAND_H
#define EX3_11_PRINTCOMMAND_H

#include "Command.h"
#include <iostream>

class PrintCommand : public Command {
public:
    virtual int execute(string * place);
};



#endif //EX3_11_PRINTCOMMAND_H