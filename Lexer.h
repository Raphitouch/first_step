using namespace std;
/*Lexer module:read from file the script to pass to Parser module*/
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class Lexer{
private:
    int num;//the length of the string array lexed
public:
    string* lex(const string &  fileName);
    int getNum();
};

#endif //LEXER_H
