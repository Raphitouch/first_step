

#ifndef MUL_H
#define MUL_H

#include "BinaryExpression.h"
class Mul : public BinaryExpression{
public:
    Mul(Expression* left,Expression* right);
    double calculate();
    ~Mul(){}
};

#endif //MUL_H
