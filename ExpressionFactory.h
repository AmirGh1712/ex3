#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H


#include "Expression.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include "VariablesMap.h"
#include "Value.h"
#include "Plus.h"
#include "Minus.h"
#include "Div.h"
#include "Mul.h"
#include "UMinus.h"
#include "UPlus.h"

#define EXPRESSION_ERROR "illegal math expression"
#define MEMORY_ERROR "no memory"

using namespace std;

/**
 * Creates an expression from a list of tokens.
 */
class ExpressionFactory {
private:
    VariablesMap* vm;

    /**
     * Returns if a string is a number.
     * @param token the string.
     * @return if a string is a number.
     */
    bool isNum(string &token);
    /**
     * Returns if a string is a variable.
     * @param token the string.
     * @return if a string is a variable.
     */
    bool isVar(string &token);
public:
    /**
     * Constructor.
     * @param vars the variables map.
     */
    ExpressionFactory(VariablesMap* vars) {
        this->vm = vars;
    }
    /**
     * Creates a expression out of list of string.
     * @param tokens the list.
     * @return the expression.
     */
    Expression *create(list<string> tokens);
};
/**Use an operator.
 *
 * @param o the operator char.
 * @param output the output stack
 * @param operators the operators stack.
 */
void addOperator(char o, stack<Expression*> *output);

#endif //EXPRESSION_FACTORY_H
