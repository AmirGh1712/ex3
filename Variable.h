//
// Created by amir on 23/11/2019.
//

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Expression.h"
/**
 * Variable Class
 */
class Variable : public Expression {
string name;
double value;
public:
    /**
     * Constructor.
     * @param n the variable name.
     * @param val the variable value.
     */
    Variable(string n, double val) {
        this->name.assign(n);
        this->value = val;
    }
    virtual double calculate();
    Variable & operator++();
    Variable & operator--();
    Variable& operator+=(const double& num);
    Variable& operator-=(const double& num);
    Variable & operator++(int);
    Variable & operator--(int);
    /**
     * Sets the value.
     * @param v the new value.
     */
    virtual void set(double v);
    /**
     * Returns the name of the variable.
     * @return the name of the variable.
     */
    string getName() {
        string tmp;
        tmp.assign(this->name);
        return tmp;
    }
};


#endif //VARIABLE_H
