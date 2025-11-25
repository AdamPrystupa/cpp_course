#include "generator.hpp"
#include "student.hpp"
#include "worker.hpp"
#include <iostream>

void Generator::generateData(DB &db, size_t count) {
  std::uniform_int_distribution<> typeDist(0, 1);
  std::uniform_int_distribution<> sexDist(0, 1);

  for (size_t i = 0; i < count; ++i) {
    bool isMale = sexDist(rng);
    Sex sex = isMale ? Sex::Male : Sex::Female;
    std::string name = getRandomName(isMale);
    std::string surname = getRandomSurname();

    if (!isMale && surname.back() == 'i') {
      surname.back() = 'a';
    }

    std::string address = getRandomAddress();
    size_t pesel = generatePESEL();

    if (typeDist(rng) == 0) {
      auto student = std::make_shared<Student>(name, surname, pesel, sex,
                                               address, generateIndexNumber());
      db.addNewPerson(student);
    } else {
      auto worker = std::make_shared<Worker>(name, surname, pesel, sex, address,
                                             generateSalary());
      db.addNewPerson(worker);
    }
  }
}

std::string Generator::getRandomName(bool isMale) {
  if (isMale) {
    std::uniform_int_distribution<> dist(0, maleNames.size() - 1);
    return maleNames[dist(rng)];
  } else {
    std::uniform_int_distribution<> dist(0, femaleNames.size() - 1);
    return femaleNames[dist(rng)];
  }
}

std::string Generator::getRandomSurname() {
  std::uniform_int_distribution<> dist(0, surnames.size() - 1);
  return surnames[dist(rng)];
}

std::string Generator::getRandomAddress() {
  std::uniform_int_distribution<> cityDist(0, cities.size() - 1);
  std::uniform_int_distribution<> streetDist(0, streets.size() - 1);
  std::uniform_int_distribution<> numDist(1, 150);

  return cities[cityDist(rng)] + ", ul. " + streets[streetDist(rng)] + " " +
         std::to_string(numDist(rng));
}

size_t Generator::generatePESEL() {
  std::uniform_int_distribution<size_t> dist(10000000000, 99999999999);
  return dist(rng);
}

size_t Generator::generateIndexNumber() {
  std::uniform_int_distribution<size_t> dist(10000, 99999);
  return dist(rng);
}

size_t Generator::generateSalary() {
  std::uniform_int_distribution<size_t> dist(3000, 15000);
  return dist(rng);
}