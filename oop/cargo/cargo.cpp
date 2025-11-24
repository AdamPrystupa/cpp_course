#include "cargo.hpp"

Cargo &Cargo::operator+=(const size_t amount) {
  amount_ += amount;
  return *this;
}

Cargo &Cargo::operator-=(const size_t amount) {
  amount_ -= amount;
  return *this;
}