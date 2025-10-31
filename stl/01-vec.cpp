#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 4, 5, 6};
  vec.erase(vec.begin(), vec.begin() + 1);
  vec.push_back(5);
  vec.emplace(vec.end(), 12);
  std::cout << "Size: " << vec.size() << ", max size: " << vec.capacity()
            << "\n";
  for (auto element : vec)
    std::cout << element << ", ";
  std::cout << "\n";
  vec.clear();
  std::cout << "Size: " << vec.size() << ", max size: " << vec.capacity()
            << "\n";
  return 0;
}