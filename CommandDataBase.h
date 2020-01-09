//
// Created by iddo on 04/01/2020.
//

#ifndef UNTITLED_COMMANDDATABASE_H
#define UNTITLED_COMMANDDATABASE_H

#include <map>
#include <string>
#include "Command.h"

using namespace std;

/**
 * A database of the variables read.
 */
class CommandDataBase {
    map<string, Command *> commandTable;
public:
    const map<string, Command *> &getCommandTable() const {
        return commandTable;
    };

    void addCommand(string varName, Command *c);

    Command *getCommand(const string &CommandName);

};


#endif //UNTITLED_COMMANDDATABASE_H
