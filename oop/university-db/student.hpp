#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>

enum class Sex { Male, Female };
class Student {
private:
  std::string name_;
  std::string surname_;
  std::string adress_;
  size_t index_number_;
  size_t ID_;
  Sex sex_;

public:
  std::string getName() const;
  std::string getSurname() const;
  std::string getAdress() const;
  size_t getIndexNumber() const;
  size_t getID() const;
  std::string sexString() const;
  void printStudent() const;

  Student(const std::string &name, const std::string &surname,
          const std::string &adress, const size_t index_number, const size_t ID,
          const Sex &sex);
  ~Student();
};

#endif