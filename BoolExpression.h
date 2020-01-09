//
// Created by iddo on 08/01/2020.
//

#ifndef UNTITLED_BOOLEXPRESSION_H
#define UNTITLED_BOOLEXPRESSION_H

#include <string>
#include "BinaryOperator.h"

#include <stdexcept>
/*
 * an expression with a left side, an operator and a right side
 */
class BoolExpression :public BinaryOperator{
    string condition;
public:
    BoolExpression(Expression* left, string c, Expression* right) : BinaryOperator(left, right){
        this->condition = c;
    }

    // Returns either 0 or 1
    double calculate();
};


#endif //UNTITLED_BOOLEXPRESSION_H
