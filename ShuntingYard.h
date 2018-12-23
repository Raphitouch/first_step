
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
class ShuntingYard{
private:
    std::map<std::string,double>* m_symbolTable;//all the varibales with their values; 0 for default(without set)
    list<std::string> ShuntingYardAlgorithm(std::string* commands,int startIndex,int* addToIndex);
public:
    ShuntingYard(std::map<std::string,double>* symbolTable);
    Expression* getExpression(std::string* commands,int startIndex,int* addToIndex);
};

#endif SHUNTINGYARD_H
