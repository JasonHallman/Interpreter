#pragma once

#include "token.hpp"
#include <string>

class Lexer {
public:
    std::string input;
    int pos = 0;

    Lexer(std::string& input) : input(input) {}

    Token nextToken();
    TokenType getTokenType();
    char getCurrentChar();
};
