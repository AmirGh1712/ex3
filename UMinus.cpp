#include "UMinus.h"
double UMinus :: calculate() {
    return -(this->e->calculate());
}