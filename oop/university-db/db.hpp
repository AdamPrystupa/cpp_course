#ifndef DB_HPP
#define DB_HPP

#include "student.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

class DB {
private:
  std::vector<Student> db;

public:
  DB();
  ~DB();
  void addNewStudent(const Student &newStudent);
  void printDB();
  void searchBySurname(const std::string &surname);
  void searchByID(const size_t ID);
  void sortByID();
  void sortBySurname();
  void removeByName(const std::string &name);
};

#endif