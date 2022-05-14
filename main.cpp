#include <iostream>
#include <omp.h>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>


//#define TIME_SEQUENTIAL
#define OMP


#include "MatrixSummation.h"

int main(){
    srand(time(0));
    Matrix<int> a(10000, 10000);
    Matrix<int> b(10000, 10000);
    for (int i = 0; i < 10000; ++i){
        for (int j = 0; j < 10000; ++j){
            a.matrix[i * 10000 + j] = rand() % 10000 - 10000;
            b.matrix[i * 10000 + j] = rand() % 10000 - 10000;
        }
    }
    Matrix<int> res = SummationRoutine(a, b);
//    for (int i = 0; i < 5; ++i){
//        for (int j = 0; j < 5; ++j){
//            std::cout << res.matrix[i * 5 + j] << " ";
//        }
//        std::cout << "\n";
//    }
}