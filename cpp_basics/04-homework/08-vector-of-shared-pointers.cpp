#include <iostream>
#include <memory>
#include <vector>

#include "vectorFunctions.hpp"

int main() {
  auto vec = generate(10);
  print(vec);
  add10(vec);
  print(vec);
  sub10(vec);
  print(vec);
}