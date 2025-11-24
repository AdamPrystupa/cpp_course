#include "item.hpp"

Item::Item(std::string &name, size_t amount, int basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity){};
Item::~Item(){};

size_t Item::getPrice() const {
  return static_cast<size_t>(basePrice_ +
                             (0.15 * basePrice_) * static_cast<int>(rarity_));
};
std::string Item::getName() const { return name_; };
size_t Item::getAmount() const { return amount_; };
size_t Item::getBasePrice() const { return basePrice_; };
