#ifndef MUL_H
#define MUL_H

#include "BinaryOperator.h"
/**
 * Multiplation Class
 */
class Mul : public BinaryOperator {
public:
    /**
     * Constructor.
     * @param left the left expression.
     * @param right the right expression.
     */
    Mul(Expression* left, Expression* right) : BinaryOperator(left, right){}
    virtual double calculate();
};


#endif //MUL_H
