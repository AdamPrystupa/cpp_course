#include "coordinates.hpp"
#include <cmath>

Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}
Coordinates::~Coordinates() {}

bool Coordinates::operator<(const Coordinates &other) const {
  return distance(*this, {0, 0}) < distance(other, {0, 0});
}

size_t Coordinates::distance(const Coordinates &lhs, const Coordinates &rhs) {
  long dx =
      static_cast<long>(lhs.positionX_) - static_cast<long>(rhs.positionX_);
  long dy =
      static_cast<long>(lhs.positionY_) - static_cast<long>(rhs.positionY_);
  double dist = std::sqrt(static_cast<double>(dx * dx + dy * dy));
  return static_cast<size_t>(dist);
}
