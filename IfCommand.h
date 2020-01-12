#ifndef IF_COMMAND_H
#define IF_COMMAND_H

#include "Command.h"
#include "BoolExpression.h"
#include "ExpressionReader.h"
#include "ExpressionFactory.h"
#include <list>
#include <string>
#include "Parser.h"
#include <map>

/**
 * Main class for if command.
 */
class IfCommand : public Command {
private:
    ExpressionFactory* ef;
    map<string, Command*> *m;
    VariablesMap* vm;
public:
    /**
     * Constructor.
     * @param expressionFactory the expression factory.
     * @param map the command map.
     * @param variablesMap the variables map.
     */
    IfCommand(ExpressionFactory* expressionFactory, map<string, Command*> *map, VariablesMap* variablesMap) {
        this->ef = expressionFactory;
        this->m = map;
        this->vm = variablesMap;
    }
    virtual int execute(list<string>::iterator place, list<string>::iterator end);
};


#endif //IF_COMMAND_H
