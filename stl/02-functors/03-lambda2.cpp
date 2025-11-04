/*
Utwórz std::vector<int> i wypełnij go dowolnymi wartościami
Utwórz lambdę, która przechwyci ten wektor, oraz wyświetli jego zawartość
Utwórz lambdę, która w swoim argumencie przyjmie int i go wyświetli
Wykorzystaj lambdę z pkt. 6 w algorytmie std::for_each() do wyświetlenia całego
kontenera
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {12, 4, 12, 5,   1,  2, 3,   544142, 354, 1,
                          23, 5, 1,  235, 43, 5, 746, 65645,  6};
  auto lambda1 = [&vec]() {
    for (auto element : vec) {
      std::cout << element << " ";
    }
    std::cout << "\n";
  };
  auto lambda2 = [](int element) { std::cout << element << " "; };
  lambda1();
  std::for_each(begin(vec), end(vec), lambda2);

  return 0;
}