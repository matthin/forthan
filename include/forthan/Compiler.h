#pragma once

#include <stack>
#include <string>

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
};

} // namespace ft

