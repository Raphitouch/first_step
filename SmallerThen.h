
#ifndef SMALLTHEN_H
#define SMALLTHEN_H

#include "BinaryExpression.h"
class SmallerThen : public BinaryExpression{
public:
    SmallerThen(Expression* left,Expression* right);
    double calculate();
};

#endif //SMALLTHEN_H
