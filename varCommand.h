
#ifndef FIRST_STEP_VARCOMMAND_H
#define FIRST_STEP_VARCOMMAND_H

#include "Command.h"
#include "connectCommand.h"
#include "equalCommand.h"

/** For command var we call to this class **/
/** This class will create a new hash option in the map symbolTable from parser. From string it will gate the variable
 * name that user ask for, and then will put in there value 0. The equal command will then bind the value with his
 * address in simulator **/
class varCommand : public Command {
    std::map<std::string, double> *symbolTable;
    std::map<std::string,std::string> *varAddresses;
    connectCommand* cc;
    equalCommand* equal;

    int executeWithEqual(std::string* commands,int startIndex);
    int executeWithoutEqual(std::string* commands,int startIndex);

public:
    varCommand(std::map<std::string, double> *symbolTable, std::map<std::string,std::string> *varAddresses,
            connectCommand* cc);
    virtual int execute(std::string* commands,int startIndex);
    virtual ~varCommand(){
        delete equal;
    }
};


#endif //FIRST_STEP_VARCOMMAND_H
