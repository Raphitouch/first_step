#include "Command.h"

#ifndef FIRST_STEP_CONNECTCOMMAND_H
#define FIRST_STEP_CONNECTCOMMAND_H

/** For command connect we call to this class **/
/** Connect Command will send to simulator the value we want to modify. It will get the variable address and the value
 * we want the simulator to modify.**/
class connectCommand : public Command {

public:
    connectCommand(std::string varAddress, double value);
    virtual int execute(std::string order[]);
};

#endif //FIRST_STEP_CONNECTCOMMAND_H
