#include "Command.h"

#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

class printCommand : public Command {
private:
    std::map<std::string,double>* m_symbolTable;//all the varibales with their values; 0 for default(without set)
public:
    printCommand(std::map<std::string,double>* symbolTable);
    int execute(std::string* order,int startIndex);
};

#endif //PRINTCOMMAND_H