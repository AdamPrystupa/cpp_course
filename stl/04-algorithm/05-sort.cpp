/*
Zadanie 💻

struct Point { int x, y; }

    Utwórz std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0,
2}, {2, 2}}; Utwórz funkcję do wypisywania zawartości kontenera d Napisz 2
komparatory: pointXCompare, który porównuje tylko wartości x ze struktury Point
        pointYCompare, który porównuje tylko wartości y ze struktury Point
    Sprawdź czy d jest posortowane względem pointXCompare oraz pointYCompare
    Użyj stable_sort do posortowania d względem wartości x
    Użyj sort do posortowania d względem wartości y
*/
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <random>
#include <string>

struct Point {
  int pointX;
  int pointY;
};

template <typename Container> const void print(Container &deque) {
  std::cout << "{";
  for (const auto &element : deque) {

    std::cout << "{" << element.pointX << ", " << element.pointY << "}";
  }
  std::cout << "}\n";
}

int main() {
  std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4},
                         {4, 1}, {0, 2}, {2, 2}};
  auto pointXCompare = [](const auto &lhs, const auto &rhs) {
    return lhs.pointX < rhs.pointX;
  };
  auto pointYCompare = [](const auto &lhs, const auto &rhs) {
    return lhs.pointY < rhs.pointY;
  };
  print(d);
  std::cout << std::boolalpha << std::is_sorted(begin(d), end(d), pointXCompare)
            << "\n";
  std::cout << std::boolalpha << std::is_sorted(begin(d), end(d), pointYCompare)
            << "\n";

  std::stable_sort(begin(d), end(d), pointXCompare);
  std::cout << std::boolalpha << std::is_sorted(begin(d), end(d), pointXCompare)
            << "\n";
  std::sort(begin(d), end(d), pointYCompare);

  std::cout << std::boolalpha << std::is_sorted(begin(d), end(d), pointYCompare)
            << "\n";

  return 0;
}
