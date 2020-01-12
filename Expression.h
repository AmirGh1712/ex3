
#ifndef EXPRESSION_H
#define EXPRESSION_H

using namespace std;
/**
 * Expression Interface
 */
class Expression {

public:
    /**
     * Calculate the expression.
     * @return the value of the expression.
     */
    virtual double calculate() = 0;
    /**
     * Destructor.
     */
    virtual ~Expression() {}
};

#endif //EXPRESSION_H
