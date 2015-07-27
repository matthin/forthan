#include "Compiler.h"

#include <sstream>

namespace ft {

Compiler::Compiler(std::string instructions) {
  // Add a single space between each newline.
  // Prevents including newline in a word.
  // Without this, *\n wouldn't match with * in the dictionary.
  size_t position = 0;
  for (int i = 0, len = instructions.size(); i < len; ++i) {
    position = instructions.find('\n', position);
    if (position == std::string::npos) {
      break;
    }
    instructions.insert(position, " ");
    position += 2;
  }

  std::istringstream stream(instructions);

  std::string line;
  while(std::getline(stream, line, ' ')) {
    if (line.find('\\') != std::string::npos) {
      std::string comment;
      std::getline(stream, comment);
      continue;
    }
    if (line.at(0) == '\n' || line.at(0) == ' ') {
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

