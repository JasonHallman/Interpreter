#include "token.hpp"
#include <iostream>

int main() {
    Token *t = new Token(TokenType::LET, "let");
    std::cout << "HI!\n";
}

