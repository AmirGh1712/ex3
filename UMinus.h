

#ifndef UMINUS_H
#define UMINUS_H

#include "UnaryOperator.h"
/**
 * Unary Minus Class
 */
class UMinus : public UnaryOperator {
public:
    virtual double calculate();
    UMinus(Expression* expression): UnaryOperator(expression) {}
};


#endif //UMINUS_H
