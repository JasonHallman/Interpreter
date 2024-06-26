#pragma once

#include "token.hpp"
#include <string>

class Lexer {
public:
    std::string input;
    int pos = 0;

    Lexer(std::string& input) : input(input) {}

    Token nextToken();
    void skipWhitespace();
    Token getToken();
    char getChar(int offset = 0);
    std::string getWord();
    std::string getNumber();
    Token getWordToken(const std::string);
};

