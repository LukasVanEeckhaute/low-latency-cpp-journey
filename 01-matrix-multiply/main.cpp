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
    std::vector<BenchmarkResult> naive_results;
    std::vector<BenchmarkResult> ikj_results;
    std::vector<BenchmarkResult> tiled_results;

    for(int N = 100; N<= 1000; N += 50){
        std::vector<int> a = generate_matrix(seed, N);
        std::vector<int> b = generate_matrix(seed, N);

        auto naive = Benchmark(a,b,"naive",10,N);
        BenchmarkResult naive_result = {"naive",N,naive[1]};
        naive_results.push_back(naive_result);

        auto ikj = Benchmark(a,b,"ikj",10,N);
        BenchmarkResult ikj_result = {"ikj",N,ikj[1]};
        ikj_results.push_back(ikj_result);

        for(int tilesize = 8; tilesize < N/2; tilesize = 2*tilesize){
            auto tiled = Benchmark(a,b,"tiled",10,N,tilesize);
            BenchmarkResult tiled_result = {"tiled",N,tiled[1],tilesize};
            tiled_results.push_back(tiled_result);
        }
        seed += 1;
    }
    seed = 5000;
    for(int N = 1300; N <= 2600; N+=300){
        std::vector<int> a = generate_matrix(seed, N);
        std::vector<int> b = generate_matrix(seed, N);

        auto naive = Benchmark(a,b,"naive",10,N);
        BenchmarkResult naive_result = {"naive",N,naive[1]};
        naive_results.push_back(naive_result);

        auto ikj = Benchmark(a,b,"ikj",10,N);
        BenchmarkResult ikj_result = {"ikj",N,ikj[1]};
        ikj_results.push_back(ikj_result);

        for(int tilesize = 8; tilesize < N/2; tilesize = 2*tilesize){
            auto tiled = Benchmark(a,b,"tiled",10,N,tilesize);
            BenchmarkResult tiled_result = {"tiled",N,tiled[1],tilesize};
            tiled_results.push_back(tiled_result);
        }
        seed += 1;
    }
    int checknaive = csv_write(naive_results, "results/naiveresults.csv");
    int checkikj = csv_write(ikj_results, "results/ikjresults.csv");
    int checktiled = csv_write(tiled_results, "results/tiledresults.csv");
}