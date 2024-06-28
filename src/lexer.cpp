#include "lexer.hpp"
#include "token.hpp"
#include <string>
#include <map>
#include <iostream>

Token Lexer::nextToken() {
    this->skipWhitespace();

    if (pos >= this->input.size()) {
        return Token(TokenType::EOF_, "");
    }

    char cur_char = this->getChar();
    TokenType tt;

    switch (cur_char) {
        case '=': tt = TokenType::ASSIGN; break;
        case '+': tt = TokenType::PLUS; break;
        case '-': tt = TokenType::MINUS; break;
        case '!': tt = TokenType::BANG; break;
        case '*': tt = TokenType::ASTERISK; break;
        case '/': tt = TokenType::SLASH; break;
        case '>': tt = TokenType::GT; break;
        case '<': tt = TokenType::LT; break;
        case ',': tt = TokenType::COMMA; break;
        case ';': tt = TokenType::SEMICOLON; break;
        case '(': tt = TokenType::LPAREN; break;
        case ')': tt = TokenType::RPAREN; break;
        case '{': tt = TokenType::LBRACE; break;
        case '}': tt = TokenType::RBRACE; break;
        default: 
            std::string literal;

            literal = this->getWord();
            if (literal.size() > 0) {
                return this->getWordToken(literal);
            } else {
                literal = this->getNumber();
                return Token(TokenType::INT, literal);
            }
    }

    this->pos++;
    return Token(tt, std::string(1, cur_char));
}

void Lexer::skipWhitespace() {
    char cur_char = this->getChar();

    while (
        cur_char == ' '  ||
        cur_char == '\n' ||
        cur_char == '\t' ||
        cur_char == '\r'
    ) {
        this->pos++;
        cur_char = this->getChar();
    }
}

char Lexer::getChar(int offset) {
    return this->input[this->pos + offset];
}


std::string Lexer::getNumber() {
    int pos_offset = 0;
    char cur_char = this->getChar(pos_offset);

    while (cur_char >= '0' && cur_char <= '9') {
        pos_offset++;
        cur_char = this->getChar(pos_offset);
    }

    if (pos_offset > 0) {
        std::string word = this->input.substr(this->pos, pos_offset);
        this->pos += pos_offset;
        return word;
    }

    return "";
}

std::string Lexer::getWord() {
    int pos_offset = 0;
    char cur_char = this->getChar(pos_offset);

    while (('A' <= cur_char && cur_char <= 'Z') || ('a' <= cur_char && cur_char <= 'z') || cur_char == '_') {
        pos_offset++;
        cur_char = this->getChar(pos_offset);
    }

    if (pos_offset > 0) {
        std::string word = this->input.substr(this->pos, pos_offset);
        this->pos += pos_offset;
        return word;
    }

    return "";
}

Token Lexer::getWordToken(const std::string word) {
    std::map<std::string, TokenType> keyword_map = {
        {"let", TokenType::LET},
        {"fn", TokenType::FUNCTION},
    };

    if (keyword_map.contains(word)) {
        return Token(keyword_map[word], word);
    }

    return Token(TokenType::IDENT, word);
}
