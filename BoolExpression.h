#ifndef BOOL_EXPRESSION_H
#define BOOL_EXPRESSION_H

#include <string>
#include "BinaryOperator.h"

class BoolExpression : public BinaryOperator {
    string condition;
public:
    /**
     * Constructor.
     * @param left the left expression.
     * @param c the boolean sign.
     * @param right the right expression.
     */
    BoolExpression(Expression *left, string c, Expression *right) : BinaryOperator(left, right) {
        this->condition.assign(c);
    }

    virtual double calculate();
};


#endif //BOOL_EXPRESSION_H
