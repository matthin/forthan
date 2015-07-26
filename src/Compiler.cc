#include "Compiler.h"

#include <sstream>

namespace ft {

Compiler::Compiler(const std::string& instructions) {
  std::istringstream stream(instructions);

  std::string line;
  while(std::getline(stream, line, ' ')) {
    try {
      dictionary.at(line)();
    } catch (const std::out_of_range& error) {
      stack.push(std::stoi(line));
    }
  }
}

} // namespace ft

