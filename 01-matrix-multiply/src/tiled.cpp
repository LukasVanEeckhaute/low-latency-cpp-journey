#include "multiplications.hpp"


std::vector<int> tiled(const std::vector<int>& a, const std::vector<int>& b, int tilesize, int N){
    if(a.size()!=N*N && b.size()!=N*N){
        throw std::invalid_argument("Matrix sizes do not match");
    }

    if((tilesize <= 0) || (tilesize > N)){
        throw std::invalid_argument("Tilesize out of range");
    }

    std::vector<int> output(N*N);
    //looping tiles
    for(int tilerow = 0; tilerow < N; tilerow += tilesize){
        for(int k_row = 0; k_row < N; k_row += tilesize){
                for(int tilecolumn = 0; tilecolumn < N; tilecolumn += tilesize){

                    //looping elements within tile
                    for(int row = tilerow; (row < tilerow + tilesize) && (row < N); row++){
                        for(int k = k_row; (k < k_row + tilesize) && (k < N); k++){

                            for(int column = tilecolumn; (column < tilecolumn + tilesize) && (column < N); column++){
                                output[N*row + column] += a[N*row + k] * b[N*k + column];
                            }
                        }
                    }


           }
        }
    }
    return output;
}