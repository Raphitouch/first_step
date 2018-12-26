using namespace std;
#include "ShuntingYard.h"
/* will get the string list of operator ordered by the shunting yard algorithm
 * will ***add*** to addToIndex parameter how much we need to advance*/
string* ShuntingYard::ShuntingYardAlgorithm(string *commands, int startIndex, int *addToIndex) {
    //raphael do here:
    string* arr; //to return. build like this: arr = new[parameter_size];
}
Expression* ShuntingYard::getExpressionHelper(string *operators) {
    Expression* rtr;
    Expression* left;
    Expression* right;
    string last = operators[operatorsArraySize];
    operatorsArraySize --;
    if(last.compare("+") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Plus(left,right);
    }
    else if(last.compare("-") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Minus(left,right);
    }
    else if(last.compare("*") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Mul(left,right);
    }
    else if(last.compare("/") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Div(left,right);
    }
    else if(last.compare(">") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new BiggerThen(left,right);
    }
    else if(last.compare("<") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new SmallerThen(left,right);
    }
    else if(last.compare(">=") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new BiggerAndEqualThen(left,right);
    }
    else if(last.compare("<=") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new SmallerAndEqualThen(left,right);
    }
    else if(last.compare("==") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new EqualThen(left,right);
    }
    else if(last.compare("!=") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new NotEqualThens(left,right);
    }
    else{//case the string is number(we checked all the operators)
        rtr = new Number(stod(last));
    }
    return rtr;
}
/*get expreesion object from the sorted string array from the shuntingYard Algo.
 * we go from the end of the array and build recursively (with helper method) - the right
 * binary expression, then left as explained in the lecture*/
Expression * ShuntingYard::getExpression(string *commands, int startIndex, int *addToIndex) {
    string* operators = ShuntingYardAlgorithm(commands,startIndex,addToIndex);
    //building Expression* object from shunting yard output
    Expression* rtr;
    Expression* left;
    Expression* right;
    string last = operators[operatorsArraySize-1];
    operatorsArraySize -= 2;//now its the one before last index of the operators array.
    if(last.compare("+") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Plus(left,right);
    }
    else if(last.compare("-") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Minus(left,right);
    }
    else if(last.compare("*") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Mul(left,right);
    }
    else if(last.compare("/") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new Div(left,right);
    }
    else if(last.compare(">") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new BiggerThen(left,right);
    }
    else if(last.compare("<") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new SmallerThen(left,right);
    }
    else if(last.compare(">=") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new BiggerAndEqualThen(left,right);
    }
    else if(last.compare("<=") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new SmallerAndEqualThen(left,right);
    }
    else if(last.compare("==") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new EqualThen(left,right);
    }
    else if(last.compare("!=") == 0){
        right = getExpressionHelper(operators);
        left = getExpressionHelper(operators);
        rtr = new NotEqualThens(left,right);
    }
    else{//case the string is number(we checked all the operators)
        rtr = new Number(stod(last));
    }
    delete[] operators;
    return rtr;
}
ShuntingYard::ShuntingYard(map<string, double> *symbolTable) {
    m_symbolTable = symbolTable;
}
