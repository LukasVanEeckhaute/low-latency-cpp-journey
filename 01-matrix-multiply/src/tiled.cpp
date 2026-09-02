#include <array>

template<std::size_t N>
std::array<int,N*N> tiled(const std::array<int,N*N>& a, const std::array<int,N*N>& b, int tilesize){

    std::array<int,N*N> output{};
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