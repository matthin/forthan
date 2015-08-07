#include "Compiler.h"
#include "Interpreter.h"
#include "Parser.h"
#include <fstream>
#include <sstream>

namespace ft {

Parser::Parser(std::string* instructions) {
  // Add required WORDS.
  std::stringstream stream;
  stream << std::ifstream("../words.fs").rdbuf();
  *instructions += stream.str();

  // Add a single space between each newline.
  // Prevents including newline in a word.
  // Without this, *\n wouldn't match with * in the dictionary.
  size_t position = 0;
  for (int i = 0, len = instructions->size(); i < len; ++i) {
    position = instructions->find('\n', position);
    if (position == std::string::npos) {
      break;
    }
    instructions->insert(position, " ");
    position += 2;
  }

  removeComments(instructions);

  Compiler compiler(instructions, &interpreter);
  interpreter.addWords(compiler.dictionary);
  interpreter.runInstructions(*instructions);
}

void Parser::removeComments(std::string* instructions) const {
  for (int i = 0, len = instructions->size(); i < len; ++i) {
    const auto start = instructions->find('(');
    if (start == std::string::npos) {
      break;
    }
    const auto end = instructions->find(')', start);
    instructions->erase(start, end - start + 1);
  }

  for (int i = 0, len = instructions->size(); i < len; ++i) {
    const auto start = instructions->find('\\');
    if (start == std::string::npos) {
      break;
    }
    const auto end = instructions->find('\n', start);
    instructions->erase(start, end - start + 1);
  }
}

} // namespace ft

