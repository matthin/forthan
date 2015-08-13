#include "Interpreter.h"
#include <catch.hpp>

TEST_CASE("Implements all basic math operators") {
  ft::Interpreter interpreter("4 10 * 5 / 7 + 2 -");
  REQUIRE(interpreter.stack.size() == 1);
  REQUIRE(interpreter.stack.top() == 13);
}

TEST_CASE("Implements absolute value") {
  ft::Interpreter interpreter("-47 ABS");
  REQUIRE(interpreter.stack.top() == 47);
}

TEST_CASE("Implements bitwise AND") {
  ft::Interpreter interpreter("10 8 AND");
  REQUIRE(interpreter.stack.top() == 8);
}

TEST_CASE("Implements bitwise OR") {
  ft::Interpreter interpreter("7 46 OR");
  REQUIRE(interpreter.stack.top() == 47);
}

TEST_CASE("Implements bitwise XOR") {
  ft::Interpreter interpreter("87 6 XOR");
  REQUIRE(interpreter.stack.top() == 81);
}

TEST_CASE("Implements bitwise NOT") {
  ft::Interpreter interpreter("9 NOT");
  REQUIRE(interpreter.stack.top() == -10);
}

TEST_CASE("Implements comparison operators", "[Interpreter]") {
  SECTION("Equality operator") {
    SECTION("Pushes -1 on the stack when true") {
      ft::Interpreter interpreter(
        "10 10 ="
      );
      REQUIRE(interpreter.stack.top() == -1);
    }

    SECTION("Pushes 0 on the stack when false") {
      ft::Interpreter interpreter(
        "10 9 ="
      );
      REQUIRE(interpreter.stack.top() == 0);
    }
  }

  SECTION("Lesser than operator") {
    SECTION("Pushes -1 on the stack when true") {
      ft::Interpreter interpreter(
        "40 47 <"
      );
      REQUIRE(interpreter.stack.top() == -1);
    }

    SECTION("Pushes 0 on the stack when false") {
      ft::Interpreter interpreter(
        "47 40 <"
      );
      REQUIRE(interpreter.stack.top() == 0);
    }
  }

  SECTION("Greater than operator") {
    SECTION("Pushes -1 on the stack when true") {
      ft::Interpreter interpreter(
        "35 30 >"
      );
      REQUIRE(interpreter.stack.top() == -1);
    }

    SECTION("Pushes 0 on the stack when false") {
      ft::Interpreter interpreter(
        "30 35 >"
      );
      REQUIRE(interpreter.stack.top() == 0);
    }
  }
}

TEST_CASE("Implements multiply-divide (*/)") {
  ft::Interpreter interpreter("214820 242324 131 */");
  REQUIRE(interpreter.stack.top() == 397374363);
}

TEST_CASE("Implements multiply-divide-mod (*/MOD)") {
  ft::Interpreter interpreter("498571 714240 4692 */MOD");
  REQUIRE(interpreter.stack.top() == 75895002);
  interpreter.stack.pop();
  REQUIRE(interpreter.stack.top() == 1656);
}

TEST_CASE("Implements CREATE") {
  ft::Interpreter interpreter("CREATE example CREATE test test");
  const auto address = interpreter.stack.top();
  REQUIRE(address == 1);
  REQUIRE(interpreter.memory.at(address) == nullptr);
}

TEST_CASE("Implements DROP") {
  ft::Interpreter interpreter("1 2 DROP");
  REQUIRE(interpreter.stack.top() == 1);
}

TEST_CASE("Implements WORD") {
  ft::Interpreter interpreter("41 WORD c )");
  const auto startingPosition = interpreter.stack.top();
  REQUIRE(*(interpreter.memory.at(startingPosition)) == 2);
  REQUIRE(*(interpreter.memory.at(startingPosition + 1)) == 99);
}

