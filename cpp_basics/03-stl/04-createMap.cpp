#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

// Implement createMap. It should take a vector and list and
// return a map of merge them as keys from the vector and values from the list

std::map<size_t, std::string> createMap(std::vector<int> &vec,
                                        std::list<std::string> &list) {
  std::map<size_t, std::string> map;
  int temp = 0;
  if (list.size() != vec.size())
    return {};
  for (auto const &element : list) {
    map.insert({vec[temp], element});
    temp++;
  }
  return map;
}

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::list<std::string> list{"One", "Two", "Three", "Four", "Five"};
  auto map = createMap(vec, list);

  for (const auto &pair : map)
    std::cout << pair.first << " | " << pair.second << '\n';

  return 0;
}