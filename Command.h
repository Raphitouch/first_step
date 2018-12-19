#ifndef FIRST_STEP_INTERFACE_H
#define FIRST_STEP_INTERFACE_H

#include <string>
#include <map>
#include <list>

/** Abstract class Command **/
class Command{
public:
    //Execute methods will read the string and return how many index has been reed
    virtual int execute(std::string order[]) = 0;
    virtual ~Command() = 0;
};

#endif //FIRST_STEP_INTERFACE_H
