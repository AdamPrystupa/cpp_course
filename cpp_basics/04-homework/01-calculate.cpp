#include <iostream>
#include <string>

enum class operation { add, subtract, multiply, divide, other };

operation hashing(const std::string &command) {
  if (command == "add")
    return operation::add;
  if (command == "subtract")
    return operation::subtract;
  if (command == "multiply")
    return operation::multiply;
  if (command == "divide")
    return operation::divide;
  return operation::other;
}

std::string calculate(const std::string &command, int first, int second) {

  switch (hashing(command)) {
  case operation::add:
    return (std::to_string(first + second));
    break;

  case operation::subtract:
    return (std::to_string(first - second));
    break;

  case operation::multiply:
    return (std::to_string(first * second));
    break;

  case operation::divide:
    return (std::to_string(first / second));
    break;

  default:
    return ("invalid data");
    break;
  }
}

int main() {
  int first = 10;
  int second = 12;
  auto result = calculate("add", first, second);
  std::cout << "calculation result: " << result << "\n";
  result = calculate("subtract", first, second);
  std::cout << "calculation result: " << result << "\n";
  result = calculate("multiply", first, second);
  std::cout << "calculation result: " << result << "\n";
  result = calculate("divide", first, second);
  std::cout << "calculation result: " << result << "\n";
}