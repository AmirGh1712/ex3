#include <iostream>
#include "Parser.h"
#include "PrintCommand.h"
#include "ExpressionReader.h"
#include "ExpressionFactory.h"
#include "VariablesMap.h"
#include "VarCommand.h"
#include "SleepCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include <fstream>
#include "Lexer.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        throw "Error";
    }
    VariablesMap* vm = new VariablesMap();
    VariablesMap* svm = new VariablesMap();
    ExpressionFactory* ef = new ExpressionFactory(vm);

    map<string, Command*> map;
    PrintCommand* p = new PrintCommand(ef);
    SleepCommand* s = new SleepCommand(ef);
    IfCommand* i = new IfCommand(ef, &map, vm);
    WhileCommand* w = new WhileCommand(ef, &map, vm);
    OpenServerCommand* os = new OpenServerCommand(svm, ef);
    ConnectCommand* cc = new ConnectCommand(ef);
    VarCommand* vc = new VarCommand(svm, vm, ef, cc);

    map["Print"] = p;
    map["var"] = vc;
    map["Sleep"] = s;
    map["if"] = i;
    map["while"] = w;
    map["openDataServer"] = os;
    map["connectControlClient"] = cc;

    char* fileName = argv[1];

    std::ifstream t;
    int length;
    t.open(fileName);      // open input file
    t.seekg(0, std::ios::end);    // go to the end
    length = t.tellg();           // report location (this is the length)
    t.seekg(0, std::ios::beg);    // go back to the beginning
    char *buffer = new char[length];    // allocate memory for a buffer of appropriate dimension
    t.read(buffer, length);       // read the whole file into the buffer
    t.close();
    Lexer lexer;

    string str;
    list<string> arr;
    for (int j = 0; j < length; ++j) {
        if (buffer[j] != '\n') {
            str += buffer[j];
        } else {


            list<string> tmp = lexer.lexer(str, ' ');
            for (auto &st :tmp) {
                if (st != "" && st != " " && st != "\n" && st != "\t") {

                    arr.push_back(st);
                }

            }
            arr.push_back("\n");
            str = "";
        }
    }
    //last one

    list<string> tmp = lexer.lexer(str, ' ');
    for (auto &st :tmp) {
        if (st != "" && st != " " && st != "\n" && st != "\t") {

            arr.push_back(st);
        }

    }
    arr.push_back("\n");
    parser(arr, map, vm, ef);

    cc->join();
    os->join();

    delete(p);
    delete(s);
    delete(vc);
    delete(i);
    delete(w);
    delete(os);
    //delete(cc);
    delete(vm);
    delete(svm);
    delete(ef);
    return 0;
}