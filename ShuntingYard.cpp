using namespace std;
#include "ShuntingYard.h"
// function that will check if current character is an operator
bool ShuntingYard::isoperator(string str){
    return str == "+" || str == "-" || str == "*" || str == "/";
}
// function that will check if current character is a command, which mean that shunting yard needs to stop
bool ShuntingYard::iscommand(string str){
    return str == "var" || str == "openDataServer" || str == "connect" || str == "if" || str == "while" || str == "print"
           || str == "exit" || str == "sleep" || str == "=";
}

/* will get the string list of operator ordered by the shunting yard algorithm
 * will ***add*** to addToIndex parameter how much we need to advance*/
string* ShuntingYard::ShuntingYardAlgorithm(string *commands, int startIndex, int *addToIndex) {
    stack<string> oper;
    string str;
    // First we check how long is the expression we want to order
    int j = 0;
    while (!iscommand(commands[startIndex + j + 1]) && (commands[startIndex + j + 1] != "}") &&
           !(commands[startIndex+j+1].empty())) {
        j++;
    }
    if (commands[startIndex + j + 1] == "="){
        j--;
    }
    (*addToIndex) = j;
    operators = new string[2*j];
    int indexOpe = 0;

    // now we have to order the expression
    for (int i = 0 ; i <= j ; i++) {
        // In case we have )
        if (commands[startIndex + i] == ")") {
            // Pop all operators from stack until we find (
            while (!(oper.empty())) {
                str = oper.top();
                oper.pop();
                if (str == "(") { break; }
                else {
                    operators[indexOpe] = str;
                    indexOpe++;
                }
            }
        } else if (isoperator(commands[startIndex + i]) || commands[startIndex + i] == "(") {
            if (commands[startIndex + i] == "-"){
                if (i == 0 || isoperator(commands[startIndex]) || commands[startIndex] == "(") {
                    operators[indexOpe] = "0";
                    indexOpe++;
                }
            }
            if (order[commands[startIndex + i]] == 1) {
                while (!oper.empty() && order[oper.top()] == 2) {
                    str = oper.top();
                    oper.pop();
                    operators[indexOpe] = str;
                    indexOpe++;
                }
            }
            oper.push(commands[startIndex + i]);
        } else {
            auto itr = (*m_symbolTable).find(commands[startIndex + i]);
            if (itr != (*m_symbolTable).end()) {
                operators[indexOpe] = to_string((*m_symbolTable)[commands[startIndex + i]]);
                indexOpe++;
            } else {
                operators[indexOpe] = commands[startIndex + i];
                indexOpe++;
            }
        }
    }
    while (!(oper.empty())) {
        str = oper.top();
        oper.pop();
        operators[indexOpe] = str;
        indexOpe++;
    }

    operatorsArraySize = indexOpe;
    return operators;
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