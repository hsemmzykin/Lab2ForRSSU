#ifndef LABRABFORRSSU_MATRIXSUMMATION_H
#define LABRABFORRSSU_MATRIXSUMMATION_H
#include <omp.h>
#include <iostream>
#include <chrono>
using namespace std::chrono;
template <typename T>
struct Matrix {
    size_t rows;
    size_t cols;
    T *matrix;
    explicit Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        matrix = new T[rows * cols];
    }
};

template<typename T>
Matrix<T> SummationRoutine(Matrix<T> a , Matrix<T> b){
    if (a.cols != b.cols || a.rows != b.rows){
        std::cerr << "Incorrect size\n";
        exit(1);
    }
    Matrix<T> res(a.rows, a.cols);
#ifdef OMP
    double begin = omp_get_wtime();
#pragma omp parallel for
#endif
#ifdef TIME_SEQUENTIAL
    auto start = high_resolution_clock::now();
#endif
    for (size_t i = 0; i < a.rows; ++i){
#ifdef OMP
#pragma omp parallel for
#endif
        for (size_t j = 0; j < a.cols; ++j)
            res.matrix[i * a.rows + j] = a.matrix[i * a.rows + j] + b.matrix[i * b.rows + j];
    }
#ifdef TIME_SEQUENTIAL
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "TIME EXECUTED IN MICROSECONDS: " << duration.count() << std::endl;

#endif

#ifdef OMP
double end = omp_get_wtime();
std::cout << "TIME EXECUTED IN SECONDS: " << end - begin << std::endl;
#endif

    return res;
}



#endif
