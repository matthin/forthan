#pragma once

#include <functional>
#include "Interpreter.h"
#include <unordered_map>
#include <string>

namespace ft {

class Compiler {
public:
  Compiler(std::string* instructions, Interpreter* interpreter);

  std::unordered_map<std::string, std::function<void()>> dictionary;

private:
  void addUserWords(std::string* instructions, Interpreter* interpreter);
};

} // namespace ft

