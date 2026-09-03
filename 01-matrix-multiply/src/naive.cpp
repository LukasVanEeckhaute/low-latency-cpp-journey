#include "multiplications.hpp"

std::vector<int> Naive(const std::vector<int> & a, const std::vector<int> & b, int N){
    if(a.size()!=N*N && b.size()!=N*N){
        throw std::invalid_argument("Matrix sizes do not match");
    }
    
    std::vector<int> output(N*N);
    for(int row=0; row<N; row++){
        for(int column=0; column<N; column++){
            int element=0;
            for(int num=0;num<N;num++){
                element += a[row*N + num]*b[column + N*num];
            }
            output[(row)*N+column] = element;
        }
    }
    return output;
}