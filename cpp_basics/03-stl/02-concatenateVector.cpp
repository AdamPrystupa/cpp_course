#include <iostream>
#include <vector>

// Implement concatenateVector.
// It should take 2 vectors and return one which has alternately elements from
// the first and the other one.

std::vector<int> concatenateVector(std::vector<int> &vec1,
                                   std::vector<int> &vec2) {
  std::vector<int> vec;
  if (vec1.size() == vec2.size())
    for (size_t i = 0; i < vec1.size(); i++) {
      vec.push_back(vec1[i]);
      vec.push_back(vec2[i]);
    }
  else if (vec1.size() > vec2.size())
    for (size_t i = 0; i < vec1.size(); i++) {
      vec.push_back(vec1[i]);
      if (i < vec2.size())
        vec.push_back(vec2[i]);
    }
  else
    for (size_t i = 0; i < vec2.size(); i++) {
      if (i < vec1.size())
        vec.push_back(vec1[i]);
      vec.push_back(vec2[i]);
    }
  return vec;
}

int main() {
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{11, 12, 13, 14, 15};

  auto vec = concatenateVector(vec1, vec2);
  for (const auto &el : vec) {
    std::cout << el << " ";
  }
  return 0;
}