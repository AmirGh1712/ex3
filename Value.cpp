#include "Value.h"

Value::Value(double v) {
    this->val = v;
}

double Value::calculate()  {
    return this->val;
}