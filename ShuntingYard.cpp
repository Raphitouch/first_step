using namespace std;
#include "ShuntingYard.h"

list<string> ShuntingYard::ShuntingYardAlgorithm(std::string *commands, int startIndex, int *addToIndex) {
    //raphael do here:
}
Expression * ShuntingYard::getExpression(std::string *commands, int startIndex, int *addToIndex) {
    list<string> operators = ShuntingYardAlgorithm(commands,startIndex,addToIndex);
    for(list<string>::reverse_iterator rit=operators.rbegin(); rit!=operators.rend(); ++rit){

    }
}

ShuntingYard::ShuntingYard(std::map<std::string, double> *symbolTable) {
    m_symbolTable = symbolTable;
}
