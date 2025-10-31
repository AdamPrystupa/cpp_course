// Napisz funkcję,
//     która przyjmuje 2 argumenty :

//     int count int step

//         oraz zwraca std::vector<int>
//             posiadający count elementów i każdy z nich jest większy od
//                 poprzedniego o step.Pierwszy ma wynosić tyle,
//     ile step.Przykład użycia

//     auto result = generateSequence(5, 3); // result = {3, 6, 9, 12, 15}

#include <iostream>
#include <vector>

std::vector<int> generateSequence(int count, int step) {
  std::vector<int> result;
  int sum = 0;
  for (size_t i = 0; i < count; i++) {
    sum += step;
    result.push_back(sum);
  }
  return result;
}

int main() {

  auto result = generateSequence(5, 3); // result = {3, 6, 9, 12, 15}
  for (size_t element : result)
    std::cout << element << ", ";
  std::cout << "\n";
  return 0;
}