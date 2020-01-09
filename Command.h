//
// Created by amir on 30/12/2019.
//

#ifndef EX3_11_COMMAND_H
#define EX3_11_COMMAND_H

#include <mutex>
#include <string>
#include <iostream>

using namespace std;


static mutex m;
class Command {

public:

    static void lock() {
        m.lock();
    }
    static void unlock() {
        m.unlock();
    }
    virtual int execute(string * place) = 0;
};

string checkString(string str);
int strToInt(string str);

#endif //EX3_11
// _COMMAND_H