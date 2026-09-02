#include <array>

template<std::size_t N>
std::array<int,N*N> ikj(std::array<int,N*N> a, std::array<int,N*N> b){
    std::array<int,N*N> output{};
    for(int row = 0; row<N; row++){
        for(int num = 0; num<N; num++){
            for(int column = 0; column<N; column++){
                output[row*N + column] += a[row*N + num]*b[num*N + column];
            }
        }
    }
    return output;
}