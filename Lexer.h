//
// Created by iddo on 24/12/2019.
//

#ifndef UNTITLED_LEXER_H
#define UNTITLED_LEXER_H

#include <string>
#include <list>
#include <regex>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * The lexer for our program.
 */
class Lexer {
private:
    list<string> specialCharacters{"+", "<", ">", "==", "<=", ">=", "/\"", "/", "(",
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
    inline list<string> lexerFromFile(const string &fileName, char delimiter) {
        std::ifstream t;
        int length;
        t.open(fileName);      // open input file
        t.seekg(0, std::ios::end);    // go to the end
        length = t.tellg();           // report location (this is the length)
        t.seekg(0, std::ios::beg);    // go back to the beginning
        char *buffer = new char[length];    // allocate memory for a buffer of appropriate dimension
        t.read(buffer, length);       // read the whole file into the buffer
        t.close();
        string s;
        for (int i = 0; i < length; ++i) {
            s += buffer[i];
        }
        return lexer(s, delimiter);
    }
};


#endif //UNTITLED_LEXER_H
