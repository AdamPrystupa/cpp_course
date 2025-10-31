#include <iostream>
#include <string>
#include <vector>

// Implement printVector to print the content of a given vector on screen.
// Each string in a new line.

void printVector(std::vector<std::string> &vec) {
  for (const auto &element : vec)
    std::cout << element << "\n";
}

int main() {
  std::vector<std::string> vec{"Hello Coders School!",
                               "Welcome to the best C++ course ever",
                               "Man, this is crazy :)"};
  printVector(vec);
  return 0;
}