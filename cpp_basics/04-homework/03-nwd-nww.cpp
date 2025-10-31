#include <iostream>

int NWW(int a, int b);
int NWD(int a, int b);

int main() {
  std::cout << "NWW(255, 15) = " << NWW(1000, 1001) << "\n";
  std::cout << "NWD(255, 15) = " << NWD(-18, 12) << "\n";

  return 0;
}

int NWW(int a, int b) {
  int result = 0;
  result = abs(a * b) / NWD(a, b);
  return result;
}

int NWD(int a, int b) {
  a = abs(a);
  b = abs(b);
  int c = 0;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
