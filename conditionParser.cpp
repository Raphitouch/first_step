using namespace std;
#include "conditionParser.h"
conditionParser::conditionParser(std::map<std::string, double> *symbolTable,
                                 std::map<std::string, std::string> *varBind, bool isWhile) {
    m_symbolTable = symbolTable;
    m_isWhile = isWhile;
    m_varBind = varBind;
}
int conditionParser::execute(string *commands, int startIndex) {
    int addToIndex = 1;
    startIndex ++;//advance to the boolean expression
    int constBooleanStartIndex = startIndex;//place where boolean starts
    int dummyAddToIndex = addToIndex;
    Expression* exp = new Expression(&m_symbolTable);
    bool pass = exp->boolEvaluate(commands,startIndex,&addToIndex);
    startIndex += addToIndex;//gets startIndex one after '{'
    addToIndex ++;//represnting number of addes to get one after '{'
    int firstStartIndex = startIndex;//for while loop
    if(pass){
        /*making list of commands until '}'*/
        //making commands and executing once. will be executed more if the boolean in while keep equaling true.
        Command* c;
        string current = commands[startIndex];
        //first iteration:
        while(current.compare("}") != 0){
            if(current.compare("openDataServer") == 0){
                c = new openServerCommand(m_varBind,m_symbolTable);
            }
            else if(current.compare("connect") == 0){
                c = new connectCommand(m_varBind,m_symbolTable);
            }
            else if(current.compare("var") == 0){
                c = new varCommand(m_varBind,m_symbolTable);
            }
            else if(current.compare("if") == 0){
                c = new conditionParser(m_symbolTable,m_varBind,false);
            }
            else if(current.compare("while") == 0){
                c = new conditionParser(m_symbolTable,m_varBind,true);
            }
            else if(current.compare("print") == 0){
                c = new printCommand(m_symbolTable);
            }
            else{//if its = command or invalid command
                if(startIndex +1 >= commands->size() || commands[startIndex +1].compare("=") != 0){
                    throw invalid_argument("not a valid command inside the loop!");
                }
                else{//its = command
                    c = new equalCommand(m_varBind,m_symbolTable);
                }
            }
            commandsList.push_back(c);
            int addTemp = c->execute(commands,startIndex);//performing the first iteration-at least a "if" statement.
            startIndex += addTemp;
            addToIndex += addTemp;
            current = commands[startIndex];
        }
        addToIndex ++;//getting after '}'
        if(m_isWhile){
            while(exp->boolEvaluate(commands,constBooleanStartIndex,&dummyAddToIndex)){//check if boolen is true for loop
                startIndex = firstStartIndex;
                for(list<Command*>::iterator it = commandsList.begin(); it != commandsList.end(); ++it){
                    startIndex += (*it)->execute(commands,startIndex);
                }
            }
        }
    }
    else{//lets find the "}" without executing anything in the while/if
        string current = commands[startIndex];
        int extraOpenings = 0;
        while(true){//searching for } that equals to { opened
            if(current.compare("}") == 0){
                if(extraOpenings == 0)
                    break;
                else
                    extraOpenings --;
            }
            if(current.compare("{") == 0){
                extraOpenings ++;
            }
            startIndex ++;
            addToIndex ++;
            current = commands[startIndex];
        }
        addToIndex ++;//getting after '}'
    }
    return addToIndex;//return to add to -one after '}'
}
conditionParser::~conditionParser() {
    commandsList.clear();
}