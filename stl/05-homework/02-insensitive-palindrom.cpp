/*
Zadanie 2 - insensitive-palindrom
Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest
palindromem. Program powinien ignorować znaki specjalne np. ,.?()[] (i nie
tylko). Powinien również ignorować wielkość liter oraz białe znaki jak spacja
czy znak nowej linii.
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

auto copyLetters = []() {

};

int main() {
  std::string phrase;
  std::cout << "podaj fraze: ";
  std::getline(std::cin, phrase);
  std::string preparedLine;
  std::string reverseLine;
  std::cout << phrase << "\n";

  auto prepare = [&preparedLine](auto &c) {
    if (std::isalpha(c)) {
      preparedLine.push_back(std::tolower(c));
    }
  };

  std::for_each(begin(phrase), end(phrase), prepare);
  std::cout << preparedLine << "\n";
  std::reverse_copy(begin(preparedLine), end(preparedLine),
                    std::back_inserter(reverseLine));

  std::cout << reverseLine << "\n";
  bool isPalindrom = true;
  if (preparedLine == reverseLine)
    isPalindrom = true;
  else
    isPalindrom = false;
  std::cout << std::boolalpha << isPalindrom;
  return 0;
}