/*
std::iota

std::list<char> l(10);
std::iota(l.begin(), l.end(), 'C');
// l = {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}

Wypełnia zakres sekwencyjnie rosnącymi wartościami.
Operacje redukcji
std::accumulate vs std::reduce

std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = std::accumulate(v.begin(), v.end(), 0);
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
// sum = 55, product = 3628800

sum = std::reduce(std::execution::par, v.begin(), v.end(), 0);
product = std::reduce(v.begin(), v.end(), 1, std::multiplies<int>());
// sum = 55, product = 3628800

    std::accumulate oblicza sumę podanego zakresu + init. Można dostarczyć
własną funkcję zamiast standardowego sumowania. std::reduce (C++17) robi
dokładnie to samo, ale kolejność dodawania poszczególnych elementów jest
dowolna. To może mieć znaczenie podczas wykonywania tego algorytmu współbieżnie.
Może przyjąć dodatkowy argument std::execution_policy, aby wykonać obliczenia
współbieżnie. Preferuj std::reduce

Operacje skanowania
std::partial_sum vs std::inclusive_scan vs std::exclusive_scan

std::vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10,
2); std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "
"));
// output: 2 4 6 8 10 12 14 16 18 20

std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
// v = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}

v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
std::inclusive_scan(v.begin(), v.end(), v.begin(), std::multiplies<int>());
// v = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}

v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
std::exclusive_scan(v.begin(), v.end(), v.begin(), 1, std::multiplies<int>());
// v = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}

    std::partial_sum oblicza sumę częściową (od początku zakresu do obecnie
przetwarzanego elementu). Można dostarczyć własną funkcję zamiast standardowego
sumowania. std::inclusive_scan robi dokładnie to samo. std::exclusive_scan robi
dokładnie to samo, ale obecny element nie jest brany pod uwagę (obliczamy do
poprzedniego elementu).

std::adjacent_difference

std::vector v {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
std::adjacent_difference(v.begin(), v.end(), v.begin());
// v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

std::vector w {-100, 2, 4, 8, 16, 32};
std::adjacent_difference(w.begin(), w.end(), w.begin());
// w = {-100, 102, 2, 4, 8, 16}

    std::adjacent_difference oblicza różnicę pomiędzy parami sąsiadujących
elementów

Operacji transformacji z redukcją
std::transform_reduce vs std::inner_product

std::vector<int> a{0, 1, 2, 3, 4};
std::vector<int> b{5, 4, 2, 3, 1};

int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
// 0 x 5 + 1 x 4 + 2 x 2 + 3 x 3 + 4 x 1
// r1 = 21

int r2 = std::irnner_poduct(a.begin(), a.end(), b.begin(), 0,
                            std::plus<>(), std::equal_to<>());
// (0 == 5) + (1 == 4) + (2 == 2) + (3 == 3) + (4 == 1)
// r2 = 2

int r3 = std::transform_reduce(a.begin(), a.end(), b.begin(), 0);
int r4 = std::transform_reduce(a.begin(), a.end(), b.begin(), 0,
                               std::plus<>(), std::equal_to<>());

    std::inner_product oblicza iloczyn skalarny 2 zakresów. Można dostarczyć
własne operacja zamiast standardowych (op1 - sumowanie i op2 - mnożenie)
    std::transform_reduce robi to samo, ale można go używać współbieżnie.
Wymaga, aby obie operacje były przemienne i łączne.

Zadanie

    Utwórz wektor v1 z liczbami od 1 do 1000
    Oblicz sumę tych liczb
    Utwórz wektor v2 z 1000 elementów powtarzających się w następującej
sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ... Oblicz iloczyn skalarny wektorów v1 i
v2 Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z
wektora v2
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

template <typename Container> const void print(Container &vec) {
  std::cout << "{";
  for (const auto &element : vec) {
    std::cout << element << " ";
  }
  std::cout << "}\n";
}

auto gen = [index = 1]() mutable {
  size_t result;
  if (index % 4 == 1) {
    result = -1;
  } else if (index % 4 == 3) {
    result = 1;
  } else
    result = 0;
  index++;
  return result;
};

auto comp = [](auto element1, auto element2) {
  if (element2 == 1)
    return element1;
  else
    return 0;
};

int main() {
  std::vector<int> v1(1000);
  std::vector<int> v2(1000);
  std::iota(begin(v1), end(v1), 1);
  print(v1);
  size_t sum = std::accumulate(begin(v1), end(v1), 0);
  std::cout << sum << "\n";

  std::generate_n(begin(v2), 1000, gen);
  print(v2);

  int r1 = std::inner_product(begin(v1), end(v1), begin(v2), 0);
  std::cout << r1 << "\n";

  int r2 = std::transform_reduce(begin(v1), end(v1), begin(v2), 0,
                                 std::plus<>(), comp);

  std::cout << r2 << "\n";
  return 0;
}