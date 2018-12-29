#include "openServerCommand.h"

using namespace std;

openServerCommand::openServerCommand(std::map<std::string, double> *symbolTable,
                                     std::map<std::string, std::string> *varAddresses) : symbolTable(symbolTable),
                                     varAddresses(varAddresses){
    data = new DataReaderServer();
}

int openServerCommand::execute(std::string order[], int index) {
    cout << "Waiting for connection from simulator" << endl;
    thread thread1(&DataReaderServer::execution, data, symbolTable, varAddresses, stoi(order[index+1]));
    thread1.detach();
    sleep(10000);
    return 3;
}