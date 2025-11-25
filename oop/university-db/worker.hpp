#ifndef WORKER_HPP
#define WORKER_HPP

#include "person.hpp"
#include <iostream>

class Worker : public Person {
private:
  size_t salary_;

public:
  Worker(const std::string &name, const std::string &surname, const size_t ID,
         const Sex &sex, const std::string &adress, const size_t salary);
  ~Worker();

  void printDB(std::ostream &os) const override;
  size_t getSalary() const;
  void setSalary(size_t newSalary);
};

#endif