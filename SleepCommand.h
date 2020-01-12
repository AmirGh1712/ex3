#ifndef SLEEP_COMMAND_H
#define SLEEP_COMMAND_H

#include "Command.h"
#include <thread>
#include <chrono>
#include "ExpressionFactory.h"
#include "ExpressionReader.h"

class SleepCommand : public Command {
private:
    ExpressionFactory* ef;
public:
    /**
     * Constructor.
     * @param expressionFactory the expression factory.
     */
    SleepCommand(ExpressionFactory* expressionFactory) {
        this->ef = expressionFactory;
    }
    virtual int execute(list<string>::iterator place, list<string>::iterator end);
};


#endif //SLEEP_COMMAND_H
