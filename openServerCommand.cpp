#include "openServerCommand.h"

openServerCommand::openServerCommand(std::map<std::string, double> *symbolTable,
                                     std::map<std::string, std::string> *varAddresses) : symbolTable(symbolTable),
                                     varAddresses(varAddresses){
}

int openServerCommand::execute(std::string *order, int index) {
    DataReaderServer data;
    struct MyParams* params = new MyParams();
    params->varAddress = this->varAddresses;
    params->symbolTable = this->symbolTable;
    pthread_t trid;
    pthread_start(&trid, nullptr, (data.execution), params);

    return 3;
}