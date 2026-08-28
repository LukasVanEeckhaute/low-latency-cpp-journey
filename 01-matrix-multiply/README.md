## Matrix multiplication preformance in C++
This project explores how different implementations of matrix multiplication
in C++ have a very different preformance despite preforming the same calculations. 

The goal is to understand how memory acces paterns, cache locality and loop ordering
affect execution time on a modern CPU

# Implementations
The project compares three different implementations of matrix multiplication:
- Naive i-j-k multiplication
- Reordered i-j-k multiplication
- Tiled matrix multiplication
All matrices are stored as std::arrays 

