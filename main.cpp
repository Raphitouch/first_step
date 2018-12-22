#include "Lexer.h"

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "TOMER starts here : \n ******************************* \n" << std::endl;
    Lexer* lexer = new Lexer(argv[1]);
    string* s = lexer->lex();
    for(int i = 0; i < lexer->getNum(); i++){
        cout << "s[" << i << "] = " << s[i] << endl;
    }
    delete[] s;
    return 0;
}