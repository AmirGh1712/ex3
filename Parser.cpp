#include "Parser.h"

void parser(list<string> array, map<string, Command*> map, VariablesMap* vm, ExpressionFactory* ef) {
    list<string>::iterator it = array.begin();
    while (it != array.end()) {
        if (*it == "\n") {
            it++;
            continue;
        }
        Command* c = map[*it];
        if (c != nullptr) {
            int i = c->execute(it, array.end());
            for (int j = 0; j < i; ++j) {
                it++;
            }
        } else if (vm->isExists(*it)) {
            //for variables
            string n = *it;
            it++;
            if (it == array.end()) {
                throw "Error";
            }
            if((*it) == "=") {
                Command::lock();
                it++;
                ExpressionReader er;
                list<string>::iterator end = array.end();
                list<string> l = er.getExpressions(it, end);
                double val = ef->create(l)->calculate();
                Command::unlock();
                vm->set(n, val);

            } else {
                throw "Error";
            }
        } else {
            cout << *it << endl;
            throw "Error";
        }
    }
}