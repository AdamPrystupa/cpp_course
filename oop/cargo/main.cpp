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

Zadanie 5

Przekształć klasę Cargo w interfejs z 4 czysto wirtualnymi metodami.

virtual size_t getPrice() const = 0;
virtual std::string getName() const = 0;
virtual size_t getAmount() const = 0;
virtual size_t getBasePrice() const = 0;

Utwórz 3 pochodne klasy Cargo:

    Fruit
    Alcohol
    Item

Klasa Fruit powinna mieć dodatkową zmienną określającą czas do zepsucia oraz
operator-- który będzie odejmował ten czas o 1. Metoda getPrice() powinna
redukować cenę odpowiednio wraz z czasem psucia naszego owocu.

Klasa Alcohol powinna mieć dodatkową zmienną określającą procentowy udział
spirytusu. Metoda getPrice() powinna być proporcjonalnie wyższa w zależności od
mocy alkoholu. Należy ustalić bazową cenę za spirytus 96%.

Klasa Item powinna mieć dodatkową zmienną enum określającą rzadkość przedmiotu
(common, rare, epic, legendary). Metoda getPrice() powinna być adekwatnie
wyliczana od poziomu rzadkości przedmiotu.

Zadanie 6

Wykorzystując wspólną klasę bazową Cargo spróbuj przechowywać wszystkie towary w
jednym wektorze w klasie Ship.

Dodaj funkcję void load(std::shared_ptr<Cargo> cargo), która dodaje towar i (dla
chętnych) void unload(Cargo* cargo), która usuwa towar z obiektu klasy Ship.


Zadanie 7

Napisz klasę DryFruit, która dziedziczyć będzie po klasie Fruit.

Klasa ta powinna nadpisywać metody getPrice(), getName() oraz operator--.

operator-- powinien odejmować zużycie raz na 10 wywołań.

Metoda getPrice() powinna zwracać trzykrotnie większą wartość w porównaniu do
ceny bazowej.

Zadanie 8

Napisz/przekształć klasę Coordinates, która ma określać współrzędne na mapie.
Powinna ona przyjmować w konstruktorze 2 parametry positionX, positionY. Klasa
Coordinates powinna też posiadać operator porównania.

Ma ona także posiadać funkcję statyczną distance:

static size_t distance(const Coordinates& lhs, const Coordinates& rhs)

Funkcja ta powinna zwracać dystans pomiędzy dwoma pozycjami.
*/

#include "alcohol.hpp"
#include "cargo.hpp"
#include "dryfruit.hpp" // <--- Dodano nagłówek
#include "fruit.hpp"
#include "item.hpp"
#include "ship.hpp"
#include <iostream>
#include <memory>
#include <string>

// Funkcja pomocnicza do ładnego formatowania w konsoli
void printHeader(const std::string &title) {
  std::cout << "\n========================================\n";
  std::cout << " TEST: " << title << "\n";
  std::cout << "========================================\n";
}

int main() {
  // ---------------------------------------------------------
  // 1. Inicjalizacja Statku
  // ---------------------------------------------------------
  printHeader("Tworzenie Statku");

  Ship myShip(1, "Czarna Perla", 50.0, 100, 1000.0, 20);
  myShip.printShip();

  // ---------------------------------------------------------
  // 2. Tworzenie Towarów (Cargo) - Fruit, Alcohol, Item
  // ---------------------------------------------------------
  printHeader("Tworzenie Towarow i Logika Cen");

  // --- FRUIT ---
  std::string fruitName = "Jablka";
  // Cena bazowa: 20, Ilość: 100
  auto apple = std::make_shared<Fruit>(fruitName, 20, 100);

  // Psujemy owoc o 4 dni
  // Używamy operatora zdefiniowanego w Fruit (zakładamy operator- lub -- w
  // zależności od Twojej implementacji) W Twoim fruit.cpp był operator-, więc
  // używamy zapisu -(*ptr)
  --*apple;
  --*apple;
  --*apple;
  --*apple;
  std::cout << "Owoc (po 4 dniach): " << apple->getName()
            << " | Cena: " << apple->getPrice() << " (Oczekiwana: 18)\n";

  // --- ALCOHOL ---
  std::string alcoholName = "Rum";
  // Ilość: 50, Cena bazowa: 100, Moc: 40%
  auto rum = std::make_shared<Alcohol>(alcoholName, 50, 100, 40);

  std::cout << "Alkohol (40%): " << rum->getName()
            << " | Cena: " << rum->getPrice() << " (Oczekiwana: 72)\n";

  // --- ITEM ---
  std::string itemName = "Miecz";
  // Ilość: 1, Cena bazowa: 200, Rarity: Rare
  auto sword = std::make_shared<Item>(itemName, 1, 200, Item::Rarity::rare);

  std::cout << "Przedmiot (Rare): " << sword->getName()
            << " | Cena: " << sword->getPrice() << " (Oczekiwana: 230)\n";

  // ---------------------------------------------------------
  // 3. Testowanie DryFruit (Suszone Owoce)
  // ---------------------------------------------------------
  printHeader("Logika DryFruit");

  std::string dryFruitName = "Sliwki";
  // Cena bazowa: 30, Ilość: 50.
  // DryFruit dziedziczy po Fruit, ale nadpisuje getPrice -> 3 * basePrice
  auto dryPlum = std::make_shared<DryFruit>(dryFruitName, 50, 30);

  // Test getName() - powinno dodać "Suszone "
  std::cout << "Nazwa: " << dryPlum->getName()
            << " (Oczekiwane: Suszone Sliwki)\n";

  // Test getPrice() - powinno być 3 * 30 = 90
  std::cout << "Cena: " << dryPlum->getPrice() << " (Oczekiwane: 90)\n";

  // Test operatora-- (dekrementacja co 10 wywołań)
  // Uwaga: Ponieważ DryFruit::getPrice() zwraca stałą wartość (3 * base),
  // psucie się nie wpłynie na cenę w tej implementacji, ale sprawdzamy czy kod
  // się kompiluje i działa.
  std::cout << "Symulacja uplywu czasu (20 cykli)...\n";
  for (int i = 0; i < 20; ++i) {
    --(*dryPlum); // Używamy operatora dekrementacji (zgodnie z poleceniem dla
                  // DryFruit)
  }
  std::cout << "Cena po uplywie czasu: " << dryPlum->getPrice()
            << " (Nadal 90 - specyfika DryFruit)\n";

  // ---------------------------------------------------------
  // 4. Ładowanie na statek (load)
  // ---------------------------------------------------------
  printHeader("Ladowanie towarow (load)");

  myShip.load(apple);
  myShip.load(rum);
  myShip.load(sword);
  myShip.load(dryPlum); // Ładujemy też suszone owoce
  std::cout << "-> Zaladowano wszystkie towary (w tym suszone).\n";

  // ---------------------------------------------------------
  // 5. Zawartość ładowni
  // ---------------------------------------------------------
  printHeader("ZAWARTOSC LADOWNI (Ship::printCargos)");

  // Tutaj sprawdzimy, czy polimorfizm działa dla DryFruit (czy wypisze poprawną
  // nazwę i cenę)
  myShip.printCargos();

  // ---------------------------------------------------------
  // 6. Rozładunek
  // ---------------------------------------------------------
  printHeader("Rozladunek (unload: Rum)");

  myShip.unload(rum.get());
  std::cout << "-> Usunieto Rum.\n";

  std::cout << "\n--- Ladownia po rozladunku ---\n";
  myShip.printCargos();

  return 0;
}