//
// Created by iddo on 24/12/2019.
//

#include "Lexer.h"

string Lexer::replaceSubString(string subject, const string &search, const string &replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) { // return from function succeeded
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

void Lexer::addSpaces(string &s) {
    for (string &sign:this->specialCharacters) {
        if (s.find(sign) != string::npos) {
            s = replaceSubString(s, sign, " " + sign + " ");
        }
    }
}

list<string> Lexer::lexer(string &s, char delimiter) {
    list<string> tokens;
    string token;
    addSpaces(s);
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        if (token != " ") {
            tokens.push_back(token);
        }
    }
    string str;
    bool take = false;
    for (auto &s :tokens) {
        if (take) {
            str += s;
        }
        if (s == "\"" && !take) {
            take = true;
            str += s;
        }
    }
    bool found = false;
    list<string> final_tokens;

    string real_sign;
    vector<string> tmp{"=", "!", "<", ">"};
    for (list<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
        string cSign = *it;
        if (++it != tokens.end()) {
            string next = *(it);
            if (next == "=" && count(tmp.begin(), tmp.end(), (cSign)) == 1) {
                real_sign = cSign + next;
                final_tokens.push_back(real_sign);
            } else {
                --it;
                if (cSign == "\"") {
                    if (found) {
                        final_tokens.push_back(str);
                    } else {
                        found = true;
                        final_tokens.push_back(str);
                    }
                } else {
                    if (!found) {
                        final_tokens.push_back(cSign);
                    }
                }
            }
        } else {
            if (!found) {
                final_tokens.push_back(cSign);
            }
            break;
        }
    }
    return final_tokens;
}
