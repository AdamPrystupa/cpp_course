#ifndef CARGO_HPP
#define CARGO_HPP

#include <iostream>
#include <string>

class Cargo {

protected:
  std::string name_;
  size_t amount_;
  int basePrice_;

public:
  Cargo(std::string &name, size_t amount, int basePrice);
  virtual ~Cargo();
  Cargo &operator+=(const size_t);
  Cargo &operator-=(const size_t);
  virtual size_t getPrice() const = 0;
  virtual std::string getName() const = 0;
  virtual size_t getAmount() const = 0;
  virtual size_t getBasePrice() const = 0;
};

#endif