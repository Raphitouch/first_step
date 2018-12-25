#include "Parser.h"
/** running the Even Derech 1 project*/
int main(int argc, char* argv[]) {
    Parser* parser = new Parser(new Lexer(argv[1]));
    parser->parse();
    return 0;
}