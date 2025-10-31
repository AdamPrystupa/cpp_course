#ifndef VECTORFUNCTIONS.HPP
#define VECTORFUNCTIONS .HPP

#include <memory>
#include <vector>

std::vector<std::shared_ptr<int>> generate(int &const);
void print(std::vector<std::shared_ptr<int>> &);
void add10(std::vector<std::shared_ptr<int>> &);
void sub10(int *const);
void sub10(std::vector<std::shared_ptr<int>> &);

#endif
