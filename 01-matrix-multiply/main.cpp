#include <array>
#include <iostream>

#include "src/naive.cpp"
#include "src/ikj.cpp"
#include "src/tiled.cpp"

template<std::size_t N>
void matrix_print(const std::array<int,N*N> &matrix){
    std::cout<<"Matrix of size "<<N<<"x"<<N<<"\n";
    for(int row=0;row<N;row++){
        for(int column=0;column<N;column++){
            std::cout<<matrix[row*N+column]<<" ";
        }
        std::cout<<"\n";
    }
}

int main(void){
    std::array<int,9> a = {1,2,1,4,5,9,2,6,2};
    std::array<int,9> b = {4,2,7,7,4,5,2,1,9};

    auto c = Naive<3>(a,b);
    matrix_print<3>(c);

    std::array<int,9> test1 = {1,0,0,0,1,0,0,0,1};
    std::array<int,9> test2 = {5,2,9,3,4,8,2,9,6};

    auto test = Naive<3>(test1,test2);
    matrix_print<3>(test);
}