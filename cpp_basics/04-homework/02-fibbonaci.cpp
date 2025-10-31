#include <iostream>
#include <vector>

int fibonacci_iterative(int sequence) {
  std::vector<int> vec = {0, 1};
  for (size_t i = 2; i <= sequence; ++i) {
    vec.push_back(vec[i - 1] + vec[i - 2]);
  }
  return vec[sequence];
}

int fibonacci_recursive(int sequence) {
  size_t result = 0;
  if (sequence == 0)
    result = 0;
  else if (sequence == 1)
    result = 1;
  else
    result +=
        (fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2));
  return result;
}

int main() {
  int sequence = 8;
  std::cout << "Fibonacci for n iterative: " << sequence << " = "
            << fibonacci_iterative(sequence) << "\n";
  std::cout << "Fibonacci for n recursive: " << sequence << " = "
            << fibonacci_recursive(sequence) << "\n";
  return 0;
}