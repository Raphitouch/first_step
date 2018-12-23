

#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
private:
    Expression* left;
    Expression* right;
public:
    double calculate();
};

#endif //BINARYEXPRESSION_H
