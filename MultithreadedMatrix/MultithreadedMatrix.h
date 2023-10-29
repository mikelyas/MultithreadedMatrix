#include <vector>
#include <cstdint>
#include <ostream>
#include <functional>


class MultithreadedMatrix {
public:
    MultithreadedMatrix(const uint32_t& matrixSize);
    MultithreadedMatrix(const uint32_t& matrixHeight, const uint32_t matrixWidth);
    MultithreadedMatrix(const std::vector<std::vector<int>> &inputMatrix);

    MultithreadedMatrix& operator=(const std::vector<std::vector<int>>& data);

    void initialize();

    bool operator==(const MultithreadedMatrix& other) const;

    MultithreadedMatrix operator*(const MultithreadedMatrix& other) const;

    MultithreadedMatrix operator+(const MultithreadedMatrix& other) const;

    MultithreadedMatrix operator-(const MultithreadedMatrix& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MultithreadedMatrix& matrix);

private:

    MultithreadedMatrix elementWiseOperation(const MultithreadedMatrix& other
        , std::function<int(int, int)> op) const;

    uint32_t m_MatrixHeight;
    uint32_t m_MatrixWidth;
    std::vector<std::vector<int>> m_Matrix;
};