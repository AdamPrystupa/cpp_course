#include <iostream>

void printString(std::string str, int num) {
  for (size_t i = 0; i < num; i++) {
    std::cout << str << " ";
  }
}

int main() {
  printString("Hello", 5);
  std::cout << "\n";

  printString("AbC", 5);
  std::cout << "\n";

  printString("HiHi", 6);
  std::cout << "\n";
}