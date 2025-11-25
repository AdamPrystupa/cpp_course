#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"
#include <iostream>

class Student : public Person {
private:
  size_t index_number_;

public:
  size_t getIndexNumber() const;
  void printDB(std::ostream &os) const override;

  Student(const std::string &name, const std::string &surname, const size_t ID,
          const Sex &sex, const std::string &adress, const size_t index_number);
  ~Student();
};

#endif