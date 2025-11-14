/*
Zadanie 1 - inner-product

Zaimplementuj funkcję ArithmeticAverage(), która bierze 2 wektory intów i
oblicza średnią arytmetyczną wszystkich wartości

Input: {1, 2, 3, 4} {1, 2, 3, 4} Output: 2.5

Zaimplementuj funkcję Distance(), która bierze 2 wektory intów (jako współrzędne
punktów w przestrzeni n-wymiarowej) i oblicza odległość między nimi.

Input: {7, 4, 3} {17, 6, 2} Output: 10.247
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>

template <typename T> void print(T &container) {
  for (const auto &element : container) {
    std::cout << element << " ";
  }
  std::cout << "\n";
}

double ArithmeticAverage(const std::vector<int> &vec1,
                         const std::vector<int> &vec2) {
  double sum = std::inner_product(begin(vec1), end(vec1), begin(vec2), 0,
                                  std::plus<>(), std::plus<>());
  return sum / (vec1.size() * 2);
}

double Distance(const std::vector<int> &vec1, const std::vector<int> &vec2) {
  double distance =
      std::sqrt(std::inner_product(begin(vec1), end(vec1), begin(vec2), 0,
                                   std::plus<>(), [](auto &a, auto &b) {
                                     double result = (a - b) * (a - b);
                                     return result;
                                   }));
  return distance;
}

int main() {
  std::vector<int> vec1 = {1, 2, 3, 4};
  std::vector<int> vec2 = {1, 2, 3, 4};

  std::vector<int> vec3 = {7, 4, 3};
  std::vector<int> vec4 = {17, 6, 2};

  std::cout << ArithmeticAverage(vec1, vec2) << "\n";

  std::cout << Distance(vec3, vec4) << "\n";

  return 0;
}