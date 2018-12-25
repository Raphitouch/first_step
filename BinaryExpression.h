

#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
private:
    //expressions from both sides of the operator
    Expression* m_left;
    Expression* m_right;
public:
    BinaryExpression(Expression* left,Expression* right);
    virtual double calculate() = 0;
};

#endif //BINARYEXPRESSION_H
