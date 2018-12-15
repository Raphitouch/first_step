using namespace std;
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <map>
#include <list>

/** Abstract class Command **/
class Command{
    public:
        //Execute methods will read the string and return how many index has been reed
        virtual int execute(string command);
        //virtual ~Command(){}
};

#endif //FIRST_STEP_INTERFACE_H
