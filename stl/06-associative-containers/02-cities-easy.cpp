// Zadanie

//     struct Point {
//   int x;
//   int y;
// }

//     Struktura Point ma reprezentować punkt o współrzędnych x i y na
//     mapie.Mamy
//         też dane 4 miast :

//     Wrocław(x = 17, y = 51) Moskwa(x = 37, y = 55) Nowy Jork(x = -74, y = 40)
//         Sydney(x = 151, y = -33)

//             Część A
//     - łatwiejsza

//     Stwórz std::map<std::string, Point>,
//     która będzie przechowywać powyższe miejsca Sprawdź czy w mapie jest
//     element, który znajduje się w promieniu 70 od środka układu
//     współrzędnych(0, 0) Pobierz i wypisz współrzędne Sydney

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>

struct Point {
  int x;
  int y;
};

double radius(Point point) { return std::sqrt(point.x ^ 2 + point.y ^ 2); }

void checkCoordinates(const std::map<std::string, Point> &map,
                      const std::string &city) {
  auto search = map.find(city);
  if (search != end(map)) {
    std::cout << "x: " << search->second.x << " y: " << search->second.y
              << "\n";
  } else {
    std::cout << "nie ma takiego miasta\n";
  }
}

int main() {
  std::map<std::string, Point> map{{"Wrocław", {17, 51}},
                                   {"Moskwa", {37, 55}},
                                   {"Nowy Jork", {-74, 40}},
                                   {"Sydney", {151, -33}}};

  auto checkIfLE70 = [](auto city, auto coord) {
    if (radius(coord) <= 70) {
      std::cout << city << "\n";
    }
  };

  for (const auto &[city, coord] : map) {
    checkIfLE70(city, coord);
  }

  // checkCoordinates(map, "Sydney");

  auto &c = map["Sydney"];
  std::cout << "x: " << c.x << " y: " << c.y << "\n";
}