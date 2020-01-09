//
// Created by amir on 30/12/2019.
//

#ifndef EX3_11_OPENSERVERCOMMAND_H
#define EX3_11_OPENSERVERCOMMAND_H

#include "Command.h"
#include <thread>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>

class OpenServerCommand : public Command {
private:
    thread thread1;
public:
    virtual int execute(string * place);
    void join() {
        this->thread1.join();
    }
};
int openServer(int port);

#endif //EX3_11_OPENSERVERCOMMAND_H