#include "cargo.hpp"

Cargo::Cargo(std::string &name, size_t amount, int basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice){}

Cargo::~Cargo() {}

Cargo &Cargo::operator+=(const size_t amount) {
  amount_ += amount;
  return *this;
}

Cargo &Cargo::operator-=(const size_t amount) {
  amount_ -= amount;
  return *this;
}