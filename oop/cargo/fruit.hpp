#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "cargo.hpp"
#include <iostream>
#include <string>

class Fruit : public Cargo {
private:
  size_t willGoBad;

public:
  Fruit &operator-();
  Fruit(std::string &name, size_t amount, size_t basePrice);
  ~Fruit();

  size_t getPrice() const override;
  size_t getBasePrice() const override;
  std::string getName() const override;
  size_t getAmount() const override;
};

#endif