cmake_minimum_required(VERSION 3.10)

# Nazwa Twojego projektu
project(UniversityDB)

# Ustawienie standardu C++ na 17 (zalecane dla nowoczesnego C++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Opcjonalnie: włączenie ostrzeżeń kompilatora (pomaga wyłapać błędy)
if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Definicja pliku wykonywalnego i lista wszystkich plików źródłowych (.cpp)
# Bazując na przesłanych plikach, musimy dodać je wszystkie tutaj:
add_executable(UniversityDB
    db.cpp
    main.cpp
    student.cpp
)

# Wskazanie katalogów, w których kompilator ma szukać plików nagłówkowych (.hpp)
# Dodajemy katalog główny oraz katalog 'university-db', aby #include działały poprawnie
target_include_directories(UniversityDB PUBLIC 
    ${CMAKE_SOURCE_DIR} 
    ${CMAKE_SOURCE_DIR}/university-db
)