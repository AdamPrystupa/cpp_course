/*
std::reverse*, std::rotate*, std::shift*

int a[] = {4, 5, 6, 7};
std::reverse(std::begin(a), std::end(a));
// a = {7, 6, 5, 4};

std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
std::rotate(v.begin(), v.begin() + 3, v.end());
// v = {0, 5, 10, 7, 3, 7, 1, 2, 4, 2}

std::vector<std::string>  c{"a", "b", "c", "d", "e", "f", "g"};
std::shift_left(begin(c), end(c), 3);
// c = {"d", "e", "f", "g", "", "", ""}
std::shift_right(begin(c), end(c), 2);
// c = {"", "", "d", "e", "f", "g", ""}

    std::reverse odwraca kolejność elementów
    std::rotate bierze 3 iteratory: first, middle, last. Po obrocie middle jest
pierwszym elementem, a zakres [first, middle) jest na końcu.
    std::shift_left/std::shift_right (C++20) przesuwa wszystkie elementy o N
pozycji w lewo/prawo

std::shuffle

std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::random_device rd;
std::mt19937 g(rd());
std::shuffle(v.begin(), v.end(), g);
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    std::shuffle zmienia kolejność elementów używając dostarczonego generatora
liczb losowych

Zadanie

    Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    Usuń wszystkie duplikaty z v
    Wypisz wszystkie elementy, używając std::copy i std::ostream_iterator
    Pomieszaj losowo wszystkie elementy
    Wypisz je raz jeszcze
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

int main() {
  std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

  auto it = std::unique(begin(v), end(v));
  v.erase(it, end(v));

  std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(begin(v), end(v), g);
  std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));

  return 0;
}
