/*
Zadanie 3 - grayscale-image
Zadanie 3a - compressGrayscale()

Zadaniem będzie kompresja obrazka w odcieniach szarości o wymiarach 240x160
pikseli. Każdy piksel może mieć wartość od 0 (kolor czarny) do 255 (kolor
biały). Im większa wartość tym jaśniejszy odcień piksel reprezentuje. Przykład
małego obrazka o rozmiarach 6x4 piksele:

255 255 0   255 0   255   // 0xFF 0xFF 0x00 0xFF 0x00 0xFF
128 0   128 0   128 0     // 0x80 0x00 0x80 0x00 0x80 0x00
64  64  64  64  64  64    // 0x40 0x40 0x40 0x40 0x40 0x40
255 192 128 64  0   0     // 0xFF 0xB0 0x80 0x40 0x00 0x00

Aby otrzymać z tego plik w formacie PGM wystarczy tylko dodać mu odpowiedni
nagłówek. Zadanie 3a - compressGrayscale() - opis

Napisz funkcję compressGrayscale(). Powinna ona przyjąć jeden argument typu
std::array<std::array<uint8_t, 240>, 160> określający rozkład odcieni szarości
na obrazku 2D (który w dalszej części nazywać będziemy bitmapą) i zwróci
std::vector<std::pair<uint8_t, uint8_t>> zawierający skompresowaną bitmapę.

Kompresja powinna przebiegać w następujący sposób:

    Bitmapę rysujemy od górnego lewego rogu przechodząc w prawo, następnie
poziom niżej. Jeżeli obok siebie występuje ten sam kolor więcej niż 1 raz,
funkcja powinna wrzucić do std::vector wartość tego koloru (liczba z przedziału
0 – 255) jako pierwszy element pary oraz ilość jego powtórzeń jako drugi element
pary. Jeżeli obok siebie występują różne odcienie to funkcja powinna wypełnić
std::vector wartością odcienia oraz liczbą wystąpień równą 1 (w tym przypadku
pogarszamy optymalizację, gdyż przechowujemy 2x tyle danych, jednak najczęściej
te same kolory są położone obok siebie).

Zadanie 3a - compressGrayscale() - przykład

input: {{0 0 0 1 1 2 3 0 0 0},
        {0 0 4 4 4 1 1 1 1 1},
        {2 2 2 2 2 1 2 2 2 2}}
output: {{0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, {0, 2},
         {4, 3}, {1, 5}, {2, 5}, {1, 1}, {2, 4}}

W przypadku powyższej konwersji zamiast 30 bajtów (wymiary 10x3) zużyjemy 22
(11x2). Więc skompresowaliśmy dane o 26,7%.

Nie przejmujemy się na razie tym jak uint_8 będzie zamieniany na kolor. Ważne w
tym zadaniu jest, aby poćwiczyć korzystanie z kontenerów oraz wykonywania na
nich różnych operacji.

Chętni mogą także zrefaktoryzować (czyli napisać czytelniej, ulepszyć) testy
tak, aby te skomplikowane pętle, które wypełniają tablice były uniwersalną
funkcją, możliwą do wywołania w obecnie istniejących i przyszłych testach
(podobnie jak funkcja getBitmap()). Po wydzieleniu i refaktoringu funkcji
generującej, postarajcie się dopisać także przypadki dla 1/16, 1/32 i 1/64
bitmapy. Zadanie 3b - decompressGrayscale()

Napisz funkcję decompressGrayscale(), która zdekompresuje obrazek skompresowany
w zadaniu 3a za pomocą funkcji compressGrayscale().

Jako argument funkcja decompressGrayscale() przyjmie
std::vector<std::pair<uint8_t, uint8_t>> natomiast zwróci
std::array<std::array<uint8_t, 240>, 160> i przeprowadzi operacje mające na celu
rekonstrukcję pierwotnego formatu bitmapy. Implementacja

Stwórz odpowiedni plik nagłówkowy (hpp) oraz źródłowy (cpp). W pliku nagłówkowym
zdefiniuj stałe dotyczące rozmiaru w taki sposób:

constexpr size_t width = 32;
constexpr size_t height = 32;

Dzięki temu będzie Ci łatwiej zmienić rozmiar obrazka w celach testowych, bo
wystarczy to zrobić tylko w jednym miejscu. W testach też są używane takie same
nazwy stałych.*/

#ifndef GRAYSCALE_IMAGE_HPP
#define GRAYSCALE_IMAGE_HPP

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr size_t width = 10;
constexpr size_t height = 3;

using Bitmap = std::array<std::array<uint8_t, width>, height>;
using CompressedData = std::vector<std::pair<uint8_t, uint8_t>>;
using Pair = std::pair<uint8_t, uint8_t>;

CompressedData compressGrayscale(const Bitmap &);
Bitmap decompressGrayscale(const CompressedData &);

void printCompressed(CompressedData &);
void printDecompressed(Bitmap &);

#endif