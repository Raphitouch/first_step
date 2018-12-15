#include "Parser.h"
/*implementation for Parser header:*/

/*constructor to set the string array as member
 * and initalaize the map the contains mapping from string(name of command) to actual
 * command as object instance of Command. if there is no such commant the string
 * will be mapped to Null object.*/
Parser::Parser(Lexer* lexer) {
    this->commands = lexer->lex();
    this->index = lexer->getNum();
}
/*the parse method will go to the current index(member of Parse class) and will get the current command
 * from the member string array in that index. it will add to the index for the next command acoordingly
 * we get the adding to the index from the execution command that will be invoked.
 * if the command is not valid(object is null we will throw exception).*/
void Parser::parse() {

}
/*destructor for cleaning memory:*/
Parser::~Parser() {
    delete[] this->commands;
    this->StrToCommand.clear();
}