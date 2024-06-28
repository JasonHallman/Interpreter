#pragma once

#include <string>
#include <iostream>

enum class TokenType {
    ILLEGAL,
    EOF_,

    IDENT,
    INT,

    ASSIGN,
    PLUS,
    MINUS,
    BANG,
    ASTERISK,
    SLASH,
    LT,
    GT,

    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    FUNCTION,
    LET
};

class Token {
public:
    TokenType type;
    std::string literal;

    Token(TokenType type, const std::string& literal);
    void print() const;
};
