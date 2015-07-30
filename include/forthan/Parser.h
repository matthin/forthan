#pragma once

#include <string>

namespace ft {

class Parser {
public:
  Parser(std::string* instructions);

private:
  void removeComments(std::string* instructions) const;
};

} // namespace ft

