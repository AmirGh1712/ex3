#include "ExpressionFactory.h"


bool ExpressionFactory::isNum(string &token) {
    bool checkNegative = 0;
    bool showDot = 0;
    for (unsigned int i = 0; i < token.length(); i++) {
        if (!checkNegative) {
            checkNegative = 1;
            if (token[i] == '-' && token.length() > 1)
                continue;
        }
        if (isdigit(token[i])) {
            continue;
        } else if (token[i] == '.' && !showDot) {
            showDot = true;
            continue;
        } else
            return false;
    }
    return true;
}

bool ExpressionFactory::isVar(string &token) {
    return this->vm->isExists(token);
}

Expression *ExpressionFactory::create(list<string> tokens) {
    stack<Expression*> output;
    stack<char> operators;
    for (list<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
        if (isNum(*it)) {
            //for number
            char *s = (char *) malloc(sizeof(char) * (*it).length());
            if (s == nullptr) {
                throw MEMORY_ERROR;
            }
            for (unsigned int i = 0; i < (*it).length(); ++i) {
                s[i] = (*it)[i];
            }
            double value = stod(s);
            output.push(new Value(value));
            delete(s);
        } else if(isVar(*it)) {
            //for variable
            output.push(this->vm->getVar(*it));
        } else if ((*it) == "+" || (*it) == "-") {
            //for + and -
            if (std::next(it,1)  == tokens.end()) {
                throw EXPRESSION_ERROR;
            }
            //Unary
            if (it != tokens.begin()) {
                if ((*(prev(it, 1))) == "(") {
                    if ((*it) == "+")
                        operators.push('p');
                    else if ((*it) == "-")
                        operators.push('m');
                    continue;
                }
            } else {
                if (*it == "+")
                    operators.push('p');
                else if (*it == "-")
                    operators.push('m');
                continue;
            }
            //Binary
            if (!operators.empty()) {
                char o = operators.top();
                while (o != ')' && o != '(') {
                    operators.pop();
                    addOperator(o, &output);
                    if (operators.empty()) {
                        break;
                    }
                    o = operators.top();
                }
            }
            operators.push((*it)[0]);
        } else if ((*it) == "*" || (*it) == "/") {
            //for * and /
            if (std::next(it,1)  == tokens.end()) {
                throw EXPRESSION_ERROR;
            }
            if (!operators.empty()) {
                char o = operators.top();
                while (o == '*' || o == '/' || o == 'm' || o == 'p') {
                    operators.pop();
                    addOperator(o, &output);
                    if (operators.empty()) {
                        break;
                    }
                    o = operators.top();
                }
            }
            operators.push((*it)[0]);
        } else if((*it) == "(") {
            operators.push('(');
        } else if((*it) == ")") { // close ()
            if (!operators.empty()) {
                char o = operators.top();
                while (o != '(') {
                    operators.pop();
                    addOperator(o, &output);
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
            addOperator(o, &output);
            if (operators.empty()) {
                break;
            }
            o = operators.top();
        }
    }
    return output.top();
}

void addOperator(char o, stack<Expression*> *output) {
    if (o == '+') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        if(output->empty()) {
            output->push(new UPlus(right));
            return;
        }
        Expression *left = output->top();
        if(left == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        output->push(new Plus(left, right));
    } else if (o == '-') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        if(output->empty()) {
            output->push(new UMinus(right));
            return;
        }
        Expression *left = output->top();
        if(left == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        output->push(new Minus(left, right));
    } else if (o == '*') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        Expression *left = output->top();
        if(left == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        output->push(new Mul(left, right));
    } else if (o == '/') {
        Expression *right = output->top();
        if(right == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        Expression *left = output->top();
        if(left == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        output->push(new Div(left, right));
    } else if (o == 'p') {
        Expression *e = output->top();
        if(e == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        output->push(new UPlus(e));
    } else if (o == 'm') {
        Expression *e = output->top();
        if(e == nullptr) {
            throw EXPRESSION_ERROR;
        }
        output->pop();
        output->push(new UMinus(e));
    }
}