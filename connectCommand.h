#include "Command.h"
#include <mutex>

#ifndef FIRST_STEP_CONNECTCOMMAND_H
#define FIRST_STEP_CONNECTCOMMAND_H

/** For command connect we call to this class **/
/** Connect Command will send to simulator the value we want to modify. It will get the variable address and the value
 * we want the simulator to modify.**/
class connectCommand : public Command {
    std::mutex* m;
    int port;
    std::string address;

public:
    connectCommand(std::string varAddress, double value, std::mutex* m);
    virtual int execute(std::string order[]);
    void set(std::string address, double value);
};

#endif //FIRST_STEP_CONNECTCOMMAND_H
