#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <cstddef>
#include <math.h>

class Coordinates {
private:
  int positionX_;
  int positionY_;

public:
  Coordinates(int positionX, int positionY);
  ~Coordinates();
  bool operator<(const Coordinates &other) const;
  static size_t distance(const Coordinates &lhs, const Coordinates &rhs);
};

#endif