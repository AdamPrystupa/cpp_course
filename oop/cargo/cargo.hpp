#ifndef CARGO_HPP
#define CARGO_HPP

#include <iostream>
#include <string>

class Cargo {

private:
  std::string name_;
  size_t amount_;
  int basePrice_;

public:
  Cargo &operator+=(const size_t);
  Cargo &operator-=(const size_t);
};

#endif