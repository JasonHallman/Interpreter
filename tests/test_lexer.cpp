#include "catch.hpp"
#include "lexer.hpp"
#include "token.hpp"
#include <string>

TEST_CASE("Lexer test", "[lexer]") {
    SECTION("Default") {
        std::string input = "=+(){},;";

        std::vector<Token> test_tokens = {
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

        for (int i = 0; i < test_tokens.size(); i++) {
            Token t = l->nextToken();

            REQUIRE(t.type == test_tokens[i].type);
            REQUIRE(t.literal == test_tokens[i].literal);
        }
    }
}

TEST_CASE("More", "[lexer]") {
    SECTION("Default") {
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

        std::vector<Token> test_tokens = {
            Token(TokenType::LET, "let"),
            Token(TokenType::IDENT, "five"),
            Token(TokenType::ASSIGN, "="),
            Token(TokenType::INT, "5"),
            Token(TokenType::SEMICOLON, ";"),
            Token(TokenType::LET, "let"),
            Token(TokenType::IDENT, "ten"),
            Token(TokenType::ASSIGN, "="),
            Token(TokenType::INT, "10"),
            Token(TokenType::SEMICOLON, ";"),
            Token(TokenType::LET, "let"),
            Token(TokenType::IDENT, "add"),
            Token(TokenType::ASSIGN, "="),
            Token(TokenType::FUNCTION, "fn"),
            Token(TokenType::LPAREN, "("),
            Token(TokenType::IDENT, "x"),
            Token(TokenType::COMMA, ","),
            Token(TokenType::IDENT, "y"),
            Token(TokenType::RPAREN, ")"),
            Token(TokenType::LBRACE, "{"),
            Token(TokenType::IDENT, "x"),
            Token(TokenType::PLUS, "+"),
            Token(TokenType::IDENT, "y"),
            Token(TokenType::SEMICOLON, ";"),
            Token(TokenType::RBRACE, "}"),
            Token(TokenType::SEMICOLON, ";"),
            Token(TokenType::LET, "let"),
            Token(TokenType::IDENT, "result"),
            Token(TokenType::ASSIGN, "="),
            Token(TokenType::IDENT, "add"),
            Token(TokenType::LPAREN, "("),
            Token(TokenType::IDENT, "five"),
            Token(TokenType::COMMA, ","),
            Token(TokenType::IDENT, "ten"),
            Token(TokenType::RPAREN, ")"),
            Token(TokenType::SEMICOLON, ";"),
            Token(TokenType::EOF_, ""),
        };

        Lexer *l = new Lexer(input);

        for (int i = 0; i < test_tokens.size(); i++) {
            Token t = l->nextToken();

            REQUIRE(t.type == test_tokens[i].type);
            REQUIRE(t.literal == test_tokens[i].literal);
        }
    }
}
