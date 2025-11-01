/*
Zadanie:

    Znajdź dokumentację std::forward_list na cppreference.com
    Skorzystaj z kodu z zadania std::list
    Stwórz listę jednokierunkową zawierającą elementy od 0 do 6
    Wyświetl listę
    Usuń trzeci element z listy
    Dodaj na początek i na koniec listy wartość 10
    Wyświetl listę
    Dodaj na czwartej pozycji liczbę 20
    Wyświetl listę

*/

#include <forward_list>
#include <iostream>
#include <list>

void printFList(std::forward_list<int> &fList) {
  for (auto element : fList) {
    std::cout << element << ", ";
  }
  std::cout << "\n";
}

int main() {
  std::forward_list<int> fList = {0, 1, 2, 3, 4, 5, 6};
  printFList(fList);

  auto it = fList.begin();
  std::advance(it, 1);
  fList.erase_after(it);
  printFList(fList);

  auto it2 = fList.begin();
  std::advance(it2, 5);
  fList.insert_after(fList.before_begin(), 10);
  fList.emplace_after(it2, 10);
  printFList(fList);

  auto it3 = fList.begin();
  std::advance(it3, 2);
  fList.insert_after(it3, 20);
  printFList(fList);

  return 0;
}