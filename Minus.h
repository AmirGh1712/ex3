#ifndef MINUS_H
#define MINUS_H


#include "BinaryOperator.h"
/**
 * Minus Class
 */
class Minus : public BinaryOperator {
public:
    /**
     * Constructor.
     * @param left the left expression.
     * @param right the right expression.
     */
    Minus(Expression* left, Expression* right) : BinaryOperator(left, right){}
    virtual double calculate();
};



#endif //MINUS_H
