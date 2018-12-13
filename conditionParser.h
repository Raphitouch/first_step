#include "Command.h"

#ifndef FIRST_STEP_CONDITIONPARSER_H
#define FIRST_STEP_CONDITIONPARSER_H

/** Condition Parser is parent class for both If and Loop **/
class conditionParser : public Command {
    std::list<Command> commands; //List of commands we need to execute in case condition is true

public:
    virtual int execute(std::string order[]);
};

#endif //FIRST_STEP_CONDITIONPARSER_H
