using namespace std;
#include "Parser.h"
/*implementation for Parser header:*/

/*constructor to set the string array as member
 * and initalaize the map the contains mapping from string(name of command) to actual
 * command as object instance of Command.*/
Parser::Parser(Lexer* lexer) {
    this->commands = lexer->lex();
    this->arraySize = lexer->getNum();
    Command* osc = new openServerCommand(&varBind,&symbolTable, m);
    Command* cc = new connectCommand(&varBind,&symbolTable, m);
    Command* ecOnly = new equalCommand(&varBind,&symbolTable, cc);
    Command* vcWithOrWithoutec = new varCommand(&varBind,&symbolTable, cc);
    Command* cpIf = new conditionParser(&symbolTable,&varBind,false,cc);
    Command* cpWhile = new conditionParser(&symbolTable,&varBind,true,cc);
    Command* pc = new printCommand(&symbolTable);
    Command* exitc = new exitCommand();
    Command* sl = new sleepCommand();
    this->StrToCommand.insert({"openDataServer",osc});
    this->StrToCommand.insert({"connect",cc});
    this->StrToCommand.insert({"=",ecOnly});
    this->StrToCommand.insert({"var",vcWithOrWithoutec});
    this->StrToCommand.insert({"if",cpIf});
    this->StrToCommand.insert({"while",cpWhile});
    this->StrToCommand.insert({"print",pc});
    this->StrToCommand.insert({"exit",exitc});
    this->StrToCommand.insert({"sleep",sl});
}
/*the parse method will go to the current index(member of Parse class) and will get the current command
 * from the member string array in that index. it will add to the index for the next command acoordingly
 * we get the adding to the index from the execution command that will be invoked.
 * if the command is not valid(object is null we will throw exception).*/
void Parser::parse() {
    while(this->index < this->arraySize){//check for commands:
        string str = this->commands[this->index];
        map<string,Command*>::iterator it;
        it = this->StrToCommand.find(str);
        Command* c;
        if(it != this->StrToCommand.end()){
            c = it->second;
            this->index += c->execute(this->commands,this->index);
        }
        else{//check for rest commands: invalid command or = command
            if(this->index +1 >= this->commands->size() || this->commands[this->index +1].compare("=") != 0){
                throw invalid_argument("not a valid command!");
            }
            else{//its = command
                it = this->StrToCommand.find("=");
                c = it->second;
                this->index += c->execute(this->commands,this->index);
            }
        }
    }
}
/* getters:*/
map<string,double> Parser::getSymbolTable() {
    return this->symbolTable;
}
map<string,string> Parser::getVarBind() {
    return this->varBind;
}
/*destructor for cleaning memory:*/
Parser::~Parser() {
    delete[] this->commands;
    this->StrToCommand.clear();
    this->symbolTable.clear();
    this->varBind.clear();
}