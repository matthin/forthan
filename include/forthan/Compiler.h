#pragma once

#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

namespace ft {

class Compiler {
public:
  Compiler(std::string instructions);
  std::stack<int> stack;

private:
  int stackPopTop() {
    const auto element = stack.top();
    stack.pop();
    return element;
  }

  std::unordered_map<std::string, std::function<void()>> dictionary = {
    {"+", std::bind(&Compiler::add, this)},
    {"-", std::bind(&Compiler::subtract, this)},
    {"*", std::bind(&Compiler::multiply, this)},
    {"/", std::bind(&Compiler::divide, this)},
    {".", std::bind(&Compiler::print, this)},
    {"CR", std::bind(&Compiler::carriageReturn, this)},
    {"ABS", std::bind(&Compiler::absoluteValue, this)},

    // Bitwise Operators
    {"AND", std::bind(&Compiler::bitwiseAND, this)},
    {"OR", std::bind(&Compiler::bitwiseOR, this)},
    {"XOR", std::bind(&Compiler::bitwiseXOR, this)},
    {"NOT", std::bind(&Compiler::bitwiseNOT, this)}
  };

  void add() {
    stack.push(
      stackPopTop() + stackPopTop()
    );
  }
  void subtract() {
    const auto second = stackPopTop();
    const auto first = stackPopTop();
    stack.push(
      first - second
    );
  }
  void multiply() {
    stack.push(
      stackPopTop() * stackPopTop()
    );
  }
  void divide() {
    const auto second = stackPopTop();
    const auto first = stackPopTop();
    stack.push(
      first / second
    );
  }
  void print() {
    std::cout << stackPopTop();
  }
  void carriageReturn() {
    std::cout << '\r';
  }
  void absoluteValue() {
    stack.push(
      std::abs(stackPopTop())
    );
  }

  /*
   * Bitwise Operators
   */
  void bitwiseAND() {
    stack.push(
      stackPopTop() & stackPopTop()
    );
  }
  void bitwiseOR() {
    stack.push(
      stackPopTop() | stackPopTop()
    );
  }
  void bitwiseXOR() {
    stack.push(
      stackPopTop() ^ stackPopTop()
    );
  }
  void bitwiseNOT() {
    stack.push(
      ~stackPopTop()
    );
  }
};

} // namespace ft

