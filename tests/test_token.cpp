#include "catch.hpp"
#include "token.hpp"

TEST_CASE("Token class initialization", "[token]") {
    SECTION("Default") {
        Token t(TokenType::ILLEGAL, "^");
        REQUIRE(t.type == TokenType::ILLEGAL);
        REQUIRE(t.literal == "^");
    }
}
