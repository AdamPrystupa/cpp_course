#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP

#include "cargo.hpp"
#include <iostream>
#include <string>

class Alcohol : public Cargo {
private:
  size_t alcoholContent_;

public:
  Alcohol(std::string &name, size_t amount, int basePrice,
          size_t alcoholContent);
  ~Alcohol();

  size_t getPrice() const override;
  std::string getName() const override;
  size_t getAmount() const override;
  size_t getBasePrice() const override;
};

#endif