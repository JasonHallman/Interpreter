#include "lexer.hpp"
#include "token.hpp"
#include <iostream>
#include <string>


int main() {
    std::string input = "=+(){},;";

    Lexer *l = new Lexer(input);

    for (Token t = l->nextToken(); t.type != TokenType::EOF_; t = l->nextToken()) {
        t.print();
    }

    std::cout << "DONE!\n";

}

