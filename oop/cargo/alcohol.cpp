#include "alcohol.hpp"

Alcohol::Alcohol(std::string &name, size_t amount, int basePrice,
                 size_t alcoholContent)
    : Cargo(name, amount, basePrice), alcoholContent_(alcoholContent){};

Alcohol::~Alcohol(){};

size_t Alcohol::getPrice() const {
  return static_cast<size_t>(basePrice_ - (96 - alcoholContent_) * 0.5);
};
std::string Alcohol::getName() const { return name_; };
size_t Alcohol::getAmount() const { return amount_; };
size_t Alcohol::getBasePrice() const { return basePrice_; };
