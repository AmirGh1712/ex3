#ifndef WHILE_COMMAND_H
#define WHILE_COMMAND_H

#include "Command.h"
#include "BoolExpression.h"
#include "ExpressionReader.h"
#include "ExpressionFactory.h"
#include <list>
#include <string>
#include "Parser.h"
#include <map>

class WhileCommand : public Command {
private:
    ExpressionFactory* ef;
    map<string, Command*> *m;
    VariablesMap* vm;
public:
    /**
     * Constructor.
     * @param expressionFactory the expression factory.
     * @param map the commands map.
     * @param variablesMap the variables map.
     */
    WhileCommand(ExpressionFactory* expressionFactory, map<string, Command*> *map, VariablesMap* variablesMap) {
        this->ef = expressionFactory;
        this->m = map;
        this->vm = variablesMap;
    }
    virtual int execute(list<string>::iterator place, list<string>::iterator end);
};


#endif //WHILE_COMMAND_H
