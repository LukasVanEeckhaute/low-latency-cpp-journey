#ifndef CSV_HPP
#define CSV_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "benchmark.hpp"

int csv_write(std::vector<BenchmarkResult> results, const std::string& csv);


#endif