//
// Created by amir on 30/12/2019.
//

#ifndef EX3_11_PARSER_H
#define EX3_11_PARSER_H


#include <map>
#include "Command.h"
using namespace std;
class Parser {
public:
    void parser(string array[], int len, map<string, Command *> map);
};

#endif //EX3_11_PARSER_H