#include "SleepCommand.h"
int SleepCommand::execute(list<string>::iterator place, list<string>::iterator end) {
    list<string>::iterator it = place;
    it++;
    ExpressionReader er;
    list<string> l = er.getExpressions(it, end);
    Expression *e = this->ef->create(l);
    Command::lock();
    double value = e->calculate();
    Command::unlock();
    this_thread::sleep_for(chrono::seconds((int)(value/ 1000)));
    return 1 + l.size();
}