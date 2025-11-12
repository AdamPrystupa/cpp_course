/*
Zadanie

    Znajdź dokumentację std::list<T> na cppreference.com
    Stwórz nowy plik i napisz funkcję main()
    Stwórz listę zawierającą elementy od 0 do 5
    Wyświetl listę
    Usuń trzeci element z listy
    Dodaj na początek i na koniec listy wartość 10
    Wyświetl listę
    Dodaj na czwartej pozycji liczbę 20
    Przepisz listę do std::array<T, N>
    Wyświetl <std::array<T, N>

*/

#include <array>
#include <iostream>
#include <list>

void printList(std::list<int> &list) {
  for (auto element : list) {
    std::cout << element << ", ";
  }
  std::cout << "\n";
}

void printArray(std::array<int, 8> &array) {
  for (auto element : array) {
    std::cout << element << ", ";
  }
  std::cout << "\n";
}

std::array<int, 8> listToArray(std::list<int> &list) {
  std::array<int, 8> array;
  auto listElement = list.begin();
  for (size_t i = 0; i < list.size(); ++i) {
    array[i] = *listElement;
    std::advance(listElement, 1);
  }
  return array;
}
int main() {
  std::list<int> list = {0, 1, 2, 3, 4, 5};
  auto listBegin = list.begin();
  printList(list);

  std::advance(listBegin, 2);
  list.erase(listBegin);
  printList(list);

  list.push_front(10);
  list.push_back(10);
  printList(list);

  std::advance(listBegin, 3);
  list.insert(listBegin, 20);
  printList(list);

  std::array<int, 8> array = listToArray(list);
  printArray(array);
  return 0;
}