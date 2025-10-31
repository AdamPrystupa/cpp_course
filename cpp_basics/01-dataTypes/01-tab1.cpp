#include <iostream>

constexpr size_t tab_size = 100;

int main()
{
    int tab[tab_size];

    size_t value = 1;
    for (size_t i = 0; i < tab_size; i++)
    {
        tab[i] = value;
        value += 2;
    }
    for (size_t i = 0; i < tab_size; ++i)
    {
        std::cout << tab[i] << "\n";
    }

    return 0;
}