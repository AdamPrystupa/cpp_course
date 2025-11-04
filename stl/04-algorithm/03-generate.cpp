/*
std::transform

std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> list {10, 20, 30 , 40 , 50, 60, 70, 80};
std::transform(begin(vec),
               end(vec),
               begin(list),
               begin(vec),
               [](auto first, auto second) {
                   return first + second;
               });
// vec = {11, 22, 33, 44, 55, 66, 77, 88}
}

std::generate*

std::vector<int> vec(10);
std::generate(begin(vec), end(vec), [i{0}]() mutable { return i++; });
// vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

std::mt19937 rng;
std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, "
"), 5, std::ref(rng));
// Possible output: 3499211612 581869302 3890346734 3586334585 545404204

std::generate* vs std::transform

    std::generate generuje wartości "z niczego"
    std::transform transformuje wartości z innego kontenera
    Oba biorą funktor mówiący jak generować/transformować elementy
    Aby wrzucać nowe elementy, użyj std::back_inserter(v) jako iterator docelowy
    Możesz użyć std::ostream_iterator<T>(std::cout, " ") jako iterator docelowy,
aby wyświetlić wynik na ekranie!


Zadanie

    Utwórz poniższy wektor:

     std::vector<std::pair<int, std::string>> v {
         {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5,
"Five"}
     };

    Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi
elementami pary) z wektora v Utwórz wektor stringów v3 i wypełnij go
konkatenacją string + dwukropek + int ze wszystkich par z wektora v Utwórz
wektor charów v4 i wypełnij go co drugą literą alfabetu
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::pair<int, std::string>> v{{0, "Zero"}, {1, "One"},
                                             {2, "Two"},  {3, "Three"},
                                             {4, "Four"}, {5, "Five"}};
  std::vector<int> v2;
  std::vector<std::string> v3;
  std::vector<char> v4;

  auto fun2 = [](auto element) {
    std::string result = element.second + ": " + std::to_string(element.first);
    return result;
  };

  std::transform(begin(v), end(v), std::back_inserter(v2), [](auto num) {
    int result = num.first;
    return result;
  });

  for (auto element : v2) {
    std::cout << element << " ";
  }
  std::cout << "\n";

  std::transform(begin(v), end(v), std::back_inserter(v3), fun2);

  for (auto element : v3) {
    std::cout << element << " ";
  }
  std::cout << "\n";

  std::generate_n(std::back_inserter(v4), 13,
                  [c{'a' - 2}]() mutable { return c += 2; });
  for (auto element : v4) {
    std::cout << element << " ";
  }
  std::cout << "\n";
  return 0;
}
