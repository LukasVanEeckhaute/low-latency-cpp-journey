#include "benchmark.hpp"

std::vector<int> generate_matrix(unsigned int seed, int N){
    std::mt19937 engine(seed);
    std::uniform_int_distribution<int> dist(0,9);

    std::vector<int> matrix(N*N);

    for(int& element : matrix){
        element += dist(engine);
    }
    return matrix;
}