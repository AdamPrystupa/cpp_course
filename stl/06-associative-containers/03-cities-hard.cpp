// Zadanie
//
// struct Point {
//   int x;
//   int y;
// }
//
// Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie.Mamy
// też dane 4 miast :
//
// Wrocław(x = 17, y = 51) Moskwa(x = 37, y = 55) Nowy Jork(x = -74, y = 40)
// Sydney(x = 151, y = -33)
//
// Część B
// - trudniejsza
//
// Skopiuj te dane do mapy std::map<Point, std::string> Sprawdź czy w
// odwróconej mapie jest element,
// który znajduje się w promieniu 70 od środka układu
// współrzędnych(0, 0) Pobierz i wypisz współrzędne Sydney

#include <iostream>
#include <map>
#include <math.h>

struct Point {
  int x;
  int y;
};

double radius(Point point) { return std::sqrt(point.x ^ 2 + point.y ^ 2); }

bool operator<(const Point &a, const Point &b) { return radius(a) < radius(b); }

void checkCoordinates(const std::map<Point, std::string> &map,
                      const std::string &city) {

  for (auto const &[point, cityName] : map) {
    if (cityName == city) {
      std::cout << "x: " << point.x << " y: " << point.y << "\n";
      return;
    } else {
      continue;
    }
  }
  std::cout << "nie ma takiego miasta\n";
}

int main() {
  std::map<Point, std::string> map{{{17, 51}, "Wrocław"},
                                   {{37, 55}, "Moskwa"},
                                   {{-74, 40}, "Nowy Jork"},
                                   {{151, -33}, "Sydney"},
                                   {{70, 0}, "Strzyżów"}};

  auto checkIfLE70 = [](auto coord, auto city) {
    if (radius(coord) <= 70) {
      std::cout << city << "\n";
    }
  };

  for (const auto &[coord, city] : map) {
    checkIfLE70(coord, city);
  }
  checkCoordinates(map, "Sydney");
}