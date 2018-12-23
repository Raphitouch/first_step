#include "Parser.h"

int main(int argc, char* argv[]) {
    Parser* parser = new Parser(new Lexer(argv[1]));
    parser->parse();
    return 0;
}