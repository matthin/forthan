#include "Compiler.h"
#include <catch.hpp>
#include "Interpreter.h"
#include <string>

TEST_CASE("Compiles user defined words") {
  ft::Interpreter interpreter;
  ft::Compiler compiler(
    new std::string( ": EXAMPLE 3 4 * ;"),
    &interpreter
  );
  REQUIRE(compiler.dictionary.at("EXAMPLE"));
}

