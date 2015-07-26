#pragma once

#include <functional>
#include <stack>
#include <string>
#include <unordered_map>

namespace ft {

class Compiler {
public:
  Compiler(const std::string& instructions);
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
};

} // namespace ft

