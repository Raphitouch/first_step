

#ifndef MINUS_H
#define MINUS_H

#include "BinaryExpression.h"
class Minus : public BinaryExpression{
public:
    Minus(Expression* left,Expression* right);
    double calculate();
};

#endif //MINUS_H
