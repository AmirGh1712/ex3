//
// Created by iddo on 08/01/2020.
//

#include "BoolExpression.h"

double BoolExpression::calculate() {
    double l = leftEx->calculate(), r = rightEx->calculate();
    if (this->condition == "<") {
        return l < r;
    } else if (this->condition == "<=") {
        return l <= r;
    } else if (this->condition == "==") {
        return l == r;
    } else if (this->condition == "!=") {
        return l != r;
    } else if (this->condition == ">=") {
        return l >= r;
    } else if (this->condition == ">") {
        return l > r;
    } else {
        throw runtime_error("Invalid Operator: " + this->condition);
    }
}
