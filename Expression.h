
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

/** */
class Expression{
private:
    int isNumber = 0;
    double number;
public:
    int getIsNumber(){return isNumber;}
    double getNumber(){return number;}
    virtual double calculate() = 0;
};

#endif //EXPRESSION_H
