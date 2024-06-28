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
        case TokenType::MINUS: tt = "TokenType::MINUS"; break;
        case TokenType::BANG: tt = "TokenType::BANG"; break;
        case TokenType::ASTERISK: tt = "TokenType::ASTERISK"; break;
        case TokenType::SLASH: tt = "TokenType::SLASH"; break;
        case TokenType::LT: tt = "TokenType::LT"; break;
        case TokenType::GT: tt = "TokenType::GT"; break;
        case TokenType::EQ: tt = "TokenType::EQ"; break;
        case TokenType::NOT_EQ: tt = "TokenType::NOT_EQ"; break;
        case TokenType::COMMA: tt = "TokenType::COMMA"; break;
        case TokenType::SEMICOLON: tt = "TokenType::SEMICOLON"; break;
        case TokenType::LPAREN: tt = "TokenType::LPAREN"; break;
        case TokenType::RPAREN: tt = "TokenType::RPAREN"; break;
        case TokenType::LBRACE: tt = "TokenType::LBRACE"; break;
        case TokenType::RBRACE: tt = "TokenType::RBRACE"; break;
        case TokenType::FUNCTION: tt = "TokenType::FUNCTION"; break;
        case TokenType::LET: tt = "TokenType::LET"; break;
        case TokenType::TRUE: tt = "TokenType::TRUE"; break;
        case TokenType::FALSE: tt = "TokenType::FALSE"; break;
        case TokenType::IF: tt = "TokenType::IF"; break;
        case TokenType::ELSE: tt = "TokenType::ELSE"; break;
        case TokenType::RETURN: tt = "TokenType::RETURN"; break;
        default: tt = "UNKNOWN";
    }
    std::cout << "{" << tt << ", " << this->literal << "}\n";
}
