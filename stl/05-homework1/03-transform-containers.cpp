/*
03- transformContainers

    Napisz funkcję transformContainers, która przyjmie std::list<std::string>
oraz std::deque<int> Usunie duplikaty z obu kontenerów Na koniec skonwertuje to
na std::map<int, std::string> i ją zwróci. Użyj std::transform.

*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <string>

void printD(std::deque<int> &d) {
  for (const auto &element : d) {
    std::cout << element << ", ";
  }
  std::cout << "\n";
}

void printL(std::list<std::string> &l) {
  for (const auto &element : l) {
    std::cout << element << ", ";
  }
  std::cout << "\n";
}

void printMap(std::map<int, std::string> &map) {
  for (const auto &element : map) {
    std::cout << element.first << ": " << element.second << ", ";
  }
  std::cout << "\n";
}

int main() {
  std::deque<int> d = {1, 2, 3, 1, 1, 4, 2, 3};
  std::list<std::string> l = {"adam", "kasia", "ola", "szymon",
                              "adam", "ola",   "ola", "kasia"};
  std::map<int, std::string> map;
  std::sort(begin(d), end(d));
  l.sort();
  auto lastD = std::unique(begin(d), end(d));
  d.erase(lastD, end(d));
  auto lastL = std::unique(begin(l), end(l));
  l.erase(lastL, end(l));
  std::transform(begin(d), end(d), begin(l), std::inserter(map, map.end()),
                 [](const int &key, const std::string &word) {
                   return std::make_pair(key, word);
                 });

  printMap(map);
  return 0;
}