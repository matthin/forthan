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

  removeComments(&instructions);
  addUserWords(&instructions);

  parseInstructions(instructions);
}

void Compiler::parseInstructions(std::string instructions) {
  std::istringstream stream(instructions);

  std::string line;
  while(std::getline(stream, line, ' ')) {
    if (line.size() == 0) {
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

void Compiler::addUserWords(std::string* instructions) {
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

    dictionary[wordTitle] = [this, wordInstructions]() {
      parseInstructions(wordInstructions);
    };
  }
}

void Compiler::removeComments(std::string* instructions) {
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

