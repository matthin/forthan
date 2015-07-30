#include "Compiler.h"

#include <sstream>

namespace ft {

Compiler::Compiler(std::string* instructions, Interpreter* interpreter) {
  addUserWords(instructions, interpreter);
}

void Compiler::addUserWords(
  std::string* instructions, Interpreter* interpreter
) {
  for (int i = 0, len = instructions->size(); i < len; ++i) {
    const auto start = instructions->find(':');
    if (start == std::string::npos) {
      break;
    }
    const auto end = instructions->find(';');
    auto wordInstructions = instructions->substr(start + 1, end - start - 1);
    instructions->erase(start, end - start + 1);

    size_t wordBegin = std::string::npos;
    size_t wordEnd = std::string::npos;
    for (int i = 0, len = wordInstructions.size(); i < len; ++i) {
      if (wordBegin == std::string::npos) {
        if (wordInstructions.at(i) != ' ') {
          wordBegin = i;
        }
      } else {
        if (wordInstructions.at(i) == ' ') {
          wordEnd = i - 1;
          break;
        }
      }
    }
    const auto wordTitle = wordInstructions.substr(
      wordBegin, wordEnd - wordBegin + 1
    );
    wordInstructions.erase(wordBegin, wordEnd - wordBegin + 1);

    dictionary[wordTitle] = [interpreter, wordInstructions]() {
      interpreter->runInstructions(wordInstructions);
    };
  }
}

} // namespace ft

