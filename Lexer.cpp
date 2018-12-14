/*Lexer- lex function implemenataion:*/
#include "Lexer.h"
string* Lexer::lex(const string & fileName) {
    string* commands;
    string line;
    int numOfLines = 0;
    ifstream file(fileName);
    if (file.is_open()){
        //getting number of strings to be lexed:
        while (getline(file,line)){
            numOfLines++;
        }
        file.clear();
        file.seekg(0);
        commands = new string[numOfLines];
        numOfLines = 0;
        while (getline(file,line)){
            commands[numOfLines] = line;
            numOfLines++;
        }
        file.close();
    }
    else throw invalid_argument("File cannot be opened!");
    return commands;
}