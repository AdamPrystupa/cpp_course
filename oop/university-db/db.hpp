#ifndef DB_HPP
#define DB_HPP

#include "person.hpp"
#include "student.hpp"
#include "worker.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class DB {
private:
  std::vector<std::shared_ptr<Person>> db{};

public:
  DB();
  ~DB();
  void addNewPerson(std::shared_ptr<Person> newPerson);
  void printDB();
  void searchBySurname(const std::string &surname);
  void searchByID(const size_t ID);
  void sortByID();
  void sortBySurname();
  void sortBySalary();
  void removeByName(const std::string &name);
  void changeSalaryByID(const size_t ID, const size_t newSalary);
};

#endif