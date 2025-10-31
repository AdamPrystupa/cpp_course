#include <iostream>
#include <vector>

int addEven(const std::vector<int> &numbers) {
  size_t sum = 0;
  for (auto element : numbers) {
    if (element % 2 == 0)
      sum += element;
  }
  return sum;
}

int main() {
  //   std::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> vec = {0, 10, 1};
  //   std::vector<int> vec = {10, 3, 20, 1, 5};
  auto result = addEven(vec); // result = 6;
  std::cout << "result = " << result << "\n";

  return 0;
}