#include "catch.hpp"
#include "lexer.hpp"
#include "token.hpp"
#include <string>

TEST_CASE("Lexer test", "[lexer]") {
    SECTION("Default") {
        std::string input = "=+(){},;";

        Token test_tokens[] = {
            Token(TokenType::ASSIGN, "="),
            Token(TokenType::PLUS, "+"),
            Token(TokenType::LPAREN, "("),
            Token(TokenType::RPAREN, ")"),
            Token(TokenType::LBRACE, "{"),
            Token(TokenType::RBRACE, "}"),
            Token(TokenType::COMMA, ","),
            Token(TokenType::SEMICOLON, ";"),
            Token(TokenType::EOF_, ""),
        };

        Lexer *l = new Lexer(input);

        for (int i = 0; i < input.size(); i++) {
            Token t = l->nextToken();

            REQUIRE(t.type == test_tokens[i].type);
            REQUIRE(t.literal == test_tokens[i].literal);
        }
    }
}
