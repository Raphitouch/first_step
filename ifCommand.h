#include "conditionParser.h"

#ifndef FIRST_STEP_IFCOMAND_H
#define FIRST_STEP_IFCOMAND_H

/** For sample condition we call to this class **/
class ifCommand : public conditionParser {
public:
    ifCommand(std::map<std::string,double>* symbolTable);
    int execute(std::string* order,int startIndex);
};

#endif //FIRST_STEP_IFCOMAND_H