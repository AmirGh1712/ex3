#ifndef PARSER_H
#define PARSER_H


#include <map>
#include "Command.h"
#include <list>
#include "VariablesMap.h"
#include "ExpressionFactory.h"
#include "ExpressionReader.h"

using namespace std;
/**
 * Parssing the array of strings.
 * @param array the strings.
 * @param len the length.
 * @param map the commands map.
 * @param ef the expression factory.
 */
void parser(list<string> array, map<string, Command*> map, VariablesMap* vm, ExpressionFactory* ef);


#endif //PARSER_H
