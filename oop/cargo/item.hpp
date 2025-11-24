#ifndef ITEM_HPP
#define ITEM_HPP

#include "cargo.hpp"
#include <iostream>
#include <string>

class Item : public Cargo {

private:
public:
  enum class Rarity { common, rare, epic, legendary } rarity_;
  Item(std::string &name, size_t amount, int basePrice, Rarity rarity);
  ~Item();

  size_t getPrice() const override;
  std::string getName() const override;
  size_t getAmount() const override;
  size_t getBasePrice() const override;
};

#endif