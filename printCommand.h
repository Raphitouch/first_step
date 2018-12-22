#include "Command.h"

#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

class printCommand : public Command {

public:
    int execute(string* order,int currentIndex);
};

#endif //PRINTCOMMAND_H