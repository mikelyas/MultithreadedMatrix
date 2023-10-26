#include "MultithreadedMatrix.h"

#include <iostream>
#include <thread>
#include <chrono>

const int MAX_NUM_THREADS = 4;   // Number of threads for parallel processing


MultithreadedMatrix::MultithreadedMatrix(const uint32_t& matrixSize)
    : m_MatrixHeight(matrixSize), m_MatrixWidth(matrixSize) {
    m_Matrix.resize(m_MatrixHeight, std::vector<int>(m_MatrixWidth));
}

MultithreadedMatrix::MultithreadedMatrix(const uint32_t& matrixHeight, const uint32_t matrixWidth)
    : m_MatrixHeight(matrixHeight), m_MatrixWidth(matrixWidth) {
    m_Matrix.resize(m_MatrixHeight, std::vector<int>(m_MatrixWidth));
}

MultithreadedMatrix::MultithreadedMatrix(const std::vector<std::vector<int>> &inputMatrix)
    : m_MatrixHeight(inputMatrix.size()), m_MatrixWidth(inputMatrix[0].size()) {
    for (const std::vector<int> &row : inputMatrix) {
        m_Matrix.push_back(row);
    }
}

MultithreadedMatrix& MultithreadedMatrix::operator=(const std::vector<std::vector<int>>& data) {
    m_MatrixHeight = data.size();
    m_MatrixWidth = data[0].size();
    m_Matrix = data;
    return *this;
}

void MultithreadedMatrix::initialize() {
    for (int i = 0; i < m_MatrixHeight; ++i) {
        for (int j = 0; j < m_MatrixWidth; ++j) {
            m_Matrix[i][j] = i * 2 + j;
        }
    }
}

bool MultithreadedMatrix::operator==(const MultithreadedMatrix& other) const {
    if (m_MatrixHeight != other.m_MatrixHeight || m_MatrixWidth != other.m_MatrixWidth) {
        // Matrices have different dimensions, they cannot be equal
        return false;
    }

    for (uint32_t i = 0; i < m_MatrixHeight; ++i) {
        for (uint32_t j = 0; j < m_MatrixWidth; ++j) {
            if (m_Matrix[i][j] != other.m_Matrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}

MultithreadedMatrix MultithreadedMatrix::operator*(const MultithreadedMatrix& other) const {
    MultithreadedMatrix result(m_MatrixHeight, other.m_MatrixWidth);

    // Perform matrix multiplication using threads
    std::vector<std::thread> multiplicationThreads;
    const int numOfThreads = m_MatrixHeight >= MAX_NUM_THREADS ? MAX_NUM_THREADS : m_MatrixHeight;
    const int numRowsPerThread = (m_MatrixHeight + 1) / numOfThreads;
    for (uint32_t i = 0; i < m_MatrixHeight; i += numRowsPerThread) {
        uint32_t startRow = i;
        uint32_t endRow = std::min(i + numRowsPerThread, m_MatrixHeight);

        multiplicationThreads.emplace_back([this, &result, startRow, endRow, &other]() {
            for (uint32_t i = startRow; i < endRow; i++) {
                for (uint32_t j = 0; j < other.m_MatrixWidth; ++j) {
                    for (uint32_t k = 0; k < m_MatrixWidth; ++k) {
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

MultithreadedMatrix MultithreadedMatrix::operator+(const MultithreadedMatrix& other) const {
     MultithreadedMatrix result(m_MatrixHeight, other.m_MatrixWidth);

    // Perform matrix multiplication using threads
    std::vector<std::thread> multiplicationThreads;
    const int numOfThreads = m_MatrixHeight >= MAX_NUM_THREADS ? MAX_NUM_THREADS : m_MatrixHeight;
    const int numRowsPerThread = (m_MatrixHeight + 1) / numOfThreads;
    for (uint32_t i = 0; i < m_MatrixHeight; i += numRowsPerThread) {
        uint32_t startRow = i;
        uint32_t endRow = std::min(i + numRowsPerThread, m_MatrixHeight);

        multiplicationThreads.emplace_back([this, &result, startRow, endRow, &other]() {
            for (uint32_t i = startRow; i < endRow; i++) {
                for (uint32_t j = 0; j < m_MatrixWidth; ++j) {
                    result.m_Matrix[i][j] = m_Matrix[i][j] + other.m_Matrix[i][j];
                }
            }
        });
    }

    for (std::thread& thread : multiplicationThreads) {
        thread.join();
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const MultithreadedMatrix& matrix) {
    for (uint32_t i = 0; i < matrix.m_MatrixHeight; ++i) {
        for (uint32_t j = 0; j < matrix.m_MatrixWidth; ++j) {
            os << matrix.m_Matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
