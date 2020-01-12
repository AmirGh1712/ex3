#ifndef SIM_VARIABLE_IN_H
#define SIM_VARIABLE_IN_H


#include <string>
#include "Variable.h"

/**
 * Main class od input simulator variable.
 */
class SimVariableIn : public Variable {
private:
    std::string sim;
public:
    /**
     * Constructor.
     * @param name the var name.
     * @param val the value.
     * @param s the sim address.
     */
    SimVariableIn(string n, double val, std::string s) : Variable(n, val) {
        this->sim.assign(s);
    }
};

#endif //SIM_VARIABLE_IN_H
