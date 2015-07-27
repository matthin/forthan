#include "Compiler.h"
#include <catch.hpp>

TEST_CASE("Compiles all basic math operators") {
  ft::Compiler compiler("4 10 * 5 / 7 + 2 -");
  REQUIRE(compiler.stack.size() == 1);
  REQUIRE(compiler.stack.top() == 13);
}

TEST_CASE("Implements absolute value") {
  ft::Compiler compiler("-47 ABS");
  REQUIRE(compiler.stack.top() == 47);
}

TEST_CASE("Implements bitwise AND") {
  ft::Compiler compiler("10 8 AND");
  REQUIRE(compiler.stack.top() == 8);
}

TEST_CASE("Implements bitwise OR") {
  ft::Compiler compiler("7 46 OR");
  REQUIRE(compiler.stack.top() == 47);
}

TEST_CASE("Implements bitwise XOR") {
  ft::Compiler compiler("87 6 XOR");
  REQUIRE(compiler.stack.top() == 81);
}

TEST_CASE("Implements bitwise NOT") {
  ft::Compiler compiler("9 NOT");
  REQUIRE(compiler.stack.top() == -10);
}

TEST_CASE("Discards comments") {
  ft::Compiler compiler(
    "3 5 *\n"
    "\\ Example comment\n"
    "2 +"
  );
  REQUIRE(compiler.stack.size() == 1);
  REQUIRE(compiler.stack.top() == 17);
}

