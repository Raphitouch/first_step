#include "equalCommand.h"

using namespace std;

equalCommand::equalCommand(std::map<std::string, double> *symbolTable, std::map<std::string, std::string> *varAddresses)
        : varAddresses(varAddresses), symbolTable(symbolTable) {

}

int equalCommand::execute(std::string *commands, int startIndex) {
    // if we need to bind with an address / another variable
    if (commands[startIndex+1] == "bind"){
        return bindCommand(commands, startIndex);
    }
    // if it's an expression
    else { return regularEqual(commands, startIndex); }
}

int equalCommand::bindCommand(std::string *commands, int startIndex) {
    string str = (commands[startIndex+2]);
    // in case that the first character is " we need to bind the variable with an addresse
    if (str[0] == '"'){
        (*varAddresses)[commands[startIndex-1]] = commands[startIndex+2];
    } else { // in this case, the bind is with an another variable
        (*varAddresses)[commands[startIndex+2]] = commands[startIndex-1];
        (*varAddresses)[commands[startIndex-1]] = commands[startIndex+2];
        (*symbolTable)[commands[startIndex-1]] = (*symbolTable)[commands[startIndex+2]];
    }
    return 3;
}

int equalCommand::regularEqual(std::string *commands, int startIndex) {
    int addToIndex = 1;
    ShuntingYard* sh = new ShuntingYard(m_symbolTable);//shunting yard object with the current symbolTable
    Expression* exp = sh->getExpression(commands,startIndex+1,&addToIndex);//we get the expression from the shunting yard object that reads the expression from the array(and updates addToIndex to  how much we need to advance the array)
    double pass = exp->calculate();//gets us the value of the expression object.
    delete exp;
    delete sh;
    (*symbolTable)[commands[startIndex-1]] = pass;
    return addToIndex;
}