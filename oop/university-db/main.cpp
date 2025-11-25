// /*
// university-db

// Napiszcie od zera program, który będzie akademicką "bazą danych".

// Używajcie STLa!
// Wymagania (16 XP):

//     Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, adres,
//     nr_indeksu, PESEL, płeć Dodawanie nowych studentów Wyświetlanie całej
//     bazy danych Wyszukiwanie po nazwisku Wyszukiwanie po numerze PESEL
//     Sortowanie po numerze PESEL
//     Sortowanie po nazwisku
//     Usuwanie po numerze indeksu

// university-db
// Opcjonalne wymagania (12 XP):

//     Walidacja czy numer PESEL jest poprawny Wiki - poprawność PESEL (trudne)
//     Wczytywanie z pliku i zapisywanie całej bazy w pliku (trudne)

// Wymagania(14 XP)

//     Przechowywanie rekordów pracowników uczelni o strukturze
//     : imię,
//       nazwisko,
//       PESEL,
//       płeć,
//       adres,
//       zarobki
// Wszystkie osoby niezależnie czy będą to pracownicy,czy studenci mają być
// trzymani w jednym kontenerze
// Wypełnianie bazy danych sztucznymi danymi(generowanie danych)
// Modyfikacja zarobków wyszukując osobę po numerze PESEL(problematyczne)
// Sortowanie po zarobkach(problematyczne)

// */
#include "db.hpp"
#include "generator.hpp" // Pamiętaj o dołączeniu nagłówka generatora
#include "student.hpp"
#include "worker.hpp"
#include <iostream>
#include <memory>
#include <string>

// Funkcja pomocnicza do ładnego formatowania logów
void printHeader(const std::string &title) {
  std::cout << "\n========================================\n";
  std::cout << " TEST: " << title << "\n";
  std::cout << "========================================\n";
}

int main() {
  // Inicjalizacja
  DB universityDB;
  Generator generator;

  // ---------------------------------------------------------
  // 1. Dodawanie Manualne (Dane Kontrolne)
  // ---------------------------------------------------------
  printHeader("1. Dodawanie reczne (dane kontrolne)");

  // Dodajemy specyficzne osoby, żeby móc potem na nich testować wyszukiwanie
  auto targetStudent =
      std::make_shared<Student>("Zygmunt", "Celowany", 11111111111, Sex::Male,
                                "Celna 1, Warszawa", 99999);

  auto targetWorker =
      std::make_shared<Worker>("Barbara", "Pracowita", 22222222222, Sex::Female,
                               "Biurowa 5, Krakow", 15000);

  universityDB.addNewPerson(targetStudent);
  universityDB.addNewPerson(targetWorker);

  std::cout << "-> Dodano 2 osoby recznie (Zygmunt i Barbara).\n";

  // ---------------------------------------------------------
  // 2. Generowanie Danych (Stres Test)
  // ---------------------------------------------------------
  printHeader("2. Generowanie losowych danych");

  size_t amountToGenerate = 10;
  std::cout << "-> Generuje " << amountToGenerate << " losowych osob...\n";

  generator.generateData(universityDB, amountToGenerate);

  std::cout << "-> Gotowe. Aktualny stan bazy:\n";
  universityDB.printDB();

  // ---------------------------------------------------------
  // 3. Test Sortowania po Nazwisku
  // ---------------------------------------------------------
  printHeader("3. Sortowanie po Nazwisku");

  universityDB.sortBySurname();
  universityDB.printDB();
  std::cout << "-> Sprawdz powyzej czy nazwiska sa alfabetycznie.\n";

  // ---------------------------------------------------------
  // 4. Test Sortowania po PESEL
  // ---------------------------------------------------------
  printHeader("4. Sortowanie po PESEL (ID)");

  universityDB.sortByID();
  universityDB.printDB();
  std::cout << "-> Sprawdz powyzej czy PESEL rosnie.\n";

  // ---------------------------------------------------------
  // 5. Test Wyszukiwania (Na danych kontrolnych)
  // ---------------------------------------------------------
  printHeader("5. Wyszukiwanie");

  std::cout << ">>> Szukam nazwiska 'Pracowita' (powinna byc Barbara):\n";
  universityDB.searchBySurname("Pracowita");

  std::cout << ">>> Szukam PESEL '11111111111' (powinien byc Zygmunt):\n";
  universityDB.searchByID(11111111111);

  std::cout << ">>> Szukam nieistniejacego nazwiska 'Yeti':\n";
  universityDB.searchBySurname("Yeti");

  // ---------------------------------------------------------
  // 6. Test Usuwania
  // ---------------------------------------------------------
  printHeader("6. Usuwanie");

  // Usuwamy Zygmunta po imieniu (zakładając, że metoda removeByName usuwa po
  // Name)
  std::cout << "-> Usuwam osobe o imieniu 'Zygmunt'...\n";
  universityDB.removeByName("Zygmunt");

  std::cout
      << ">>> Weryfikacja (szukam PESELu Zygmunta - powinno byc pusto):\n";
  universityDB.searchByID(11111111111);

  std::cout << "\n>>> Koncowy stan bazy (bez Zygmunta):\n";
  universityDB.printDB();

  universityDB.changeSalaryByID(22222222222, 2137);
  universityDB.changeSalaryByID(11111111111, 2137);
  universityDB.searchByID(22222222222);

  // universityDB.printDB();
  // ---------------------------------------------------------
  // 7. Test Sortowania po Zarobkach
  // ---------------------------------------------------------
  printHeader("7. Sortowanie po Zarobkach");

  universityDB.sortBySalary();
  universityDB.printDB();

  std::cout
      << "-> Oczekiwane: Najpierw Studenci (0), potem Pracownicy rosnaco.\n";

  return 0;
}