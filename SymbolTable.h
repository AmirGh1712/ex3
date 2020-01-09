//
// Created by iddo on 09/01/2020.
//

#ifndef UNTITLED_SYMBOLTABLE_H
#define UNTITLED_SYMBOLTABLE_H

#include <string>
#include <map>
#include <mutex>
#include <iostream>

using namespace std;

/**
 * Creates a map of strings representing symbols; and their values.
 */
class SymbolTable {
    map<string, double> symbolTable;
    static SymbolTable *map_instance;
public:
    static inline SymbolTable *instance() {
        if (map_instance == nullptr) {
            map_instance = new SymbolTable();
        }
        return map_instance;
    }

    inline const map<string, double> &getVarTable() const {
        return this->symbolTable;
    }

    inline void setValue(string key, double value) {
        this->symbolTable[key] = value;
    }

    inline double getValue(const string &key) {
        double temp;
        if (this->symbolTable.count(key) == 1) {
            temp = this->symbolTable[key];
            return temp;
        } else {
            throw runtime_error("var: " + key + "not exists");
        }

    }

    ~SymbolTable() {
        delete map_instance;
    }
};


#endif //UNTITLED_SYMBOLTABLE_H
