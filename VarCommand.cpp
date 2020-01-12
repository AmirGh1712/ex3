#include "VarCommand.h"

int VarCommand::execute(list<string>::iterator place, list<string>::iterator end) {
    list<string>::iterator it = place;
    int p = 3;
    //variable name
    it++;
    if (it == end) {
        throw "Error";
    }
    string varName = *it;
    //variable sign.
    it++;
    if (it == end) {
        throw "Error";
    }
    string sign = *it;
    Variable* v;
    if (sign == "=") {
        //regular variable.
        ExpressionReader er;
        it++;
        if(it == end) {
            throw "Error";
        }
        list<string> l = er.getExpressions(it, end);
        v = new Variable(varName, this->ef->create(l)->calculate());
        this->vars->add(v, varName);
        p += l.size();
    } else if (sign == "<") {
        //simulator variable input
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != "-") {
            throw "Error";
        }
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != "sim") {
            throw "Error";
        }
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != "(") {
            throw "Error";
        }
        it++;
        if(it == end) {
            throw "Error";
        }
        string s = *it;
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != ")") {
            throw "Error";
        }
        v = new SimVariableIn(varName, 0, s);
        this->vars->add(v, varName);
        this->simVars->add(v, s);
        p += 5;
    } else if (sign == "-") {
        //simulator variable output
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != ">") {
            throw "Error";
        }
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != "sim") {
            throw "Error";
        }
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != "(") {
            throw "Error";
        }
        it++;
        if(it == end) {
            throw "Error";
        }
        string s = *it;
        it++;
        if(it == end) {
            throw "Error";
        }
        if(*it != ")") {
            throw "Error";
        }
        v = new SimVariableOut(varName, 0, s, this->cc);
        this->vars->add(v, varName);
        p += 5;
    } else {
        throw "Error";
    }
    return p;
}