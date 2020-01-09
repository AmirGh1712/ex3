#include "Minus.h"

double Minus::calculate() {
    return this->leftEx->calculate() - this->rightEx->calculate();
}