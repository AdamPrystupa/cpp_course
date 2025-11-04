/*
Zadania

    Utwórz lambdę, która przyjmie 2 argumenty typu int oraz zwróci ich iloczyn
    Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów. np.
        krowa -> "krowa"

    Utwórz lambdę, która wypisze ciąg znaków *. Przy każdym zawołaniu funkcji
powinniśmy dostać ciąg dłuższy o jedną *. Kolejno:
        *
        **
        ***
        itd.
*/
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  auto lambda1 = [](int number1, int number2) {
    return number1 * number2;
  }; // lambda printing Hello (not called)
  auto lambda2 = [](std::string word) { return "\"" + word + "\""; };
  auto lambda3 = [index = 1]() mutable {
    std::string output;
    for (size_t i = 0; i < index; ++i) {
      output += "*";
    }
    std::cout << output << "\n";
    index++;
  };

  std::cout << lambda1(3, 5) << "\n";
  std::cout << lambda2("krowa") << "\n";
  lambda3();
  lambda3();
  lambda3();
  lambda3();
  lambda3();
  lambda3();
  lambda3();
  lambda3();

  return 0;
}