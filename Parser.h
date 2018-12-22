/*the parser module that getes the lexed script and parses it to
 * commands to be sent to execute(if its a valid command):*/

#ifndef Parser_H
#define Parser_H

#include "Lexer.h"
#include <map>
#include <stdexcept>
#include "openServerCommand.h"
#include "varCommand.h"
#include "printCommand.h"
#include "loopCommand.h"
#include "ifCommand.h"
#include "connectCommand.h"
class Parser{
private:
    int arraySize;//the size of array from the lexer
    int index = 0;//start reading from here
    string* commands;//we get from lexer
    map<string,double> symbolTable;//all the varibales with their values; 0 for default(without set)
    map<string,string> varBind;//all the bound variables with their address in the simulator
    map<string,Command*> StrToCommand;//map of all commands avaliable from their string to actual object.
public:
    Parser(Lexer* lexer);
    ~Parser();
    void parse();
    map<string,string> getVarBind();
    map<string,double> getSymbolTable();
};


#endif //Parser_H