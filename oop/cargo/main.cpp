/*
Zadanie 1

Napisz klasę Ship, która przechowywać będzie dane statku:

    id_ - identyfikator statku
    name_ - nazwa statku
    speed_ - prędkość statku
    maxCrew_ - maksymalna liczna załogi
    capacity_ - ładowność statku

Dane powinny być prywatne, a dostęp do nich dostęp powinniśmy mieć przez
gettery. Pomyśl samodzielnie jakiego typu powinny to być dane.

Zadanie 2
Dodaj do klasy Ship konstruktory, które przyjmować będą odpowiednie dane. Chcemy
3 konstruktory:

Pierwszy nieprzyjmujący żadnych argumentów. id_ dla takiego obiektu powinno
wynosić -1
Drugi przyjmujący wszystkie dane
Trzeci przyjmujący id, speed i
maxCrew (postaraj się wykorzystać drugi konstruktor przy pisaniu trzeciego -
patrz Delegowanie konstruktorów)

Dodatkowo dodaj metodę void setName(const std::string&), która pozwoli na
ustawianie nazwy statku.

Zadanie 3

Dodaj do klasy Ship:

    zmienną size_t crew_ określającą aktualną liczbę załogi na statku
    Ship& operator+=(const int), który dodawać będzie załogę do statku
    Ship& operator-=(const int), który będzie ją odejmował.

Zadanie 4

Utwórz klasę Cargo. Ma ona reprezentować 1 typ towaru na statku. Będzie ona
posiadać 3 pola:

    name_ - nazwa towaru
    amount_ - ilość towaru
    basePrice_ - bazowa cena towaru

Następnie napisz w klasie Cargo:

Cargo& operator+=(const size_t), który będzie dodawać podaną ilość towaru
Cargo& operator-=(const size_t), który będzie odejmował podaną ilość towaru

Zastanów się także, jak będziesz przechowywać towary na statku.
*/

#include "cargo.hpp"
#include "ship.hpp"
#include <iostream>
#include <string>

int main() {
  Ship stateczek(2137, "Pogrom", 50.5, 5, 100, 2);
  Ship statek(420, 30.1, 3);
  stateczek.printShip();
  statek.printShip();
  statek.setName("Orzeł");
  statek += 2;
  statek.printShip();
  statek -= 1;
  statek.printShip();
  return 0;
}
