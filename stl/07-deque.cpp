/*
Zadanie:

    Znajdź dokumentację std:deque na cppreference.com
    Stwórz nowy plik i napisz funkcję main()
    Stwórz pusty deque
    Dodaj do niego pięć dowolnych wartości
    Wyświetl deque
    Usuń drugi i czwarty element
    Dodaj na początek i koniec wartość 30
    Wyświetl deque
    Dodaj na czwartej pozycji liczbę 20
    Wyświetl deque
*/

#include <cstdlib>
#include <deque>
#include <iostream>

void printDeque(std::deque<int> d) {
  for (auto element : d) {
    std::cout << element << " ";
  }
  std::cout << "\n";
}

int main() {
  std::deque<int> d;
  for (size_t i = 0; i < 5; ++i) {
    auto newElement = rand() % 20;
    d.push_front(newElement);
  }
  printDeque(d);

  auto it = d.cbegin();
  auto it2 = d.cbegin();
  auto it3 = d.cbegin();
  std::advance(it, 3);
  d.erase(it);

  std::advance(it2, 1);
  d.erase(it2);

  d.push_back(30);
  d.push_front(30);

  printDeque(d);

  std::advance(it3, 3);
  d.insert(it3, 20);

  printDeque(d);
  return 0;
}