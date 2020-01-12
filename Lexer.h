#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <list>
#include <regex>
#include <sstream>
#include <algorithm>
#include <fstream>

#include <iostream>

using namespace std;

/**
 * The lexer for our program.
 */
class Lexer {
private:
    list<string> specialCharacters{"->", "<-", "+", "<", ">", "==", "<=", ">=", "/\"", "/", "(",
                                   ")",
                                   "*", "-", "=", "\"", ",", "{", "}", "\t"};

/**
     * The function will replace all occurrences of a certain substring with another substring.
     * @param subject the main string we want to chance.
     * @param search the substring we are looking for
     * @param replace the replacement
     * @return the
     */
    string replaceSubString(string subject, const string &search, const string &replace);

    /**
     * The function adds spaces before and after the special signs if it's valid
     * @param s the string we want to update.
     */
    void addSpaces(string &s);

    /**
     * Seperate the string.
     * @param s the string.
     * @param delimiter the delimiter.
     * @return list of the strings.
     */
    vector<string> baseSplit(string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

public:
    /**
     * The function creates a list of tokens from the string, with a delimiter for
     * for separation.
     * @param s
     * @param delimiter
     * @return list of strings of all the tokens.
     */
    list<string> lexer(string &s, char delimiter);
};


#endif //LEXER_H
