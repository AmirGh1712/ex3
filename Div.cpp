#include "Div.h"
double Div::calculate() {
    if (this->rightEx->calculate() == 0)
        throw "division by zero";
    return this->leftEx->calculate() / this->rightEx->calculate();
}