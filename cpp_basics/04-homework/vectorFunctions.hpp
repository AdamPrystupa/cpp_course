#ifndef VECTORFUNCTIONS_HPP
#define VECTORFUNCTIONS_HPP

#include <iostream>
#include <memory>
#include <vector>
std::vector<std::shared_ptr<int>> generate(const int &);
void print(std::vector<std::shared_ptr<int>> &);
void add10(std::vector<std::shared_ptr<int>> &);
void sub10(int *const);
void sub10(std::vector<std::shared_ptr<int>> &);

#endif
