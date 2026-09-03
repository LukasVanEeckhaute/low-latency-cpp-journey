#ifndef MULTIPLICATIONS_HPP
#define MULTIPLICATIONS_HPP

#include <vector>
#include <stdexcept>

std::vector<int> Naive(const std::vector<int> & a, const std::vector<int> & b, int N);

std::vector<int> ikj(const std::vector<int>& a, const std::vector<int>& b, int N);

std::vector<int> tiled(const std::vector<int>& a, const std::vector<int>& b, int tilesize, int N);

#endif
