#include <array>
#include <iostream>

int main() {
  std::array<int, 4> numbers{3, 1, 4, 1};
  std::array<int, 0> no_numbers;
  std::array<int, 3> other;

  std::cout << std::boolalpha;
  std::cout << "numbers.empty(): " << numbers.empty() << '\n';
  std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';
  std::cout << "other.empty(): " << other.empty() << '\n';
  for (auto element : other)
    std::cout << element << ", ";
  std::cout << "\n";
}