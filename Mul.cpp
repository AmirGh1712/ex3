#include "Mul.h"

double Mul::calculate() {
    return this->leftEx->calculate() * this->rightEx->calculate();
}