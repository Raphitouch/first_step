

#ifndef NOTEQUALTHEN_H
#define NOTEQUALTHEN_H

#include "BinaryExpression.h"
class NotEqualThen : public BinaryExpression{
public:
    NotEqualThen(Expression* left,Expression* right);
    double calculate();
    ~NotEqualThen(){}
};

#endif //NOTEQUALTHEN_H
