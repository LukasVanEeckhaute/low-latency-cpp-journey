#include <array>
#include <iostream>
#include <chrono>
using namespace std::chrono;

#include "multiplications.hpp"
#include "benchmark.hpp"
#include "csv.hpp"

void print_matrix(const std::vector<int> &matrix, int N){
    std::cout<<"Matrix of size "<<N<<"x"<<N<<"\n";
    for(int row=0;row<N;row++){
        for(int column=0;column<N;column++){
            std::cout<<matrix[row*N+column]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

int main(void){

    int seed = 10;
    std::vector<BenchmarkResult> results;
    for(int N = 100; N<= 1000; N += 50){
        std::vector<int> a = generate_matrix(seed, N);
        std::vector<int> b = generate_matrix(seed, N);

        auto naive = Benchmark(a,b,"naive",20,N);
        BenchmarkResult naive_result = {"naive",N,naive[1]};
        results.push_back(naive_result);

        auto ikj = Benchmark(a,b,"ikj",20,N);
        BenchmarkResult ikj_result = {"ikj",N,ikj[1]};
        results.push_back(ikj_result);

        for(int tilesize = 8; tilesize < N/2; tilesize = 2*tilesize){
            auto tiled = Benchmark(a,b,"tiled",20,N,tilesize);
            BenchmarkResult tiled_result = {"tiled",N,tiled[1],tilesize};
            results.push_back(tiled_result);
        }
        seed += 1;
    }
    int check = csv_write(results);
}