#include "IfCommand.h"

int IfCommand::execute(list<string>::iterator place, list<string>::iterator end) {
    list<string>::iterator it = place;
    int p = 1;
    it++;
    //creates the condition.
    ExpressionReader er;
    list<string> lst = er.getExpressions(it, end);
    Expression* l = this->ef->create(lst);
    p += lst.size();
    if(it == end) {
        throw "Error";
    }
    string c = *it;
    it++;
    p++;
    if(it == end) {
        throw "Error";
    }
    c += *it;
    it++;
    p++;
    lst = er.getExpressions(it, end);
    p += lst.size();
    Expression* r = this->ef->create(lst);
    BoolExpression condition(l, c, r);
    if(it == end) {
        throw "Error";
    }
    if (*it != "{") {
        throw "Error";
    }
    it++;
    p++;
    //creates the list of the commands.
    list<string> cmds;
    while (*it != "}") {
        cmds.push_back(*it);
        it++;
        p++;
        if (it == end) {
            throw "Error";
        }
    }
    p++;
    Command::lock();
    if (condition.calculate()) {
        Command::unlock();
        parser(cmds, *this->m, this->vm, this->ef);
    } else {
        Command::unlock();
    }
    return p;
}