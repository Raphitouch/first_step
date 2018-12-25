#include "varCommand.h"

varCommand::varCommand(std::map<std::string, double> *symbolTable, std::map<std::string, std::string> *varAddresses) :
varAddresses(varAddresses), symbolTable(symbolTable){

}

// This function just add a new variable into symbol Table and gives it 0 value
// Returns 2 because it used only var command and variable name
int varCommand::execute(std::string *commands, int startIndex) {
    (*symbolTable)[(startIndex+1)] = 0;
    return 2;
}