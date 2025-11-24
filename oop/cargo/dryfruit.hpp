#ifndef DRYFRUIT_HPP
#define DRYFRUIT_HPP

#include "fruit.hpp"

class DryFruit : public Fruit {
private:
  size_t countToTen;

public:
  DryFruit(std::string &name, size_t amount, size_t basePrice);
  ~DryFruit();
  Fruit &operator--() override;

  size_t getPrice() const override;
  std::string getName() const override;
};

#endif