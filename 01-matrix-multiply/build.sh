#!/bin/bash
g++ -std=c++20 -O3 \
    -Iinclude \
    main.cpp \
    src/naive.cpp \
    src/ikj.cpp \
    src/tiled.cpp \
    src/generator.cpp \
    src/benchmark.cpp \
    src/csv.cpp \
    -o matrix_benchmark

./matrix_benchmark
