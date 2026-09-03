#include "multiplications.hpp"

std::vector<int> ikj(const std::vector<int>& a, const std::vector<int>& b, int N){
    std::vector<int> output(N*N);
    for(int row = 0; row<N; row++){
        for(int num = 0; num<N; num++){
            for(int column = 0; column<N; column++){
                output[row*N + column] += a[row*N + num]*b[num*N + column];
            }
        }
    }
    return output;
}