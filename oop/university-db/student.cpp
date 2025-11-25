#include "student.hpp"

Student::Student(const std::string &name, const std::string &surname,
                 const size_t ID, const Sex &sex, const std::string &adress,
                 const size_t index_number)
    : Person(name, surname, ID, sex, adress), index_number_(index_number) {}

Student::~Student(){};

size_t Student::getIndexNumber() const { return this->index_number_; }

void Student::printDB(std::ostream &os) const {
  Person::printDB(os);
  os << "Numer indeksu: " << index_number_ << "\n\n";
}