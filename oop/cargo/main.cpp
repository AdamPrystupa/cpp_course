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
*/

#include "alcohol.hpp"
#include "cargo.hpp"
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

  // ID: 1, Nazwa: Czarna Perla, Speed: 50, MaxCrew: 100, Capacity: 1000, Crew:
  // 20
  Ship myShip(1, "Czarna Perla", 50.0, 100, 1000.0, 20);
  myShip.printShip();

  // ---------------------------------------------------------
  // 2. Tworzenie Towarów (Cargo)
  // ---------------------------------------------------------
  printHeader("Tworzenie Towarow i Logika Cen");

  // --- FRUIT ---
  std::string fruitName = "Jablka";
  // Cena bazowa: 20, Ilość: 100. willGoBad domyślnie 7.
  // Uwaga: Zakładam, że poprawiłeś kolejność w konstruktorze Fruit na (name,
  // basePrice, amount)
  auto apple = std::make_shared<Fruit>(fruitName, 20, 100);

  // Psujemy owoc o 4 dni (zostanie 3 dni świeżości)
  // Wzór: cena - (7 - willGoBad) * 0.5
  // willGoBad = 3. Różnica = 4. Obniżka = 4 * 0.5 = 2. Nowa cena = 18.
  -*apple;
  -*apple;
  -*apple;
  -*apple;
  std::cout << "Owoc (po 4 dniach): " << apple->getName()
            << " | Cena wyliczona: " << apple->getPrice()
            << " (Oczekiwana: 18)\n";

  // --- ALCOHOL ---
  std::string alcoholName = "Rum";
  // Ilość: 50, Cena bazowa: 100, Moc: 40%
  auto rum = std::make_shared<Alcohol>(alcoholName, 50, 100, 40);

  // Wzór: basePrice - (96 - alcoholContent) * 0.5
  // 100 - (96 - 40) * 0.5 = 100 - (56 * 0.5) = 100 - 28 = 72.
  std::cout << "Alkohol (40%): " << rum->getName()
            << " | Cena wyliczona: " << rum->getPrice()
            << " (Oczekiwana: 72)\n";

  // --- ITEM ---
  std::string itemName = "Miecz";
  // Ilość: 1, Cena bazowa: 200, Rarity: Rare (zakładamy int(Rare) == 1)
  // Musisz mieć 'enum class Rarity' w sekcji PUBLIC w item.hpp!
  auto sword = std::make_shared<Item>(itemName, 1, 200, Item::Rarity::rare);

  // Wzór: basePrice + (0.15 * basePrice) * rarity
  // 200 + (30 * 1) = 230.
  std::cout << "Przedmiot (Rare): " << sword->getName()
            << " | Cena wyliczona: " << sword->getPrice()
            << " (Oczekiwana: 230)\n";

  // ---------------------------------------------------------
  // 3. Ładowanie na statek (load)
  // ---------------------------------------------------------
  printHeader("Ladowanie towarow (load)");

  myShip.load(apple);
  std::cout << "-> Zaladowano Jablka\n";
  myShip.load(rum);
  std::cout << "-> Zaladowano Rum\n";
  myShip.load(sword);
  std::cout << "-> Zaladowano Miecz\n";

  // ---------------------------------------------------------
  // 4. Test nowej funkcji printCargos()
  // ---------------------------------------------------------
  printHeader("ZAWARTOSC LADOWNI (Ship::printCargos)");

  // To wywoła Twoją nową pętlę for-each
  myShip.printCargos(); // Upewnij się, że w .hpp nazwałeś to printCargos, a nie
                        // pritnCargos ;)

  // ---------------------------------------------------------
  // 5. Rozładunek (unload) i weryfikacja
  // ---------------------------------------------------------
  printHeader("Rozladunek (unload: Rum)");

  // Usuwamy Rum ze statku
  myShip.unload(rum.get());
  std::cout << "-> Usunieto Rum.\n";

  std::cout << "\n--- Ladownia po rozladunku ---\n";
  // Powinny zostać tylko Jabłka i Miecz
  myShip.printCargos();

  return 0;
}