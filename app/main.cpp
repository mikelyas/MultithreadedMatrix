#include <iostream>

#include "MultithreadedMatrix.h"


int main() {
    MultithreadedMatrix matrixA({{1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6}});
    MultithreadedMatrix matrixB({{1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6},
                                 {1, 2, 3, 4, 5, 6}});

    std::cout << "Matrix A:" << std::endl;
    matrixA.print();

    std::cout << "Matrix B:" << std::endl;
    matrixB.print();

    MultithreadedMatrix resultMatrix = matrixA * matrixB;

    std::cout << "Matrix Multiplication Result:" << std::endl;
    resultMatrix.print();

    return 0;
}
