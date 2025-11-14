/*
    Zadanie

    struct Point {
  int x;
  int y;
}

    Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie.Mamy
        też dane 4 miast :

    Wrocław(x = 17, y = 51) Moskwa(x = 37, y = 55) Nowy Jork(x = -74, y = 40)
        Sydney(x = 151, y = -33)

        Część B
        - trudniejsza

        Stwórz std::unordered_map<Point, std::string> Sprawdź czy w
        odwróconej mapie jest element,
    który znajduje się w promieniu 70 od środka układu
    współrzędnych(0, 0) Pobierz i wypisz współrzędne Sydney
*/
#include <compare>
#include <iostream>
#include <math.h>
#include <unordered_map>

struct Point {
  int x;
  int y;
  auto operator<=>(const Point &) const = default;
};

struct MyHash {
  std::size_t operator()(const Point &point) const noexcept {
    std::size_t h1 = std::hash<int>{}(point.x);
    std::size_t h2 = std::hash<int>{}(point.y);
    return h1 ^ (h2 << 1);
  }
};

double radius(Point point) { return std::sqrt(point.x ^ 2 + point.y ^ 2); }
void checkCoordinates(
    const std::unordered_map<Point, std::string, MyHash> &uMap,
    const std::string &city) {

  for (auto const &[point, cityName] : uMap) {
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
  std::unordered_map<Point, std::string, MyHash> uMap{{{17, 51}, "Wrocław"},
                                                      {{37, 55}, "Moskwa"},
                                                      {{-74, 40}, "Nowy Jork"},
                                                      {{151, -33}, "Sydney"},
                                                      {{70, 0}, "Strzyżów"}};

  auto checkIfLE70 = [](auto coord, auto city) {
    if (radius(coord) <= 70) {
      std::cout << city << "\n";
    }
  };

  for (const auto &[coord, city] : uMap) {
    checkIfLE70(coord, city);
  }
  checkCoordinates(uMap, "Sydney");
}