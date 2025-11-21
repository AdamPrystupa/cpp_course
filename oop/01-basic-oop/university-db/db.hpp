#ifndef DB_HPP
#define DB_HPP

#include "student.hpp"
#include <iostream>

class DB {
private:
  /* data */
public:
  DB(/* args */);
  ~DB();
};

// Przechowywanie rekordów studentów o strukturze
//     : Imię,
//       nazwisko,
//       adres,
//       nr_indeksu,
//       PESEL,
//       płeć
//     Dodawanie nowych studentów
//     Wyświetlanie całej bazy danych
//     Wyszukiwanie po nazwisku
//     Wyszukiwanie po numerze PESEL
//     Sortowanie po numerze PESEL
//     Sortowanie po nazwisku
//     Usuwanie po numerze indeksu

DB::DB(/* args */) {}

DB::~DB() {}

#endif