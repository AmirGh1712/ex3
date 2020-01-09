#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "Expression.h"

/**
 * Binary Operator Interface
 */
class BinaryOperator : public Expression {
protected:
    Expression *leftEx;
    Expression *rightEx;
public:
    BinaryOperator(Expression *left, Expression *right) {
        this->leftEx = left;
        this->rightEx = right;
    }

    virtual double calculate() = 0;

    virtual ~BinaryOperator() override {
        delete (this->leftEx);
        delete (this->rightEx);
    }
};


#endif //BINARY_OPERATOR_H
