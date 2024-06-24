#include "lexer.hpp"
#include "token.hpp"
#include <string>

TokenType Lexer::getTokenType() {
    switch (this->getCurrentChar()) {
        case '=': return TokenType::ASSIGN;
        case '+': return TokenType::PLUS;
        case ',': return TokenType::COMMA;
        case ';': return TokenType::SEMICOLON;
        case '(': return TokenType::LPAREN;
        case ')': return TokenType::RPAREN;
        case '{': return TokenType::LBRACE;
        case '}': return TokenType::RBRACE;
        default: return TokenType::ILLEGAL;
    }
}

Token Lexer::nextToken() {
    if (pos > this->input.size()) {
        return Token(TokenType::EOF_, "");
    }

    Token t = Token(this->getTokenType(), std::string(1, this->getCurrentChar()));
    pos++;
    return t;
}

char Lexer::getCurrentChar() {
    return this->input[this->pos];
}
