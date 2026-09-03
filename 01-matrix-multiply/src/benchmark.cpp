#include "benchmark.hpp"

std::array<microseconds,3> Benchmark(const std::vector<int>& a, const std::vector<int>& b, std::string type, int repeats, int N, int tilesize){
    
    microseconds median;
    microseconds max;
    microseconds min;

    std::vector<microseconds> durations(repeats);
    std::array<microseconds,3> arr;

    if(type == "naive"){
        //benchmark
        for(int i = 0; i< repeats; i++){
            auto start = steady_clock::now();
            std::vector<int> output = Naive(a,b,N);
            auto end = steady_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            durations[i] = duration;
        }
    }
    else if(type == "ikj"){
        //benchmark
        for(int i = 0; i< repeats; i++){
            auto start = steady_clock::now();
            std::vector<int> output = ikj(a,b,N);
            auto end = steady_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            durations[i] = duration;
        }  
    }
    else if(type == "tiled"){
        //benchmark
        for(int i = 0; i< repeats; i++){
            auto start = steady_clock::now();
            std::vector<int> output = tiled(a,b,tilesize,N);
            auto end = steady_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            durations[i] = duration;
        }
    }
    else{
        throw std::invalid_argument("Multiplication type not supported");
    }

    min = *(std::min_element(durations.begin(), durations.end()));
    max = *(std::max_element(durations.begin(), durations.end()));
    //calculating median
    size_t n = durations.size();
    size_t mid = n/2;
    std::nth_element(durations.begin(),durations.begin() + mid, durations.end());

    if(n % 2 != 0){
        median = durations[mid];
    }
    else{
        auto upper = durations[mid];
        std::nth_element(durations.begin(),durations.begin() + mid - 1, durations.end());
        auto lower = durations[mid-1];
        median = (upper + lower)/2;
    }
    // std::cout<<type<<" benchmark of matrix size "<<N<<" with "<<repeats<<" repeats\n";
    // if(type == "tiled") std::cout<<"Tilesize= "<<tilesize<<"\n";
    // std::cout<<"Median time= "<<median.count()<<" microseconds\n\n";
    
    arr[0] = min;
    arr[1] = median;
    arr[2] = max;
    
    return arr;
}   