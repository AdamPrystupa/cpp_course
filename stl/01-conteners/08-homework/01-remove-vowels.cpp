/*
Napisz funkcję removeVowels(), która przyjmie std::vector<std::string> oraz
usunie wszystkie samogłoski z tych wyrażeń.

    Input: {"abcde", "aabbbccabc", "qwerty"}
    Output: {"bcd", "bbccbc", "qwrt"}
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void removeVowels(std::vector<std::string> &vec) {

  for (auto &element : vec) {
    element.erase(std::remove_if(element.begin(), element.end(),
                                 [](char x) {
                                   return x == 'a' || x == 'e' || x == 'i' ||
                                          x == 'o' || x == 'u' || x == 'y' ||
                                          x == 'A' || x == 'E' || x == 'I' ||
                                          x == 'O' || x == 'U' || x == 'Y';
                                 }),
                  element.end());
  }
}

void printVector(std::vector<std::string> &vec) {
  for (auto element : vec) {
    std::cout << element << ", ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<std::string> input = {"abcdE", "aAbbbccabc", "qwErty"};
  removeVowels(input);
  printVector(input);
  return 0;
}