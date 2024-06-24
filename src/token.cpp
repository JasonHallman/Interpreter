#include "token.hpp"
#include <string>
#include <iostream>

Token::Token(TokenType type, const std::string& literal) : type(type), literal(literal) {}

void Token::print() const {
    std::string tt;

    switch (this->type) {
        case TokenType::ILLEGAL: tt = "TokenType::ILLEGAL"; break;
        case TokenType::EOF_: tt = "TokenType::END_OF_FILE"; break;
        case TokenType::IDENT: tt = "TokenType::IDENT"; break;
        case TokenType::INT: tt = "TokenType::INT"; break;
        case TokenType::ASSIGN: tt = "TokenType::ASSIGN"; break;
        case TokenType::PLUS: tt = "TokenType::PLUS"; break;
        case TokenType::COMMA: tt = "TokenType::COMMA"; break;
        case TokenType::SEMICOLON: tt = "TokenType::SEMICOLON"; break;
        case TokenType::LPAREN: tt = "TokenType::LPAREN"; break;
        case TokenType::RPAREN: tt = "TokenType::RPAREN"; break;
        case TokenType::LBRACE: tt = "TokenType::LBRACE"; break;
        case TokenType::RBRACE: tt = "TokenType::RBRACE"; break;
        case TokenType::FUNCTION: tt = "TokenType::FUNCTION"; break;
        case TokenType::LET: tt = "TokenType::LET"; break;
        default: tt = "UNKNOWN";
    }
    std::cout << "{" << tt << ", " << this->literal << "}\n";
}
