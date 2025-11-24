#include "student.hpp"

Student::Student(const std::string &name, const std::string &surname,
                 const std::string &adress, const size_t index_number,
                 const size_t ID, const Sex &sex)
    : name_(name), surname_(surname), adress_(adress),
      index_number_(index_number), ID_(ID), sex_(sex) {}

Student::~Student(){};
std::string Student::getName() const { return this->name_; }
std::string Student::getSurname() const { return this->surname_; }
std::string Student::getAdress() const { return this->adress_; }
size_t Student::getIndexNumber() const { return this->index_number_; }
size_t Student::getID() const { return this->ID_; }
std::string Student::sexString() const {
  return sex_ == Sex::Male ? "Mężczyzna" : "Kobieta";
}

void Student::printStudent() const {
  std::cout << "Imie: " << this->getName() << "\n";
  std::cout << "Nazwisko: " << this->getSurname() << "\n";
  std::cout << "Adres: " << this->getAdress() << "\n";
  std::cout << "Numer indexu: " << this->getIndexNumber() << "\n";
  std::cout << "Pesel: " << this->getID() << "\n";
  std::cout << "Płeć: " << this->sexString() << "\n";
  std::cout << "\n";
};