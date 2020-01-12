//
// Created by iddo on 08/01/2020.
//

#include "ExpressionReader.h"

#define DIV_OP "/"
#define MULT_OP "*"
#define PLUS_OP "+"
#define MINUS_OP "-"

bool isOperator(const list<string>::iterator &it){
    return *it == DIV_OP || *it == MULT_OP || *it == PLUS_OP || *it == MINUS_OP;
}
list<string> ExpressionReader::getExpressions(list<string>::iterator &it, list<string>::iterator &end) {
    bool endOfExpression = false;
    int argumentsLeft = 1;
    list<string> expression;
    while (!endOfExpression) {
        if (it == end) {
            endOfExpression = true;
            continue;
        }
        if (isOperator(it)) {
            expression.push_back(*it);
            argumentsLeft = 1;

        } else if (argumentsLeft) {
            if(*it == "("){
                while (*it != ")") {

                    expression.push_back(*it);
                    it++;
                    if (it == end) {
                        endOfExpression = true;
                        cerr << "Wrong Syntax" << endl;
                        break;
                    }
                }
                continue;
            }
            expression.push_back(*it);
            argumentsLeft--;

        } else {
            endOfExpression = true;
            continue;
        }
        it++;
    }
    return expression;
}
