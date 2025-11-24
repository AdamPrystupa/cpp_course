#include "dryfruit.hpp"

DryFruit::DryFruit(std::string &name, size_t amount, size_t basePrice)
    : Fruit(name, basePrice, amount), countToTen(0) {}

DryFruit::~DryFruit() {}

Fruit &DryFruit::operator--() {
  ++countToTen;
  if (countToTen == 10) {
    willGoBad--;
    countToTen = 0;
  }
  return *this;
}

size_t DryFruit::getPrice() const {
  return static_cast<size_t>(basePrice_ * 3);
}

std::string DryFruit::getName() const { return "Dry" + name_; }
