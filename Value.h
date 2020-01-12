#ifndef VALUE_H
#define VALUE_H

#include "Expression.h"
/**
 * Value Class
 */
class Value : public Expression {
private:
    double val;
public:
    /**
     * Constructor.
     * @param v the value.
     */
    Value(double v);
    virtual double calculate();
};



#endif //PROJECT_VALUE_H
