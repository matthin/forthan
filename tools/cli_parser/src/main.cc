#include <Parser.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  std::string instructions(argv[1]);
  ft::Parser parser(&instructions);
  std::cout << std::endl;

  return 0;
}

