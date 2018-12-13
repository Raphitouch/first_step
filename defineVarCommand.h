#include "Command.h"

#ifndef FIRST_STEP_DEFINEVARCOMMAND_H
#define FIRST_STEP_DEFINEVARCOMMAND_H

/** For command var we call to this class **/
/** This class will create a new hash option in the map symbolTable from parser. From string it will gate the variable
 * name that user ask for, and then will put in there value 0. The equal command will then bind the value with his
 * address in simulator **/
class defineVarCommand : public Command {

public:
    defineVarCommand(std::map<std::string, double> *symbolTable);
    virtual int execute(std::string order[]);
};

#endif //FIRST_STEP_DEFINEVARCOMMAND_H
