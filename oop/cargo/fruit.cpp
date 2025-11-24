#include "fruit.hpp"

Fruit::Fruit(std::string &name, size_t amount, size_t basePrice)
    : Cargo(name, basePrice, amount), willGoBad(7) {}

Fruit::~Fruit() {}

Fruit &Fruit::operator-() {
  willGoBad--;
  return *this;
}

size_t Fruit::getPrice() const {
  return static_cast<size_t>(basePrice_ - (7 - willGoBad) * 0.5);
}

size_t Fruit::getBasePrice() const { return basePrice_; };
std::string Fruit::getName() const { return name_; };
size_t Fruit::getAmount() const { return amount_; };