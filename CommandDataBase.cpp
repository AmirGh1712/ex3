//
// Created by iddo on 04/01/2020.
//

#include "CommandDataBase.h"

// update or add command into map
void CommandDataBase::addCommand(string varName, Command *command) {
    this->commandTable[varName] = command;
}

Command *CommandDataBase::getCommand(const string &CommandName) {
    if (this->commandTable.count(CommandName) == 1)
        return this->commandTable[CommandName];
    else
        return nullptr;
}