#include "Variable.h"

double Variable::calculate() {
    return this->value;
}

Variable& Variable::operator++() {
    this->value++;
    return *this;
}

Variable& Variable::operator--() {
    this->value--;
    return *this;
}
Variable& Variable::operator+=(const double &num) {
    this->value+=num;
    return *this;
}
Variable& Variable::operator-=(const double &num) {
    this->value-=num;
    return *this;
}
Variable& Variable::operator++(int) {
    this->value++;
    return *this;
}
Variable& Variable::operator--(int) {
    this->value--;
    return *this;
}
void Variable::set(double v) {
    this->value = v;
}
