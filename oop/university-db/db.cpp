#include "db.hpp"

DB::DB(){};
DB::~DB(){};

void DB::addNewStudent(const Student &newStudent) { db.push_back(newStudent); }
void DB::printDB() {
  for (auto el : db) {
    el.printStudent();
  }
};

void DB::searchBySurname(const std::string &surname) {
  for (auto el : db) {
    if (el.getSurname() == surname)
      el.printStudent();
  }
};

void DB::searchByID(const size_t ID) {
  for (auto el : db) {
    if (el.getID() == ID)
      el.printStudent();
  }
};

void DB::sortByID() {
  std::sort(begin(db), end(db),
            [](auto a, auto b) { return a.getID() < b.getID(); });
};
void DB::sortBySurname() {
  std::sort(begin(db), end(db),
            [](auto a, auto b) { return a.getSurname() < b.getSurname(); });
};
void DB::removeByName(const std::string &name) {
  auto studentToRemove = std::find_if(
      begin(db), end(db), [&name](auto el) { return el.getName() == name; });
  db.erase(studentToRemove);
};