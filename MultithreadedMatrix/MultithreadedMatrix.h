#include <vector>
#include <cstdint>


class MultithreadedMatrix {
public:
    MultithreadedMatrix(const uint32_t& matrixSize);
    MultithreadedMatrix(const std::vector<std::vector<int>> &inputMatrix);

    MultithreadedMatrix& operator=(const std::vector<std::vector<int>>& data);

    void initialize();

    bool operator==(const MultithreadedMatrix& other) const;

    MultithreadedMatrix operator*(const MultithreadedMatrix& other) const;

    void print() const;

private:
    uint32_t m_MatrixSize;
    std::vector<std::vector<int>> m_Matrix;
};