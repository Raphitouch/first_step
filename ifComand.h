#include "conditionParser.h"

#ifndef FIRST_STEP_IFCOMAND_H
#define FIRST_STEP_IFCOMAND_H

/** For sample condition we call to this class **/
class ifComand : public conditionParser {

public:
    virtual int execute(std::string order[]);
};

#endif //FIRST_STEP_IFCOMAND_H
