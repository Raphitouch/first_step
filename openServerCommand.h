#include <pthread.h>
#include <chrono>
#include "Command.h"
#include "DataReaderServer.h"

#ifndef FIRST_STEP_OPENSERVERCOMMAND_H
#define FIRST_STEP_OPENSERVERCOMMAND_H

/** For command Open Data Server we call to this class **/
/** The server opener will receive a pointer to both parser map : map symbol table which contains variables names
 * and their value.
 * Map varAddresses which contains variables names and their "bind" addresses in the simulator**/

class openServerCommand : public Command {
    std::map<std::string, double> *symbolTable;
    std::map<std::string,std::string> *varAddresses;

public:
    openServerCommand(std::map<std::string, double> *symbolTable, std::map<std::string,std::string> *varAddresses);
    virtual int execute(std::string order[], int index);
};

#endif //FIRST_STEP_OPENSERVERCOMMAND_H
