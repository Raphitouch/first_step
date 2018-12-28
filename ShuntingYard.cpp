using namespace std;
#include "ShuntingYard.h"
/* will get the string list of operator ordered by the shunting yard algorithm
 * will ***add*** to addToIndex parameter how much we need to advance*/
string* ShuntingYard::ShuntingYardAlgorithm(string *commands, int startIndex, int *addToIndex) {
    stack<string> oper;
    int j = 0;
    while (!iscommand(commands[startIndex + j + 1])) {
        j++;
    }
    if (commands[startIndex + j + 1] == "="){
        j--;
    }
    addToIndex = j;
    string operators[j+1];
    for (int i = 0 ; i < j ; i++) {

    }

    string* arr; //to return. build like this: arr = new[parameter_size];
}

// function that will check if current character is an operator
bool Shunting_yard::isoperator(string str){
    return c == "+" || c == "-" || c == "*" || c == "/";
}
// function that will check if current character is a command, which mean that shunting yard needs to stop
bool Shunting_yard::iscommand(string str){
    return c == "var" || c == "openDataServer" || c == "connect" || c == "if" || c == "while" || c = "print" ||
            c = "exit" || c = "sleep" || c == "=";
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