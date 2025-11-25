#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "db.hpp"
#include <random>
#include <string>
#include <vector>

class Generator {
public:
  void generateData(DB &db, size_t count);

private:
  std::mt19937 rng{std::random_device{}()};

  std::string getRandomName(bool isMale);
  std::string getRandomSurname();
  std::string getRandomAddress();
  size_t generatePESEL();
  size_t generateIndexNumber();
  size_t generateSalary();

  const std::vector<std::string> maleNames = {
      "Jan", "Piotr", "Michal", "Pawel", "Jakub", "Adam", "Krzysztof"};
  const std::vector<std::string> femaleNames = {
      "Anna", "Katarzyna", "Maria", "Agnieszka", "Ewa", "Magdalena", "Monika"};
  const std::vector<std::string> surnames = {
      "Kowalski",  "Nowak",    "Wisniewski", "Wojcik",
      "Kowalczyk", "Kaminski", "Lewandowski"};
  const std::vector<std::string> cities = {"Warszawa", "Krakow", "Wroclaw",
                                           "Gdansk",   "Poznan", "Lodz"};
  const std::vector<std::string> streets = {"Polna",  "Lesna", "Sloneczna",
                                            "Krotka", "Dluga", "Ogrodowa"};
};

#endif