//
// Created by amir on 30/12/2019.
//

#include "Parser.h"

void Parser::parser(string array[], int len, map<string, Command*> map) {
    int  i = 0;
    while (i < len) {
        Command* c = map[array[i]];
        if (c != nullptr) {
            i += c->execute(&array[i]);
        }
    }
}