// Created by amir on 30/12/2019.
//

#include "Command.h"

string checkString(string str) {
    if (str[0] == '\"' && str[str.length() - 1] == '\"') {
        return str.substr(1, str.length() - 2);
    }
    return "\"";
}

int strToInt(string str) {
    int i = 0 , neg = 0;
    int num = 0;
    int power10 = 1;
    if(str[0] == '-') {
        i++;
        neg = 1;
    }
    for (int j = i; j < str.length() - 1; ++j) {
        power10 *= 10;
    }
    for (i; i < str.length(); ++i) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            cerr << "Not a number." << endl;
            return 0;
        }
        num += power10 * (str[i] - '0');
        power10 /= 10;
    }
    if(neg) {
        return -num;
    }
    return num;
}