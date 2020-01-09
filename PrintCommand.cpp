//
// Created by amir on 30/12/2019.
//

#include "PrintCommand.h"


int PrintCommand::execute(string *place) {
    Command::lock();
    string str = checkString(place[1]);
    if (str != "\"") {
        cout << str << "\n";
    }
    Command::unlock();
    return 2;

}