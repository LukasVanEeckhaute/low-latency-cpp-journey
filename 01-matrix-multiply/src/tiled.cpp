#include <array>

template<std::size_t N>
std::array<int,N*N> tiled(const std::array<int,N*N>& a, const std::array<int,N*N>& b, int tilesize){

    std::array<int,N*N> output{};

    for(int tilerow = 0; tilerow < N/tilesize; tilerow ++){
        
        for(int k_row = 0; k_row < N/tilesize; k_row++){ 
            for(int tilecolumn = 0; tilecolumn < N/tilesize; tilecolumn++){

                //loop through all k-values corresponding to k_row
                for(int k = tilesize*k_row; k < tilesize*(k_row+1); k++){
                    //loop through all elements of one tile
                    for(int row = 0; row < tilesize; row++){
                        for(int column = 0; column < tilesize; column++){

                            int truerow = tilerow * tilesize + row;
                            int truecol = tilecolumn * tilesize + column;

                            output[N*truerow + truecol] += a[N*truerow + k]*b[k*N + truecol];
                        
                        }
                    }
                }
            }
        }
    }

    if(N % tilesize != ){
        // to be continued
    }
    return output;
}