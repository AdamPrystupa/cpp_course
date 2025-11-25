#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

enum class Sex { Male, Female };

class Person {
protected:
  std::string name_;
  std::string surname_;
  size_t ID_;
  Sex sex_;
  std::string adress_;

public:
  Person(const std::string &name, const std::string &surname, const size_t ID,
         const Sex &sex, const std::string &adress);
  virtual ~Person();
  virtual std::string getName() const;
  virtual std::string getSurname() const;
  virtual size_t getID() const;
  std::string sexString() const;
  virtual std::string getAdress() const;
  // 1. Wirtualna metoda do wypisywania (zamiast void print())
  virtual void printDB(std::ostream &os) const;

  // 2. Operator zaprzyjaźniony (nie jest metodą klasy)
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
};

#endif