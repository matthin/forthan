#pragma once

#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

namespace ft {

class Interpreter {
public:
  Interpreter() {}
  Interpreter(const std::string& instructions) {
    runInstructions(instructions);
  }
  void runInstructions(const std::string& instructions);

  void addWords(
    const std::unordered_map<std::string, std::function<void()>> newWords
  ) {
    dictionary.insert(newWords.begin(), newWords.end());
  }

  std::stack<int> stack;

private:
  int stackPopTop() {
    const auto element = stack.top();
    stack.pop();
    return element;
  }

  std::unordered_map<std::string, std::function<void()>> dictionary = {
    {"+", std::bind(&Interpreter::add, this)},
    {"-", std::bind(&Interpreter::subtract, this)},
    {"*", std::bind(&Interpreter::multiply, this)},
    {"/", std::bind(&Interpreter::divide, this)},
    {".", std::bind(&Interpreter::print, this)},
    {"EMIT", std::bind(&Interpreter::emit, this)},
    {"CR", std::bind(&Interpreter::carriageReturn, this)},
    {"ABS", std::bind(&Interpreter::absoluteValue, this)},

    // Bitwise Operators
    {"AND", std::bind(&Interpreter::bitwiseAND, this)},
    {"OR", std::bind(&Interpreter::bitwiseOR, this)},
    {"XOR", std::bind(&Interpreter::bitwiseXOR, this)},
    {"NOT", std::bind(&Interpreter::bitwiseNOT, this)},

    // Comparison Operators
    {"=", std::bind(&Interpreter::equals, this)},
    {"<", std::bind(&Interpreter::lesserThan, this)},
    {">", std::bind(&Interpreter::greaterThan, this)},
    {"0<", std::bind(&Interpreter::lesserThanZero, this)},
    {"0>", std::bind(&Interpreter::greaterThanZero, this)},
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
  void emit() {
    std::cout << std::to_string(stackPopTop());
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

  /*
   * Comparison Operators
   */
  void equals() {
    stack.push(
      stackPopTop() == stackPopTop() ? -1 : 0
    );
  }
  void lesserThan() {
    const auto second = stackPopTop();
    const auto first = stackPopTop();
    stack.push(
      first < second ? -1 : 0
    );
  }
  void greaterThan() {
    const auto second = stackPopTop();
    const auto first = stackPopTop();
    stack.push(
      first > second ? -1 : 0
    );
  }
  void lesserThanZero() {
    stack.push(
      stackPopTop() < 0 ? -1 : 0
    );
  }
  void greaterThanZero() {
    stack.push(
      stackPopTop() > 0 ? -1 : 0
    );
  }
};

} // namespace ft

