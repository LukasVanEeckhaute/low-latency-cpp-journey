#include "csv.hpp"

int csv_write(std::vector<BenchmarkResult> results){
    std::ofstream filee("result/benchmarks.csv",std::ios::trunc);
    filee.close();
    std::ofstream file("results/benchmarks.csv", std::ios::app);

    if(!file.is_open()){
        std::cerr<<"Could not open file\n";
        return 0;
    }
    file<<"algorithm,size,median,tilesize\n";

    for(BenchmarkResult result : results){
        file<<result.type<<","<<result.matrix_size<<","<<result.median.count()<<","<<result.tilesize<<"\n";
    }
    return 1;
}