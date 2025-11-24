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

// */

#include "db.hpp"
#include "student.hpp"
#include <iostream>

int main() {
  DB db;
  Student s1("Jan", "Kowalski", "Warszawa, ul. Zlota 44", 123456, 98010212345,
             Sex::Male);

  Student s2("Anna", "Nowak", "Krakow, ul. Szewska 10", 654321, 99112254321,
             Sex::Female);

  db.addNewStudent(
      {"Karol", "Dabrowski", "Lublin, Zana 3", 400100, 12251199887, Sex::Male});

  db.addNewStudent({
      "Ewa",              // name
      "Jastrzebska-Kruk", // surname
      "Opole",            // adress
      550990,             // index_number
      78110543210,        // ID (PESEL)
      Sex::Female         // sex
  });

  db.addNewStudent({
      "Tomasz",              // name
      "Wozniak",             // surname
      "Szczecin, Piastow 1", // adress
      876543,                // index_number
      94071567890,           // ID (PESEL)
      Sex::Male              // sex
  });

  db.addNewStudent(s1);
  db.addNewStudent(s2);

  //   db.sortBySurname();
  //   db.sortByID();
  //   db.searchBySurname("Nowak");
  //   db.searchByID(78110543210);
  db.printDB();
  db.removeByName("Nowak");
  db.printDB();

  return 0;
}