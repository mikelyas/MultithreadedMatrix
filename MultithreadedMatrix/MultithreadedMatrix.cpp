#include "MultithreadedMatrix.h"

#include <iostream>
#include <thread>
#include <chrono>

const int MAX_NUM_THREADS = 4;   // Number of threads for parallel processing


MultithreadedMatrix::MultithreadedMatrix(const uint32_t& matrixSize)
    : m_MatrixSize(matrixSize) {
    m_Matrix.resize(m_MatrixSize, std::vector<int>(m_MatrixSize));
}

MultithreadedMatrix::MultithreadedMatrix(const std::vector<std::vector<int>> &inputMatrix)
    : m_MatrixSize(inputMatrix.size()) {
    for (const std::vector<int> &row : inputMatrix) {
        m_Matrix.push_back(row);
    }
}

MultithreadedMatrix& MultithreadedMatrix::operator=(const std::vector<std::vector<int>>& data) {
    m_MatrixSize = data.size();
    m_Matrix = data;
    return *this;
}

void MultithreadedMatrix::initialize() {
    for (int i = 0; i < m_MatrixSize; ++i) {
        for (int j = 0; j < m_MatrixSize; ++j) {
            m_Matrix[i][j] = i * 2 + j;
        }
    }
}

bool MultithreadedMatrix::operator==(const MultithreadedMatrix& other) const {
    if (m_Matrix.size() != other.m_Matrix.size() || m_Matrix[0].size() != other.m_Matrix[0].size()) {
        // Matrices have different dimensions, they cannot be equal
        return false;
    }

    for (size_t i = 0; i < m_Matrix.size(); ++i) {
        for (size_t j = 0; j < m_Matrix[0].size(); ++j) {
            if (m_Matrix[i][j] != other.m_Matrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}

MultithreadedMatrix MultithreadedMatrix::operator*(const MultithreadedMatrix& other) const {
    MultithreadedMatrix result(m_MatrixSize);

    // Perform matrix multiplication using threads
    std::vector<std::thread> multiplicationThreads;
    const int numOfThreads = m_MatrixSize >= MAX_NUM_THREADS ? MAX_NUM_THREADS : m_MatrixSize;
    const int numRowsPerThread = (m_MatrixSize + 1) / numOfThreads;
    for (uint32_t i = 0; i < m_MatrixSize; i += numRowsPerThread) {
        uint32_t startRow = i;
        uint32_t endRow = std::min(i + numRowsPerThread, m_MatrixSize);

        multiplicationThreads.emplace_back([this, &result, startRow, endRow, &other]() {
            for (uint32_t i = startRow; i < endRow; i++) {
                for (uint32_t j = 0; j < m_MatrixSize; ++j) {
                    for (uint32_t k = 0; k < m_MatrixSize; ++k) {
                        result.m_Matrix[i][j] += m_Matrix[i][k] * other.m_Matrix[k][j];
                    }
                }
            }
        });
    }

    for (std::thread& thread : multiplicationThreads) {
        thread.join();
    }

    return result;
}

void MultithreadedMatrix::print() const {
    for (uint32_t i = 0; i < m_MatrixSize; ++i) {
        for (uint32_t j = 0; j < m_MatrixSize; ++j) {
            std::cout << m_Matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
