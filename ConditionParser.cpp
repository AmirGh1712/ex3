//
// Created by iddo on 02/01/2020.
//

#include "ConditionParser.h"
double ConditionParser::checkBoolExpression(list<string> leftExpression, std::string boolOperator, list<string> rightExpression) {
    ExpressionFactory factory = ExpressionFactory();
    Expression *leftExpr = factory.create(leftExpression);
    Expression *rightExpr = factory.create(rightExpression);
    Expression *boolExpression = new BoolExpression(leftExpr, boolOperator, rightExpr);
    double result = boolExpression->calculate();
    delete boolExpression;
    return result;
}
