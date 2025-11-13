/*

Cechy std::set<K>, std::multiset<K>

    Te same co w std::map&lt;K, V&gt; i std::multimap&lt;K, V&gt;
    Jedyna różnica jest taka, że set i multiset przechowują tylko klucze (a nie
pary klucz-wartość) Idealne, gdy chcesz mieć zawsze posortowane elementy

Jeśli nie ma potrzeby, aby elementy były zawsze posortowane, to lepszym wyborem
może być std::vector<T>. Można go posortować tylko wtedy gdy jest to potrzebne
za pomocą algorytmu std::sort()

Jeśli zależy nam na braku duplikatów możemy też wtedy użyć algorytmu
std::unique(). Metody std::set<K> i std::multiset<K>

std::set<K, T> on cppreference.org

std::multiset<K, T> on cppreference.org

    dodawanie elementu: insert(), emplace(), emplace_hint()
    modyfikowanie/dostęp do elementu: przez iteratory
    rozmiar/pusty: size(), empty()
    wyczyszczenie nieużywanej pamięci: brak
    pierwszy/ostatni element: brak
    odwrócony (ang. reverse) iterator: rbegin(), rend()
    stały iterator: cbegin(), cend(), crbegin(), crend()
    wyczyszczenie kontenera: clear()
    przygotowanie do usunięcia: brak
    wymazanie elementów z pamięci: erase()
    podmiana całego kontenera: swap()
    zliczenie elementów: count() (dla set zwraca tylko 0 albo 1, dla multiset
liczbę od 0 do size()) odnalezienie elementu o podanym kluczu: find() czy klucz
istnieje (C++20): contains()

Złożoność operacji

    Wstawianie/usuwanie
        O(log n)
    Dostęp
        O(log n)
    Wyszukiwanie
        O(log n)

Zużycie pamięci

    n * (sizeof(K) + 2 * sizeof(X*))
    O(n)
    Dodatkowe wewnętrzne dane: root, compare, allocator

Unieważnienie iteratorów

    Bidirectional Iterators
    Dodawanie, usuwanie i przenoszenie elementów nie unieważnia iteratorów lub
referencji Iterator jest unieważniany tylko wtedy, gdy dany element jest usuwany

Przykład użycia std::set<K>

std::vector<int> v = {5, 4, 3, 5, 2, 1, 1, 0, 6, 8, 7, 2};
std::set<int> set {v.begin(), v.end()};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';

std::set<int, std::greater<int>> set2 {v.begin(), v.end()};
for (const auto el : set2) {
    std::cout << el << ' ';
}
std::cout << '\n';

Output:

0 1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1 0

Przykład użycia std::multiset<K>

std::vector<int> v = {5, 4, 3, 2, 1, 0, 6, 8, 7, 1, 2, 3, 4, 5, 6};
std::multiset<int> set {v.begin(), v.end()};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';

std::multiset<int, std::greater<int>> set2 {v.begin(), v.end()};
for (const auto el : set2) {
    std::cout << el << ' ';
}
std::cout << '\n';

Output:

0 1 1 2 2 3 3 4 4 5 5 6 6 7 8
8 7 6 6 5 5 4 4 3 3 2 2 1 1 0

Zadanie

    Wygeneruj zbiór liczb od -20 do 20 i zapisz go w std::set w kolejności
malejącej
Wstaw nowe elementy: -10, 0, 10, 100, -100
Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w std::multiset
Wstaw nowe elementy: -10, 0, 10, 100, -100
Połącz oba zbiory w jeden (ma to być std::multiset)
Znajdź wszystkie elementy równe 0 i 50

Co każdy krok wypisuj zawartości kontenerów.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>

template <typename T> void print(const T &container) {
  for (const auto &l : container) {
    std::cout << l << " ";
  }
  std::cout << "\n";
}

int main() {
  std::set<int, std::greater<int>> set;

  for (int i = -20; i <= 20; ++i) {
    set.insert(i);
  }
  print(set);
  set.insert(-10);
  set.insert(0);
  set.insert(10);
  set.insert(100);
  set.insert(-100);

  print(set);

  std::multiset<int> multiSet;

  for (int i = 0; i <= 40; ++i) {
    multiSet.insert(i);
  }
  print(multiSet);

  multiSet.insert(-10);
  multiSet.insert(0);
  multiSet.insert(10);
  multiSet.insert(100);
  multiSet.insert(-100);

  print(multiSet);
  std::multiset<int> finalSet;

  multiSet.merge(set);
  print(multiSet);

  std::copy_if(
      begin(multiSet), end(multiSet),
      std::ostream_iterator<int>(std::cout, " "),
      [](const auto &element) { return element == 50 || element == 0; });

  return 0;
}