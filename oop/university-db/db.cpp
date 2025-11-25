#include "db.hpp"

DB::DB() {}
DB::~DB() {}

void DB::addNewPerson(std::shared_ptr<Person> newPerson) {
  db.push_back(newPerson);
}

void DB::printDB() {
  for (const auto &el : db) {
    std::cout << *el;
  }
}

void DB::searchBySurname(const std::string &surname) {
  for (const auto &el : db) {
    if (el.get()->getSurname() == surname)
      std::cout << *el;
  }
}

void DB::searchByID(const size_t ID) {
  for (const auto &el : db) {
    if (el.get()->getID() == ID)
      std::cout << *el;
  }
}

void DB::sortByID() {
  std::sort(begin(db), end(db),
            [](auto a, auto b) { return a.get()->getID() < b.get()->getID(); });
}
void DB::sortBySurname() {
  std::sort(begin(db), end(db), [](auto a, auto b) {
    return a.get()->getSurname() < b.get()->getSurname();
  });
}
void DB::sortBySalary() {
  auto getSalaryOrZero = [](const std::shared_ptr<Person> &p) -> size_t {
    if (auto worker = dynamic_cast<Worker *>(p.get())) {
      return worker->getSalary();
    }
    return 0;
  };

  std::sort(begin(db), end(db),
            [&getSalaryOrZero](const auto &a, const auto &b) {
              return getSalaryOrZero(a) < getSalaryOrZero(b);
            });
}

void DB::removeByName(const std::string &name) {
  auto personToRemove = std::find_if(begin(db), end(db), [&name](auto el) {
    return el.get()->getName() == name;
  });
  db.erase(personToRemove);
}

void DB::changeSalaryByID(const size_t ID, const size_t newSalary) {
  Person *person;
  std::find_if(begin(db), end(db), [&ID, &person](auto el) {
    if (el.get()->getID() == ID) {
      person = el.get();
      return true;
    }
    return false;
  });
  if (Worker *worker = dynamic_cast<Worker *>(person); worker != nullptr) {
    worker->setSalary(newSalary);
  }
}