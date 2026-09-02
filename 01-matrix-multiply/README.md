# Matrix multiplication preformance in C++
This project explores how different implementations of matrix multiplication
in C++ have a very different preformance despite preforming the same calculations. 

The goal is to understand how memory acces paterns, cache locality and loop ordering
affect execution time on a modern CPU

## Implementations
We've got a matrix multiplication a * b = output where a is the first operand, b the second and output is the 
multiplied matrix.

The project compares three different implementations of matrix multiplication:
- Naive i-j-k multiplication
- Reordered i-k-j multiplication
- Tiled matrix multiplication

All matrices are stored as std::arrays.
For example a 3x3 matrix A:

```text
[ 1  2  3 ]
[ 4  5  6 ]
[ 7  8  9 ]
```

is stored as:

```text
[ 1  2  3 | 4  5  6 | 7  8  9 ]
  row 0     row 1     row 2


For an NxN matrix A, A[row][column] becomes A[N*row + column]
```

## Reordered i-k-j multiplication


## Tiled matrix multiplication
The tiled implementation splits up a matrix (N x N) in a number of tiles (tilesize x tilesize). 
It repeatedly uses small blocks of matrix a and b that are stored next to eachother in memory so the chance that a called element is already in cache is way larger than for naive multiplication. 


For this example we have a 4x4 matrix that we split in tiles of 2x2. 
```text
[ 5  6  9  0 ]
[ 2  2  6  7 ]
[ 1  3  4  4 ] 
[ 8  3  0  1 ]
     =a