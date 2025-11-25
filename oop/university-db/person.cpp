#include "person.hpp"

Person::Person(const std::string &name, const std::string &surname,
               const size_t ID, const Sex &sex, const std::string &adress)
    : name_(name), surname_(surname), ID_(ID), sex_(sex), adress_(adress) {}

Person::~Person() {}

// Implementacja operatora - deleguje zadanie do metody wirtualnej
std::ostream &operator<<(std::ostream &os, const Person &p) {
  p.printDB(os);
  return os;
}

// Implementacja bazowa
void Person::printDB(std::ostream &os) const {
  os << "Imie: " << name_ << "\n"
     << "Nazwisko: " << surname_ << "\n"
     << "Pesel: " << ID_ << "\n"
     << "Płeć: " << sexString() << "\n"
     << "Adres: " << this->getAdress() << "\n\n";
}

std::string Person::getName() const { return this->name_; }
std::string Person::getSurname() const { return this->surname_; }
size_t Person::getID() const { return this->ID_; }

std::string Person::sexString() const {
  return sex_ == Sex::Male ? "Mężczyzna" : "Kobieta";
}
std::string Person::getAdress() const { return this->adress_; }