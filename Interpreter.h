#ifndef INTERPRETER_H
#define INTERPRETER_H

#define VARIABLES_ERROR "illegal variable assignment!"
#define EXPRESSION_ERROR "illegal math expression"
#define MEMORY_ERROR "no memory"

#include <map>
#include <stack>
#include "Variable.h"
#include "Value.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "UMinus.h"
#include "UPlus.h"
using namespace std;
/**
 * Interpreter Class
 */
class Interpreter {
    map<string, Variable*> Vars;
public:
    /**Set the variables according to the string.
     *
     * @param variables the variables string.
     */
    void setVariables(string variables);
    /**Splits the string where there is ';'.
     *
     * @param variables the variables string.
     * @param p pointer to th sets array.
     * @return the number of sets.
     */
    int divideToSets(string variables, string** p);
    /**Add all the variables according to the sets.
     *
     * @param count the number of sets.
     * @param sets the sets.
     */
    void addVariables(int count, string* sets);
    /**Generate an expression according to the string.
     *
     * @param str the string to generate from.
     * @return the expression.
     */
    Expression* interpret(string str);
};
/**Use an operator.
 *
 * @param o the operator char.
 * @param output the output stack
 * @param operators the operators stack.
 */
void addOperator(char o, stack<Expression*> *output, stack<char> operators);

#endif //INTERPRETER_H
