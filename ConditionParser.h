//
// Created by iddo on 02/01/2020.
//

#ifndef PROJECT_CONDITIONPARSER_H
#define PROJECT_CONDITIONPARSER_H

#include "Command.h"
#include "CommandDataBase.h"
#include "ExpressionFactory.h"
#include "BoolExpression.h"
#include "Parser.h"
#include <list>

using namespace std;

/*
 * check for boolean condition, execute list of commands
 */
class ConditionParser : public Command {
protected:
    CommandDataBase *db;
    list<string> leftExpression;
    list<string> rightExpression;
    string boolOperator;
    Parser *parser;
public:
    virtual void execute(list<string>::iterator &it) = 0;

    double checkBoolExpression(list<string> leftExpression, string boolOperator, list<string> rightExpression);

};

#endif //PROJECT_CONDITIONPARSER_H