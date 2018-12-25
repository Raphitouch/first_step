using namespace std;
#include "ShuntingYard.h"
/* will get the string list of operator ordered by the shunting yard algorithm
 * will ***add*** to addToIndex parameter how much we need to advance*/
list<string> ShuntingYard::ShuntingYardAlgorithm(std::string *commands, int startIndex, int *addToIndex) {
    //raphael do here:
}
Expression * ShuntingYard::getExpression(std::string *commands, int startIndex, int *addToIndex) {
    list<string> operators = ShuntingYardAlgorithm(commands,startIndex,addToIndex);
    //building Expression* object from shunting yard output
    Expression* rtr;
    for(list<string>::reverse_iterator rit=operators.rbegin(); rit!=operators.rend(); ++rit)
        if((*rit).compareTo("+") == 0) {

        }
    }



    return rtr;
}
ShuntingYard::ShuntingYard(std::map<std::string, double> *symbolTable) {
    m_symbolTable = symbolTable;
}
