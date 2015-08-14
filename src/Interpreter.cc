#include "Interpreter.h"

namespace ft {

void Interpreter::runInstructions(const std::string& instructions) {
  stream << instructions;

  std::string line;
  while(std::getline(stream, line, ' ')) {
    if (line.size() == 0 || line.at(0) == '\n' || line.at(0) == ' ') {
      continue;
    }

    auto wordMatch = dictionary.find(line);
    if (wordMatch == dictionary.end()) {
      stack.push(std::stoi(line));
    } else {
      wordMatch->second();
    }
  }
}

} // namespace ft

