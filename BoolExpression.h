//
// Created by iddo on 08/01/2020.
//

#ifndef UNTITLED_BOOLEXPRESSION_H
#define UNTITLED_BOOLEXPRESSION_H

#include <string>
#include "BinaryOperator.h"

#include <stdexcept>

class BoolExpression :public BinaryOperator{
    string condition;
public:
    BoolExpression(Expression* left, string c, Expression* right) : BinaryOperator(left, right){
        this->condition = c;
    }

    double calculate();
};


#endif //UNTITLED_BOOLEXPRESSION_H
