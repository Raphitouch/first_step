

#ifndef NOTEQUALTHEN_H
#define NOTEQUALTHEN_H

#include "BinaryExpression.h"
class NotEqualThen : public BinaryExpression{
public:
    NotEqualThen(Expression* left,Expression* right);
    double calculate();
};

#endif //NOTEQUALTHEN_H
