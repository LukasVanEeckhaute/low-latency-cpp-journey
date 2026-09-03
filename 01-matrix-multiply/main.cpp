#include <array>
#include <iostream>
#include <chrono>
using namespace std::chrono;

#include "src/naive.cpp"
#include "src/ikj.cpp"
#include "src/tiled.cpp"
#include "src/generator.cpp"
#include "src/benchmark.cpp"

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
    std::vector<int> a = generate_matrix(232323, 1000);
    std::vector<int> b = generate_matrix(1111, 1000);

    auto result1 = Benchmark(a,b,"naive",10,1000);
    auto result2 = Benchmark(a,b,"ikj",10,1000);
    auto result3 = Benchmark(a,b,"tiled",10,1000,64);

}