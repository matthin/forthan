#include "Parser.h"
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

