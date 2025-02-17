#ifndef PRINT_COMMAND_H
#define PRINT_COMMAND_H

#include "Command.h"
#include <iostream>
#include "ExpressionFactory.h"
#include "ExpressionReader.h"
#include "string"
#include "list"

using namespace std;

/**
 * Main class of print command.
 */
class PrintCommand : public Command {
    ExpressionFactory* ef;
public:
    /**
     * Constructor.
     * @param expressionFactory the expression factory.
     */
    PrintCommand(ExpressionFactory* expressionFactory) {
        this->ef = expressionFactory;
    }
    virtual int execute(list<string>::iterator place, list<string>::iterator end);
};



#endif //PRINT_COMMAND_H
