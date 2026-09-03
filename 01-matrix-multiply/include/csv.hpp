#ifndef CSV_HPP
#define CSV_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "benchmark.hpp"

bool isEmpty(const std::string& csv);

int csv_write(std::vector<BenchmarkResult> results);


#endif