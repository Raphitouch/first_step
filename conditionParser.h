#include "Command.h"

#ifndef FIRST_STEP_CONDITIONPARSER_H
#define FIRST_STEP_CONDITIONPARSER_H

/** Condition Parser is parent class for both If and Loop **/
class conditionParser : public Command {
private:
    std::map<std::string,double>* m_symbolTable;//all the varibales with their values; 0 for default(without set)
    std::list<Command*> commands; //List of commands we need to execute in case condition is true

public:
    conditionParser(std::map<std::string,double>* symbolTable);
    virtual int execute(std::string* commands,int startIndex);
    virtual ~conditionParser(){}
};

#endif //FIRST_STEP_CONDITIONPARSER_H