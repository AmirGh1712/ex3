//
// Created by iddo on 05/01/2020.
//

#ifndef UNTITLED_EXPRESSIONFACTORY_H
#define UNTITLED_EXPRESSIONFACTORY_H


#include "Expression.h"
#include "CommandDataBase.h"
#include "SymbolTable.h"
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class ExpressionFactory {
public:
/**
 * creating an expression
 * @param tokens list of tokes
 * @return expression
 */
    Expression *create(list<string> tokens);

};


#endif //UNTITLED_EXPRESSIONFACTORY_H
