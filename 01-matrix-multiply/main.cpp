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
    std::vector<int> a = generate_matrix(232323, 10);
    std::vector<int> b = generate_matrix(1111, 10);

    auto startnaive = steady_clock::now();
    std::vector<int> naive_output = Naive(a,b,10);
    auto endnaive = steady_clock::now();
    auto naivetime = duration_cast<microseconds>(endnaive - startnaive);

    auto startikj = steady_clock::now();
    std::vector<int> ikj_output = ikj(a,b,10);
    auto endikj = steady_clock::now();
    auto ikjtime = duration_cast<microseconds>(endikj - startikj);

    auto starttiled = steady_clock::now();
    std::vector<int> tiled_output = tiled(a,b,10,2);
    auto endtiled = steady_clock::now();
    auto tiledtime = duration_cast<microseconds>(endtiled - starttiled);

    // std::cout<<"Naive: "<<naivetime.count()<<"\n";
    // std::cout<<"ikj: "<<ikjtime.count()<<"\n";
    // std::cout<<"tiled: "<<tiledtime.count()<<"\n";
    // int hulp = naive_output[1];
    // int hulp2 = ikj_output[2];
    // int hulp3 = tiled_output[3];
    // std::cout<<hulp<<hulp2<<hulp3;
}