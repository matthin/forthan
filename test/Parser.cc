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

  SECTION("2+") {
    std::string instructions(
      "9 2+"
    );
    ft::Parser parser(&instructions);
    REQUIRE(parser.interpreter.stack.top() == 11);
  }

  SECTION("2-") {
    std::string instructions(
      "87 2-"
    );
    ft::Parser parser(&instructions);
    REQUIRE(parser.interpreter.stack.top() == 85);
  }

  SECTION("Implements comparison WORD set") {
    SECTION("Lesser than 0 operator") {
      SECTION("Pushes -1 on the stack when true") {
        std::string instructions("-30 0<");
        ft::Parser parser(&instructions);
        REQUIRE(parser.interpreter.stack.top() == -1);
      }

      SECTION("Pushes 0 on the stack when false") {
        std::string instructions("30 0<");
        ft::Parser parser(&instructions);
        REQUIRE(parser.interpreter.stack.top() == 0);
      }
    }

    SECTION("Greater than 0 operator") {
      SECTION("Pushes -1 on the stack when true") {
        std::string instructions("45 0>");
        ft::Parser parser(&instructions);
        REQUIRE(parser.interpreter.stack.top() == -1);
      }

      SECTION("Pushes 0 on the stack when false") {
        std::string instructions("-45 0>");
        ft::Parser parser(&instructions);
        REQUIRE(parser.interpreter.stack.top() == 0);
      }
    }
  }
}

