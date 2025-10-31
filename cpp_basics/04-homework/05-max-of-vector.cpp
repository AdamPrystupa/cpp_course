#include <iostream>
#include <vector>

int maxOfVector(const std::vector<int> &numbers) {
  int max = 0;
  for (auto element : numbers) {
    if (element > max)
      max = element;
  }

  return max;
}

int main() {
  std::vector<int> numbers = {6, 78, 12, 54, -11, 0};
  auto result = maxOfVector(numbers); // result = 78
  std::cout << "result = " << result << "\n";

  return 0;
}