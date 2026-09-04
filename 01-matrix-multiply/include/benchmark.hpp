#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <chrono>
#include <numeric>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std::chrono;

#include "multiplications.hpp"

struct BenchmarkResult{
    std::string type;
    int matrix_size;
    microseconds median;
    int tilesize = 0;
};

std::array<microseconds,3> Benchmark(const std::vector<int>& a, const std::vector<int>& b, std::string type, int repeats, int N, int tilesize = 0);

std::vector<int> generate_matrix(unsigned int seed, int N);

#endif