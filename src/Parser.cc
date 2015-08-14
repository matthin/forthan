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

  removeComments(instructions);

  cleanupInstructions(instructions);

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

void Parser::replaceAll(
  std::string* subject, const std::string& search, const std::string& replace
) {
  size_t position = 0;
  while ((position = subject->find(search, position)) != std::string::npos) {
    subject->replace(position, search.length(), replace);
    position += replace.length();
  }
}

} // namespace ft

