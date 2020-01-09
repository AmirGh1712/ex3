//
// Created by amir on 31/12/2019.
//

#ifndef EX3_11_CONNECTCOMMAND_H
#define EX3_11_CONNECTCOMMAND_H

#include "Command.h"
#include <thread>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>
#include <string.h>
#include <arpa/inet.h>

class ConnectCommand : public Command {
private:
    thread thread1;
public:
    virtual int execute(string * place);
    void join() {
        this->thread1.join();
    }
};
int connectControlClient(int port, const char* addr);

#endif //EX3_11_CONNECTCOMMAND_H