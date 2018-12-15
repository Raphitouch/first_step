/*the parser module that getes the lexed script and parses it to
 * commands to be sent to execute(if its a valid command):*/

#ifndef Parser_H
#define Parser_H

#include "Lexer.h"
#include "Command.h"
#include <map>
#include <stdexcept>

class Parser{
    private:
        int index = 0;//start reading from here
        string* commands;//we get from lexer
        map<string,Command> StrToCommand;//map of all commands avaliable from their string to actual object.
    public:
        Parser(Lexer* lexer);
        ~Parser();
        void parse();
};


#endif //Parser_H