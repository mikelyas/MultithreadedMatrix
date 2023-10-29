#include <iostream>

#include "MultithreadedMatrix.h"


int main() {
    
    MultithreadedMatrix matrixA = MultithreadedMatrix({{1, 2, 3, 4},
                                                       {2, 3, 4, 5}});
    MultithreadedMatrix matrixB = MultithreadedMatrix({{1, 2, 3},
                                                       {2, 3, 4},
                                                       {4, 5, 6},
                                                       {6, 7, 8}});

    std::cout << "Matrix A:" << std::endl;
    std::cout << matrixA;

    std::cout << "Matrix B:" << std::endl;
    std::cout << matrixB;

    MultithreadedMatrix resultMatrix = matrixA * matrixB;

    std::cout << "Matrix Multiplication Result:" << std::endl;
    std::cout << resultMatrix;

    return 0;
}
