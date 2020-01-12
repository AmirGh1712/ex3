
#ifndef COMMAND_H
#define COMMAND_H

#include <mutex>
#include <string>
#include <iostream>
#include <list>

using namespace std;

// the mutex of every command
static mutex m;
/**
 * The main class of command.
 */
class Command {

public:
    /**
     * locks every command.
     */
    static void lock() {
        m.lock();
    }
    /**
     * unlock every command.
     */
    static void unlock() {
        m.unlock();
    }
    /**
     * Execute the command.
     * @param place the iterator of the command in the list of strings.
     * @param end the end iterator of the list.
     * @return
     */
    virtual int execute(list<string>::iterator place, list<string>::iterator end) = 0;
    /**
     * Destructor.
     */
    virtual ~Command() {}
};
/**
 * Check if the string has "".
 * @param str the string.
 * @return the string without the "".
 */
string checkString(string str);
/**
 * Convert a string to int.
 * @param str the string.
 * @return the number.
 */
int strToInt(string str);

#endif //COMMAND_H
