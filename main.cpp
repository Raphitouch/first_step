#include "Lexer.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "TOMER starts here : \n ******************************* \n" << std::endl;
    Lexer* lexer = new Lexer();
    string* s = lexer->lex("/home/cs/CLionProjects/TESTINGS/commandsfile.txt");
    for(int i = 0; i < lexer->getNum(); i++){
        cout << "s[" << i << "] = " << s[i] << endl;
    }
    delete[] s;
    return 0;
}