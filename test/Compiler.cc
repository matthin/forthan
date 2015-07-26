#include "Compiler.h"
#include <catch.hpp>

TEST_CASE("Compiles all basic math operators") {
  ft::Compiler compiler("4 10 * 5 / 7 + 2 -");
  REQUIRE(compiler.stack.size() == 1);
  REQUIRE(compiler.stack.top() == 13);
}

