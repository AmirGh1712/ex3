
#ifndef DIV_H
#define DIV_H


#include "BinaryOperator.h"
/**
 * Divide Class
 */
class Div : public BinaryOperator {
public:
    /**
     * Constructor.
     * @param left the left expression.
     * @param right the right expression.
     */
    Div(Expression* left, Expression* right) : BinaryOperator(left, right){}
    virtual double calculate();
};


#endif //DIV_H
