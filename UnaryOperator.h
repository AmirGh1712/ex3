

#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "Expression.h"
/**
 * Unary Operator Interface
 */
class UnaryOperator : public Expression {
protected:
    Expression* e;
public:
    //Constructor.
    UnaryOperator(Expression* expression) {
        this->e = expression;
    }
    virtual double calculate() = 0;
    virtual ~UnaryOperator() override {
        delete(this->e);
    }
};


#endif //UNARY_OPERATOR_H
