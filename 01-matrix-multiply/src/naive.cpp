#include <array>

template<std::size_t N>
std::array<int,N*N> Naive(const std::array<int,N*N> & a, const std::array<int,N*N> & b){
    std::array<int,N*N> output;
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