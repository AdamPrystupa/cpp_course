/*Przykład : emplace_hint()

               int main() {
  std::map<int, std::string> map;

  auto it = map.begin();
  map.emplace_hint(it, 10, "Ten");

  std::cout << map[10] << '\n';
}

Output : Ten

             Podpowiadamy mapie miejsce,
         gdzie powinna wstawić element,
         dzięki temu taka operacja będzie miała złożoność O(1)
             .Podpowiedź to iterator,
         przed którym dany element powinien być wstawiony.

         Gdy podany iterator jest niepoprawną wskazówką,
         to złożoność wstawianie jest O(log n).Przykład : insert_or_assign()

                                                              int main() {
  std::map<int, std::string> map;

  auto it = map.begin();
  map.insert_or_assign(it, 10, "Ten");
  std::cout << map[10] << '\n';
  map.insert_or_assign(it, 10, "Dziesiec");
  std::cout << map[10] << '\n';
  map[10] = "Cent";
  std::cout << map[10] << '\n';
}

Output :

    Ten Dziesiec Cent

        Przykład : count()

                       int main() {
  std::multimap<int, std::string> map;

  map.insert({5, "Five"});
  map.insert({5, "Funf"});
  map.insert({5, "Piec"});
  map.insert({5, "Cinq"});
  std::cout << map.count(5) << '\n';
}

Output : 4 Przykład : find()

                          int main() {
  std::multimap<int, std::string> map;

  map.insert({5, "Five"});
  map.insert({5, "Funf"});
  map.insert({5, "Piec"});
  map.insert({5, "Cinq"});
  auto it = map.find(5);

  for (; it != map.end(); ++it) {
    std::cout << it->first << " | " << it->second << '\n';
  }
}

Output :

    5 | Five 5 | Funf 5 | Piec 5 |
    Cinq

        Zadanie

            Stwórz multimapę i wypełnij ją podanymi wartościami

                map.insert({5, "Ala"});
map.insert({5, "Ma"});
map.insert({5, "Kota"});
map.insert({5, "A"});
map.insert({5, "Kot"});
map.insert({5, "Ma"});
map.insert({5, "Ale"});

Napisz funkcję, która wyświetli słowa w mapie o liczbie znaków równej 3.
*/

#include <iostream>
#include <map>

void display(std::multimap<int, std::string> &map) {
  for (auto &[k, v] : map) {
    if (v.size() == 3) {
      std::cout << v << "\n";
    }
  }
}

void pritnMap(std::multimap<int, std::string> &map) {
  for (auto &[k, v] : map) {
    std::cout << k << " | " << v << "\n";
  }
}

int main() {
  std::multimap<int, std::string> map;
  map.insert({5, "Ma"});
  map.insert({5, "Kota"});
  map.insert({5, "A"});
  map.insert({5, "Kot"});
  map.insert({5, "Ma"});
  map.insert({5, "Ale"});
  pritnMap(map);
  display(map);
}