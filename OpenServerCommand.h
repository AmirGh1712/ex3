#ifndef OPEN_SERVER_COMMAND_H
#define OPEN_SERVER_COMMAND_H

#include "Command.h"
#include <thread>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>
#include "SimVariables.h"
#include "VariablesMap.h"
#include "ExpressionFactory.h"
#include "ExpressionReader.h"
#include <list>
#include <string>

/**
 * Main class for open server command.
 */
class OpenServerCommand : public Command {
private:
    thread thread1;
    SimVariables sv;
    VariablesMap *vm;
    ExpressionFactory* ef;
    bool run;
public:
    /**
     * Constructor.
     * @param map the simulator variables map.
     * @param expressionFactory the expression factory.
     */
    OpenServerCommand(VariablesMap *map, ExpressionFactory* expressionFactory) {
        this->vm = map;
        this->ef = expressionFactory;
        this->sv.create();
        this->run = false;
    }
    virtual int execute(list<string>::iterator place, list<string>::iterator end);
    /**
     * join the thread.
     */
    void join() {
        if (this->run) {
            this->thread1.join();
        }
    }

};
/**
 * Open the server and listening to a client.
 * @param port the port.
 * @param sv the simulator variables.
 * @param vm the variables map.
 * @return the error.
 */
int openServer(int port, SimVariables sv, VariablesMap* vm);

#endif //OPEN_SERVER_COMMAND_H
