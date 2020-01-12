#ifndef UPLUS_H
#define UPLUS_H


#include "UnaryOperator.h"
/**
 * Unary Plus Class
 */
class UPlus : public UnaryOperator {
public:
    virtual double calculate();
    /**
     * Constructor.
     * @param expression the expression.
     */
    UPlus(Expression* expression): UnaryOperator(expression) {}
};



#endif //UPLUS_H
