#include <array>
#include <iostream>

int main() {
  std::array<int, 10> array;
  array.fill(5);
  array[4] = 3;
  std::array<int, 10> array1;
  array.swap(array1);

  for (auto element : array)
    std::cout << element << ", ";
  std::cout << "\n";

  for (auto element : array1)
    std::cout << element << ", ";
  std::cout << "\n";
}