#include "Matrix.h"

#include <string>

namespace  LES::Math
{
    Matrix Matrix::operator+(const Matrix& matrix) const
    {
        
    }
    
    std::vector<std::vector<int>> Matrix::GetContent() const
    {
        return this->content;
    }
    
    int Matrix::GetCols() const
    {
        return this->cols;
    }
    
    void LES::Math::Matrix::PrintMatrix()
    {
        std::string result = "";
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                std::cout << this->content[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}

