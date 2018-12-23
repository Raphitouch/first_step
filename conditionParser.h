#include "varCommand.h"
#include "printCommand.h"
#include "connectCommand.h"
#include "openServerCommand.h"
#ifndef FIRST_STEP_CONDITIONPARSER_H
#define FIRST_STEP_CONDITIONPARSER_H

/** Condition Parser is parent class for both If and Loop **/
class conditionParser : public Command {
private:
    std::map<std::string,double>* m_symbolTable;//all the varibales with their values; 0 for default(without set)
    std::map<std::string,std::string>* m_varBind;//all the bound variables with their address in the simulator
    std::list<Command*> commandsList; //List of commands we need to execute in case condition is true
    bool m_isWhile;//true iff this object represents while loop, 0 - if

public:
    conditionParser(std::map<std::string,double>* symbolTable,std::map<std::string,std::string>* varBind,bool isWhile);
    int execute(std::string* commands,int startIndex);
    ~conditionParser();
};

#endif //FIRST_STEP_CONDITIONPARSER_H