
#ifndef SLEEPCOMMAND_H
#define SLEEPCOMMAND_H

#include <thread>
#include <chrono>
#include "Command.h"
class sleepCommand : public Command{
public:
    int execute(std::string* commands,int startIndex);
    ~sleepCommand(){}
};

#endif //SLEEPCOMMAND_H