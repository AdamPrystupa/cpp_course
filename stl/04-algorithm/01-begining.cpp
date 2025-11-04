/*
Zadanie 💻

    Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    Policz, ile jest elementów większych lub równych 5
    Sprawdź, czy istnieje element mniejszy od 1
    Sprawdź, czy wszystkie elementy są większe od 1
*/
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 3, 8, 9};
  std::cout << std::count_if(begin(v), end(v), [](auto element) {
    return element >= 5;
  }) << "\n";
  if (std::any_of(begin(v), end(v), [](auto element) { return element < 1; })) {
    std::cout << "istnieje element <1!\n";
  } else
    std::cout << "nie istnieje element <1!\n";

  if (std::all_of(begin(v), end(v), [](auto element) { return element > 1; })) {
    std::cout << "wszystkie elementy >1!\n";
  } else
    std::cout << "nie wszystkie elementy >1!\n";

  return 0;
}