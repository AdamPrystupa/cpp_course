#include "ship.hpp"

Ship::Ship() : id_(-1) {}
Ship::Ship(const int id, const std::string &name, double speed,
           const size_t maxCrew, const double capacity, const size_t crew)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew),
      capacity_(capacity), crew_(crew){};

Ship::Ship(const int id, double speed, const size_t maxCrew)
    : Ship(id, "", speed, maxCrew, 0, 0) {}

Ship::~Ship() {}

void Ship::setName(const std::string &name) {
  if (!name.empty()) {
    name_ = name;
  }
}

unsigned int Ship::getId() const { return id_; }
std::string Ship::getName() const { return name_; }
double Ship::getSpeed() const { return speed_; }
unsigned int Ship::getMaxCrew() const { return maxCrew_; }
double Ship::getCapacity() const { return capacity_; }

Ship &Ship::operator+=(const int crewNumber) {
  crew_ += crewNumber;
  return *this;
};
Ship &Ship::operator-=(const int crewNumber) {
  crew_ -= crewNumber;
  return *this;
};

void Ship::printShip() const {
  std::cout << "Ship ID: " << this->getId() << "\n";
  std::cout << "Ship name: " << this->getName() << "\n";
  std::cout << "Ship speed: " << this->getSpeed() << "\n";
  std::cout << "Ship maxCrew: " << this->getMaxCrew() << "\n";
  std::cout << "Ship capacity: " << this->getCapacity() << "\n";
  std::cout << "Ship crew: " << this->crew_ << "\n\n";
};
