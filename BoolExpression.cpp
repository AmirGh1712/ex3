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
        throw "Invalid Operator";
    }
}
