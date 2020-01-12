#ifndef PLUS_H
#define PLUS_H

#include "BinaryOperator.h"
/**
 * Plus Class
 */
class Plus : public BinaryOperator {
public:
    /**
     * Constructor.
     * @param left the left expression.
     * @param right the right expression.
     */
    Plus(Expression* left, Expression* right) : BinaryOperator(left, right){}
    virtual double calculate();
};


#endif //PLUS_H
