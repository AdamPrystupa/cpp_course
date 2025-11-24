#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <string>

class Ship {

private:
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
  unsigned int getId() const;
  std::string getName() const;
  void setName(const std::string &);
  double getSpeed() const;
  unsigned int getMaxCrew() const;
  double getCapacity() const;
  Ship &operator+=(const int);
  Ship &operator-=(const int);
  void printShip() const;
};

#endif