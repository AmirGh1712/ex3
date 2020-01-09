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
#include <list>

using namespace std;

/**
 * Creates an expression from a list of tokens.
 */
class ExpressionFactory {
public:

    Expression *create(list<string> tokens);

};


#endif //UNTITLED_EXPRESSIONFACTORY_H
