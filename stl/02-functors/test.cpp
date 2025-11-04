#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  []() { std::cout << "Hello"; }; // lambda printing Hello (not called)

  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vec.erase(
      std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2; }),
      vec.end());

  auto print = [](int num) { std::cout << num << ' '; }; // named lambda
  std::for_each(vec.begin(), vec.end(), print);

  return 0;
}