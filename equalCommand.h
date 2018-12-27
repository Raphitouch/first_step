#include "Command.h"
#include "ShuntingYard.h"
#include "connectCommand.h"

#ifndef FIRST_STEP_EQUALCOMMAND_H
#define FIRST_STEP_EQUALCOMMAND_H


class equalCommand : public Command {
    std::map<std::string, double> *symbolTable;
    std::map<std::string,std::string> *varAddresses;

    int bindCommand(std::string* commands,int startIndex);
    int regularEqual(std::string* commands,int startIndex);

public :
    equalCommand(std::map<std::string, double> *symbolTable, std::map<std::string,std::string> *varAddresses,
                 connectCommand* cc);
    virtual int execute(std::string* commands,int startIndex);
    virtual ~equalCommand(){}
};


#endif //FIRST_STEP_EQUALCOMMAND_H