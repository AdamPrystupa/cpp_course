/*
Zadanie

Napisz funkcję middle, która może być wywoływana na różnych kontenerach. Funkcja
ta powinna zwracać środkowy element w kolekcji. Napisz ją w konwencji algorytmów
z biblioteki STL, czyli jako argumenty chcemy podać 2 iteratory:

auto middle(Iter first, Iter last);

Za Iter musisz podstawić właściwe typy parametrów i napisać kilka przeciążeń tej
funkcji. Możesz też... użyć szablonów, jeśli wiesz jak :).
*/

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

template <typename Iter> auto middle(Iter first, Iter last) {
  auto mid = std::distance(first, last) / 2;
  size_t result = *std::next(first, mid);

  return result;
}

int main() {
  std::vector v = {1, 2, 3, 4, 5};
  std::list l = {1, 2, 3, 4, 5};
  std::forward_list fl = {1, 2, 3, 4, 5};
  std::cout << middle(v.begin(), v.end());
  std::cout << middle(l.begin(), l.end());
  std::cout << middle(fl.begin(), fl.end());
}
