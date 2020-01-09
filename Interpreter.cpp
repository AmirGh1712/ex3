#include "Interpreter.h"

void Interpreter::setVariables(string variables) {
    string* sets;
    int count = this->divideToSets(variables, &sets);
    try {
        this->addVariables(count, sets);
    } catch (exception e) {
        delete(sets);
    }
    delete(sets);
}

int Interpreter::divideToSets(string variables, string** p) {
    int count = 0;
    int size = 5;
    string* sets = (string*) malloc(sizeof(string) * size);
    if (sets == nullptr) {
        throw MEMORY_ERROR;
    }
    string str = "";
    //Iterate for each character in the string.
    for (int i = 0; i < variables.length(); ++i) {
        if (variables[i] == ';') {
            if (count + 1 > size) {
                size *= 2;
                sets = (string*) realloc(sets, sizeof(string) * size);
                if (sets == nullptr) {
                    throw MEMORY_ERROR;
                }
            }
            sets[count] = str;
            count++;
            str = "";
        } else {
            str += variables[i];
        }
    }
    //Add the last one.
    if (count + 1 > size) {
        size++;
        sets = (string*) realloc(sets, sizeof(string) * size);
        if (sets == nullptr) {
            throw MEMORY_ERROR;
        }
    }
    sets[count] = str;
    count++;
    //Resize.
    sets = (string*) realloc(sets, sizeof(string) * count);
    if (sets == nullptr) {
        throw MEMORY_ERROR;
    }
    *p = sets;
    return count;
}

void Interpreter::addVariables(int count, string* sets) {
    for (int i = 0; i < count; ++i) {
        int j = 0;
        double value;
        string name = "";
        if (sets[i][j] >= '0' && sets[i][j] <= '9') {
            delete(sets);
            throw VARIABLES_ERROR;
        }
        //Find the name.
        while (j < sets[i].length()) {
            if (sets[i][j] == '=') {
                break;
            }
            if(!((sets[i][j] >= 'a' && sets[i][j] <= 'z') || (sets[i][j] >= 'A' && sets[i][j] <= 'Z')
                 || (sets[i][j] >= '0' && sets[i][j] <= '9') || sets[i][j] >= '_')) {
                delete(sets);
                throw VARIABLES_ERROR;
            }
            name += sets[i][j];
            j++;
        }
        //If there is no '='.
        if (j >= sets[i].length()) {
            delete(sets);
            throw VARIABLES_ERROR;
        }

        //Find the Value.
        char* sub = (char*)malloc(sizeof(char) * (sets[i].length() - j));
        if (sub == nullptr) {
            delete(sets);
            throw MEMORY_ERROR;
        }
        j++;
        int k = j;
        while (j < sets[i].length()) {
            sub[j-k] = sets[i][j];
            j++;
        }
        value = strtof(sub, nullptr);
        this->Vars[name] = new Variable(name, value);
        delete(sub);
    }
}

Expression *Interpreter::interpret(string str) {
    stack<Expression*> output;
    stack<char> operators;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') { //Num
            int size = 5;
            int l = 0;
            char* s = (char *)malloc(sizeof(char) * size);
            if (s == nullptr) {
                throw MEMORY_ERROR;
            }
            while (i < str.length()) {
                if(!((str[i] >= '0' && str[i] <= '9') || str[i] == '.')) {
                    break;
                }
                if(l + 1 > size) {
                    size *= 2;
                    s = (char *)realloc(s, sizeof(char) * size);
                    if (s == nullptr) {
                        throw MEMORY_ERROR;
                    }
                }
                s[l] = str[i];
                i++;
                l++;
            }
            i--;
            s = (char *)realloc(s, sizeof(char) * l);
            if (s == nullptr) {
                throw MEMORY_ERROR;
            }
            double value = strtod(s, nullptr);
            output.push(new Value(value));
            delete(s);
        } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_') { //Variable
            string s = "";
            while (i < str.length()) {
                if (!(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'
                    || (str[i] >= '0' && str[i] <= '9')) {
                    break;
                }
                s += str[i];
                i++;
            }
            i--;
            if (this->Vars[s] == nullptr) {
                throw VARIABLES_ERROR;
            }
            output.push(this->Vars[s]);
        } else if (str[i] == '+' || str[i] == '-') { // + / -
            if (i + 1  == str.length()) {
                throw VARIABLES_ERROR;
            }
            //Unary
            if (i != 0) {
                if (str[i - 1] == '(') {
                    if (str[i] == '+')
                        operators.push('p');
                    else if (str[i] == '-')
                        operators.push('m');
                    continue;
                }
            } else {
                if (str[i] == '+')
                    operators.push('p');
                else if (str[i] == '-')
                    operators.push('m');
                continue;
            }
            //Binary
            if (!operators.empty()) {
                char o = operators.top();
                while (o != ')' && o != '(') {
                    operators.pop();
                    addOperator(o, &output, operators);
                    if (operators.empty()) {
                        break;
                    }
                    o = operators.top();
                }
            }
            operators.push(str[i]);
        } else if (str[i] == '*' || str[i] == '/') { // * / /
            if (i + 1  == str.length()) {
                throw VARIABLES_ERROR;
            }
            if (!operators.empty()) {
                char o = operators.top();
                while (o == '*' || o == '/' || str[i] == 'm' || str[i] == 'p') {
                    operators.pop();
                    addOperator(o, &output, operators);
                    if (operators.empty()) {
                        break;
                    }
                    o = operators.top();
                }
            }
            operators.push(str[i]);
        } else if(str[i] == '(') {
            operators.push('(');
        } else if(str[i] == ')') { // close ()
            if (!operators.empty()) {
                char o = operators.top();
                while (o != '(') {
                    operators.pop();
                    addOperator(o, &output, operators);
                    if (operators.empty()) {
                        throw EXPRESSION_ERROR;
                    }
                    o = operators.top();
                }
                operators.pop();
            }
        } else {
            throw EXPRESSION_ERROR;
        }
    }
    //The last ones
    if (!operators.empty()) {
        char o = operators.top();
        while (!operators.empty()) {
            operators.pop();
            addOperator(o, &output, operators);
            if (operators.empty()) {
                break;
            }
            o = operators.top();
        }
    }
    return output.top();
}

void addOperator(char o, stack<Expression*> *output, stack<char> operators) {
    if (o == '+') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        if(output->empty()) {
            output->push(new UPlus(right));
            return;
        }
        Expression *left = output->top();
        if(left == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        output->push(new Plus(left, right));
    } else if (o == '-') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        if(output->empty()) {
            output->push(new UMinus(right));
            return;
        }
        Expression *left = output->top();
        if(left == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        output->push(new Minus(left, right));
    } else if (o == '*') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        Expression *left = output->top();
        if(left == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        output->push(new Mul(left, right));
    } else if (o == '/') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        Expression *left = output->top();
        if(left == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        output->push(new Div(left, right));
    } else if (o == 'p') {
        Expression *e = output->top();
        if(e == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        output->push(new UPlus(e));
    } else if (o == 'm') {
        Expression *e = output->top();
        if(e == nullptr) {
            throw VARIABLES_ERROR;
        }
        output->pop();
        output->push(new UMinus(e));
    }
}
