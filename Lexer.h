using namespace std;
/*Lexer module:read from file the script to pass to Parser module*/
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class Lexer{
    //private:

    public:
        string* lex(const string &  fileName);
};

#endif //LEXER_H
