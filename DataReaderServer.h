#include <map>
#include <list>
#include <string>

#ifndef FIRST_STEP_DATAREADERSERVER_H
#define FIRST_STEP_DATAREADERSERVER_H


class DataReaderServer {
    std::map<std::string, double> dataReceived;
    std::vector<std::string> insertOrder;

public:
    DataReaderServer();
    void execution (std::map<std::string, double> *symbolTable, std::map<std::string,std::string> *varAddresses);
    void actualizeData(std::map<std::string, double> *symbolTable, std::map<std::string,std::string> *varAddresses);
};


#endif //FIRST_STEP_DATAREADERSERVER_H
