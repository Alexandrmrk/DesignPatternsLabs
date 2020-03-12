#include "stdafx.h"
#include "MatrixInitiator.h"
#include <ctime>
#include <numeric>
#include <vector>

void MatrixInitiator::fillMatrix(IMatrix * const matrix, long nonZeroCount, long maxValue) {
    srand((unsigned int)time(nullptr));
    int rows = matrix->GetRows();
    int cols = matrix->GetCols();
    int count = 0;
    std::vector<int> indices(rows * cols);
    std::iota(indices.begin(), indices.end(), 0);
    while (count != nonZeroCount && count < rows*cols)
    {
        unsigned long pos = rand() % indices.size();
        matrix->SetValue(indices[pos] / cols, indices[pos] % cols, rand() % maxValue + 1);
        indices.erase(indices.begin() + pos);
        count++;
    }
}
