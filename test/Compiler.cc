#include "Compiler.h"
#include <catch.hpp>

TEST_CASE("Compiles a basic mathamatical expression") {
  ft::Compiler compiler("2 5 *");
  REQUIRE(compiler.stack.size() == 1);
  REQUIRE(compiler.stack.top() == 10);
}

