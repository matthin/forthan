#pragma once

#include <string>
#include "Interpreter.h"

namespace ft {

class Parser {
public:
  Parser(std::string* instructions);
  Interpreter interpreter;

private:
  void removeComments(std::string* instructions) const;
};

} // namespace ft

