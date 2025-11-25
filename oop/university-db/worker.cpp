#include "worker.hpp"

Worker::Worker(const std::string &name, const std::string &surname,
               const size_t ID, const Sex &sex, const std::string &adress,
               const size_t salary)
    : Person(name, surname, ID, sex, adress), salary_(salary) {}

Worker::~Worker() {}

size_t Worker::getSalary() const { return this->salary_; }

void Worker::setSalary(size_t newSalary) { this->salary_ = newSalary; }

void Worker::printDB(std::ostream &os) const {
  Person::printDB(os);
  os << "Zarobki: " << salary_ << "\n\n";
}