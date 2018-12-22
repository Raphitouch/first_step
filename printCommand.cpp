using namespace std;
#include "printCommand.h"

printCommand::printCommand(std::map<std::string, double> *symbolTable) {
    m_symbolTable = symbolTable;
}