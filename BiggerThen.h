

#ifndef BIGGERTHEN_H
#define BIGGERTHEN_H

#include "BinaryExpression.h"
class BiggerThen : public BinaryExpression{
public:
    BiggerThen(Expression* left,Expression* right);
    double calculate();
};

#endif //BIGGERTHEN_H
