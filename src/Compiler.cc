#include "Compiler.h"

#include <sstream>

namespace ft {

Compiler::Compiler(const std::string& instructions) {
  std::istringstream stream(instructions);

  std::string line;
  while(std::getline(stream, line, ' ')) {
    if (line.at(0) == '*') {
      stack.push(
        stackPopTop() * stackPopTop()
      );
    } else {
      stack.push(std::stoi(line));
    }
  }
}

} // namespace ft

