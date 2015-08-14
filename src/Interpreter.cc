#include "Interpreter.h"

namespace ft {

void Interpreter::runInstructions(const std::string& instructions) {
  stream << instructions;

  std::string line;
  while(std::getline(stream, line, ' ')) {
    if (line.size() == 0 || line.at(0) == '\n' || line.at(0) == ' ') {
      continue;
    }

    try {
      dictionary.at(line)();
    } catch (const std::out_of_range& error) {
      stack.push(std::stoi(line));
    }
  }
}

} // namespace ft

