#include "conditionParser.h"

#ifndef FIRST_STEP_IFCOMAND_H
#define FIRST_STEP_IFCOMAND_H

/** For sample condition we call to this class **/
class ifCommand : public conditionParser {

public:
    int execute(string* order,int currentIndex);
};

#endif //FIRST_STEP_IFCOMAND_H