#include "Parser.h"
#include "Interpreter.h"
#include <catch.hpp>
#include <string>

TEST_CASE("Discards comments") {
  std::string instructions(
    "3 5 *\n"
    "\\ Example comment\n"
    " (Example inline comment) 2 +"
  );
  ft::Parser parser(&instructions);
  REQUIRE(instructions.find("\\ Example comment\n") == std::string::npos);
}

TEST_CASE("Implements required WORD set", "[Parser]") {
  SECTION("1+") {
    std::string instructions(
      "7 1+"
    );
    ft::Parser parser(&instructions);
    REQUIRE(parser.interpreter.stack.top() == 8);
  }

  SECTION("1-") {
    std::string instructions(
      "46 1-"
    );
    ft::Parser parser(&instructions);
    REQUIRE(parser.interpreter.stack.top() == 45);
  }
}

