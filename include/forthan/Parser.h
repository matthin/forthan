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

  void cleanupInstructions(std::string* instructions) {
    replaceAll(instructions, "\n", " \n ");
  }

  void replaceAll(
    std::string* subject, const std::string& search, const std::string& replace
  );
};

} // namespace ft

