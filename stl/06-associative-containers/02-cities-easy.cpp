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

#include <iostream>
#include <map>
#include <math.h>

struct Point {
  int x;
  int y;
};

bool checkDistance(const std::map<std::string, Point> &map,
                   const int &distance) {
  for (auto &[city, point] : map) {
    if (std::sqrt(point.x * point.x + point.y * point.y) == distance)
      return true;
  }
  return false;
}

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

  std::cout << (checkDistance(map, 70) ? "true\n" : "false\n");
  checkCoordinates(map, "Wrocław");
}