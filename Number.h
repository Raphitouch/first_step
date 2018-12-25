

#ifndef NUMBER_H
#define NUMBER_H
/**this is the expression in case of a number value to be calculated*/
#include "Expression.h"
class Number : public Expression{
private:
    double m_number;
public:
    double calculate();
    Number(double number);
};

#endif //NUMBER_H
