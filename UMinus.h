#ifndef UMINUS_H
#define UMINUS_H

#include "UnaryOperator.h"
/**
 * Unary Minus Class
 */
class UMinus : public UnaryOperator {
public:
    virtual double calculate();
    /**
     * Constructor.
     * @param expression the expression.
     */
    UMinus(Expression* expression): UnaryOperator(expression) {}
};


#endif //UMINUS_H
