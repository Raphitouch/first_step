#include "Command.h"

#ifndef FIRST_STEP_CONDITIONPARSER_H
#define FIRST_STEP_CONDITIONPARSER_H

/** Condition Parser is parent class for both If and Loop **/
class conditionParser : public Command {
private:
    list<Command*> commands; //List of commands we need to execute in case condition is true

public:
    virtual int execute(string* order,int currentIndex);
    virtual ~conditionParser();
};

#endif //FIRST_STEP_CONDITIONPARSER_H