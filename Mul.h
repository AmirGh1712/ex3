#ifndef MUL_H
#define MUL_H

#include "BinaryOperator.h"
/**
 * Multiplation Class
 */
class Mul : public BinaryOperator {
public:
    Mul(Expression* left, Expression* right) : BinaryOperator(left, right){}
    virtual double calculate();
};


#endif //MUL_H
