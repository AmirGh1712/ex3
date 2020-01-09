#ifndef UPLUS_H
#define UPLUS_H


#include "UnaryOperator.h"
/**
 * Unary Plus Class
 */
class UPlus : public UnaryOperator {
public:
    virtual double calculate();
    UPlus(Expression* expression): UnaryOperator(expression) {}
};



#endif //UPLUS_H
