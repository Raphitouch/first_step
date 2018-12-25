

#ifndef PLUS_H
#define PLUS_H

#include "BinaryExpression.h"
class Plus : public BinaryExpression{
public:
    Plus(Expression* left,Expression* right);
    double calculate();
};

#endif //PLUS_H
