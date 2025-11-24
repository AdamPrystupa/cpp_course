#ifndef SHIP_HPP
#define SHIP_HPP

#include "cargo.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Ship {

private:
  std::vector<std::shared_ptr<Cargo>> cargos{};

  const int id_;
  std::string name_;
  double speed_;
  size_t maxCrew_;
  double capacity_;
  size_t crew_;

public:
  Ship();
  Ship(const int id, const std::string &name, double speed,
       const size_t maxCrew, const double capacity, const size_t crew);
  Ship(const int id, double speed, const size_t maxCrew);
  ~Ship();
  int getId() const;
  std::string getName() const;
  void setName(const std::string &);
  double getSpeed() const;
  unsigned int getMaxCrew() const;
  double getCapacity() const;
  Ship &operator+=(const int);
  Ship &operator-=(const int);
  void printShip() const;
  void printCargos() const;
  void load(std::shared_ptr<Cargo> cargo);
  void unload(Cargo *cargo);
};

#endif