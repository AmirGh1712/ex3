#include "PrintCommand.h"


int PrintCommand::execute(list<string>::iterator place, list<string>::iterator end) {
    Command::lock();
    int p = 3;
    list<string>::iterator it = place;
    it++;
    if (it == end) {
        throw "Error";
    }
    if (*it != "(") {
        throw "Error";
    }
    it++;
    if (it == end) {
        throw "Error";
    }
    string str = checkString(*it);
    if (str != "\"") {
        cout << str << endl;
        it++;
    } else {
        ExpressionReader er;
        list<string> l = er.getExpressions(it, end);
        p = 2 + l.size();
        Expression* e = this->ef->create(l);
        cout << e->calculate() << endl;
    }

    if (it == end) {
        throw "Error";
    }
    if (*it != ")") {
        throw "Error";
    }
    Command::unlock();
    return p + 1;

}
