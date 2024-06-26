#include "lexer.hpp"
#include "token.hpp"
#include <iostream>
#include <string>


int main() {
    std::string input =
        "let five = 5; \
        let ten = 10; \
        \
        let add = fn(x, y) { \
        x + y; \
        }; \
        \
        let result = add(five, ten); \
    ";

    auto *l = new Lexer(input);

    for (Token t = l->nextToken(); t.type != TokenType::EOF_; t = l->nextToken()) {
        t.print();
    }

    std::cout << "DONE!\n";

}

