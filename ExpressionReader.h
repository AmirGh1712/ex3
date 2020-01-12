#ifndef EXPRESSION_READER_H
#define EXPRESSION_READER_H

#include <list>
#include <string>
#include <iostream>

using namespace std;
/**
 * Main class for reading an expression from string.
 */
class ExpressionReader {
public:
    /**
     * Create a list of string for the strings of the expresion.
     * @param it the iterator to start checking from the original list.
     * @param end iterator for the end of the original list.
     * @return the new list.
     */
    list<string> getExpressions(list<string>::iterator &it, list<string>::iterator &end);
};
/**
 * Returns if a string is an operator.
 * @param it the iterator to the string.
 * @return if a string is an operator.
 */
bool isOperator(const list<string>::iterator &it);

#endif //EXPRESSION_READER_H
