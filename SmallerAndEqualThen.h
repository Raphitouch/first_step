

#ifndef SMALLERANDEQUALTHEN_H
#define SMALLERANDEQUALTHEN_H

#include "BinaryExpression.h"
class SmallerAndEqualThen : public BinaryExpression{
public:
    SmallerAndEqualThen(Expression* left,Expression* right);
    double calculate();
};

#endif //SMALLERANDEQUALTHEN_H
