#ifndef VARIABLES_MAP_H
#define VARIABLES_MAP_H

#include "Variable.h"
#include <map>

using namespace std;

/**
 * main class of variables map.
 */
class VariablesMap {
private:
    map<string, Variable*> m;
public:
    /**
     * Gets a variable.
     * @param str the key.
     * @return the variable's value.
     */
    double get(string str) {
        return this->m[str]->calculate();
    }
    /**
     * Sets the variable key.
     * @param str the key.
     * @param value the value.
     */
    void set(string str, double value) {
        if(this->isExists(str)) {
            this->m[str]->set(value);
        }
    }
    /**
     * Returns if key exsits.
     * @param name the key.
     * @return if key exsits.
     */
    bool isExists(string name) {
        return this->m.find(name) != this->m.end();
    }
    /**
     * Add a variable to the map.
     * @param v the variable.
     */
    void add(Variable* v, string key) {
        this->m[key] = v;
    }
    /**
     * Returns the Variable.
     * @param name the variable's name.
     * @return the variable.
     */
    Variable* getVar(string name) {
        return this->m[name];
    }
};


#endif //VARIABLES_MAP_H
