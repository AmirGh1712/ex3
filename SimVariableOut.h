#ifndef SIM_VARIABLE_OUT_H
#define SIM_VARIABLE_OUT_H

#include <string>
#include "Variable.h"
#include "ConnectCommand.h"

/**
 * main class dor output simulator variable.
 */
class SimVariableOut : public Variable {
private:
    std::string sim;
    ConnectCommand* c;
public:
    /**
     * Constructor.
     * @param name the var name.
     * @param val the vale.
     * @param s the simulator address.
     * @param client the connect command.
     */
    SimVariableOut(string n, double val, std::string s, ConnectCommand* client) : Variable(n, val) {
        this->sim.assign(s);
        this->c = client;
    }
    virtual void set(double v) {
        Variable::set(v);
        string tmp = "set " + this->sim + " " + to_string(v);
        char* msg = (char*) malloc(sizeof(char) * tmp.length());
        for (unsigned int i = 0; i < tmp.length(); ++i) {
            msg[i] = tmp[i];
        }
        this->c->sendToServer(msg);
        delete(msg);
    }
};


#endif //SIM_VARIABLE_OUT_H
