/*
Zadanie

Utwórz funktor sprawdzający czy podana liczba typu int jest podzielna przez 6
*/

#include <algorithm>
#include <iostream>
#include <vector>
struct Functor {

  void operator()(int number) {
    if (number % 6 == 0) {
      std::cout << number << " jest podzielne przez 6\n";
    } else
      std::cout << number << " nie jest podzielne przez 6\n";
  }
};

int main() {
  std::vector<int> vec = {6,    1,   12, 88, 32,  5,   121,
                          1233, 567, 80, 60, 120, 554, 588};
  std::for_each(begin(vec), end(vec), Functor{});
}