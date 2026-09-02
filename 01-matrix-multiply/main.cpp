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

    std::array<int,9> test1 = {1,0,0,0,1,0,0,0,1};
    std::array<int,9> test2 = {5,2,9,3,4,8,2,9,6};

    auto testnaive = Naive<3>(test1,test2);
    auto testikj = ikj<3>(test1,test2);

    std::array<int,16> test3 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    std::array<int,16> test4 = {5,2,9,3,4,8,2,9,6,7,6,3,1,0,2,2};
    auto testtiled = tiled<4>(test3,test4,2);

    matrix_print<3>(testnaive);
    matrix_print<3>(testikj);
    matrix_print<4>(testtiled);
}