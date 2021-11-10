#include "Matrix.h"

#include <string>

namespace  LES::Math
{
    Matrix Matrix::operator+(const Matrix& matrix)
    {
        if (SameSize(matrix))
        {
            auto copiedMatrix = new Matrix(this->rows, this->cols, this->content);
            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < this->cols; j++)
                {
                    auto toAdd =  matrix.GetContent()[i][j];
                    int updatedValue = copiedMatrix->UpdateIndex(i, j, this->content[i][j] + toAdd);
                }
                std::cout << "\n";
            }
            return *copiedMatrix;
        }
        return *this;
    }
    
    std::vector<std::vector<int>> Matrix::GetContent() const
    {
        return this->content;
    }
    
    void Matrix::SetContent(std::vector<std::vector<int>> newContent)
    {
        this->content = newContent;
    }
    
    int Matrix::UpdateIndex(int row, int col, int value)
    {
        this->content[row][col] = value;
        return this->content[row][col];
    }

    int Matrix::GetCols() const
    {
        return this->cols;
    }
    
    int Matrix::GetRows() const
    {
        return this->rows;
    }
    
    bool Matrix::SameSize(const Matrix& matrix) const
    {
        return matrix.GetCols() == this->cols && matrix.GetRows() == this->rows;
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

