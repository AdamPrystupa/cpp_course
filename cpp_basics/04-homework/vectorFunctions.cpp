#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(const int &count) {
  std::vector<std::shared_ptr<int>> vec;
  for (size_t i = 0; i < count; ++i) {
    std::shared_ptr<int> temp = std::make_shared<int>(i);
    vec.push_back(temp);
  }
  return vec;
}

void print(std::vector<std::shared_ptr<int>> &vec) {
  for (auto element : vec) {
    std::cout << *element << ", ";
  }
  std::cout << "\n";
}

void add10(std::vector<std::shared_ptr<int>> &vec) {
  for (auto element : vec) {
    *element += 10;
  }
}

void sub10(int *const ptr) { *ptr -= 10; }

void sub10(std::vector<std::shared_ptr<int>> &vec) {
  for (auto element : vec) {
    sub10(element.get());
  }
}
