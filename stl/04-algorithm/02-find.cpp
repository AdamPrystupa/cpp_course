/*
Zadanie — przeszukiwanie

    Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; (ten
sam co ostatnio) Znajdź wszystkie elementy większe od 6 i wypisz je Znajdź
wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je Przeszukaj wektor v w
poszukiwaniu zakresów {6, 6} i {7, 7} Użyj std::adjacent_find na wektorze v
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main() {

  std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 7, 6, 1, 8, 9};

  //   auto it =
  //       std::find_if(begin(v), end(v), [](auto element) { return element > 6;
  //       });
  //   while (it != end(v)) {
  //     std::cout << *it << " ";
  //     it = std::find_if(std::next(it), end(v),
  //                       [](auto element) { return element > 6; });
  //   }
  std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "),
               [](auto element) { return element > 6; });
  std::cout << "\n";

  //   auto it2 = std::find_if(begin(v), end(v), [](auto element) {
  //     return element == 2 || element == 4 || element == 6 || element == 8;
  //   });
  //   while (it2 != end(v)) {
  //     std::cout << *it2 << " ";
  //     it2 = std::find_if(std::next(it2), end(v), [](auto element) {
  //       return element == 2 || element == 4 || element == 6 || element == 8;
  //     });
  //   }

  std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "),
               [](auto element) {
                 return element == 2 || element == 4 || element == 6 ||
                        element == 8;
               });
  std::cout << "\n";

  auto it3 = std::search_n(begin(v), end(v), 2, 6);
  auto it4 = std::search_n(begin(v), end(v), 2, 7);
  if (it3 != end(v) || it4 != end(v)) {
    std::cout << "znaleziono\n";
  }

<<<<<<< Updated upstream
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> Stashed changes
  //   auto found = std::ranges::search(v, std::vector{6, 6});
  //   if (!found.empty()) {
  //     for (const auto element : found) {
  //       std::cout << element << " ";
  //     }
  //     std::cout << "\n";
  //   }

<<<<<<< Updated upstream
>>>>>>> fa76a0a (learning algorithms)
=======
>>>>>>> refs/remotes/origin/main
=======
>>>>>>> Stashed changes
  return 0;
}
