/*
Napisz funkcję lengthSort().

Ma ona przyjąć std::forward_list<std::string> i zwrócić std::deque<std::string>
z posortowanymi słowami od najkrótszego do najdłuższego. Jeżeli dwa lub więcej
słów ma tyle samo znaków posortuj je leksykograficznie.

    Input: std::forward_list<std::string>{"Three", "One", "Four", "Two"}
    Output: std::deque<std::string>{"One", "Two", "Four", "Three"}
*/

#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <string>

bool compareByLengthThenLex(const std::string &a, const std::string &b) {
  if (a.length() != b.length()) {
    return a.length() < b.length();
  }
  return a < b;
}

std::deque<std::string> lengthSort(const std::forward_list<std::string> &fl) {
  std::deque<std::string> sortedDeque(fl.begin(), fl.end());
  std::sort(sortedDeque.begin(), sortedDeque.end(), compareByLengthThenLex);
  return sortedDeque;
}

void printDeque(const std::deque<std::string> &dq) {
  std::cout << "{";
  for (auto it = dq.begin(); it != dq.end(); ++it) {
    std::cout << *it;
    if (std::next(it) != dq.end()) {
      std::cout << ", ";
    }
  }
  std::cout << "}" << std::endl;
}

int main() {
  std::forward_list<std::string> input = {"Three", "One",      "Four",  "Two",
                                          "Six",   "Seventah", "eleven"};

  std::deque<std::string> output = lengthSort(input);

  std::cout << "Output: ";
  printDeque(output);

  return 0;
}