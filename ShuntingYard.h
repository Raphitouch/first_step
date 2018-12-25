
#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <string>
#include <list>
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "EqualThen.h"
#include "BiggerAndEqualThen.h"
#include "SmallerAndEqualThen.h"
#include "NotEqualThen.h"
#include "BiggerThen.h"
#include "SmallerThen.h"
/**this class will implement shunting yard algorithm-that returns the expression ordered
 * for the build of the expression object that implements the math calculation needed.
 * the expression object will be returned to be used for calculations.*/
class ShuntingYard{
private:
    std::map<std::string,double>* m_symbolTable;//all the varibales with their values; 0 for default(without set)
    list<std::string> ShuntingYardAlgorithm(std::string* commands,int startIndex,int* addToIndex);
public:
    ShuntingYard(std::map<std::string,double>* symbolTable);
    Expression* getExpression(std::string* commands,int startIndex,int* addToIndex);
    ~ShuntingYard(){}
};

#endif SHUNTINGYARD_H
