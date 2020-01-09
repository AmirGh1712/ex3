#include "Plus.h"

double Plus::calculate() {
    return this->leftEx->calculate() + this->rightEx->calculate();
}