#include "lexer.hpp"
#include "token.hpp"
#include <iostream>
#include <string>


int main() {
    Lexer* l;
    while (true) {
        std::cout << ">> ";
        std::string line;
        std::getline(std::cin, line);

        l =  new Lexer(line);

        for (Token t = l->nextToken(); t.type != TokenType::EOF_; t = l->nextToken()) {
            t.print();
        }
    }
    delete l;
}

