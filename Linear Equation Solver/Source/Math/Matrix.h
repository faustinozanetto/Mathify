#pragma once
#include <vector>
#include <iostream>

namespace LES::Math 
{
    class Matrix
    {
    public:
        Matrix()
        {
            this->rows = 3;
            this->cols = 3;
            // Initialize content to 0s.
            this->content = std::vector<std::vector<int>> (this->rows, std::vector (this->cols, 0));
        }

        Matrix(int rows, int cols)
        {
            this->rows = rows;
            this->cols = cols;
            // Initialize content to 0s.
            this->content = std::vector<std::vector<int>> (this->rows, std::vector (this->cols, 0));
        }

        Matrix(int rows, int cols, std::vector<std::vector<int>> content)
        {
            this->rows = rows;
            this->cols = cols;
            this->content = content;
        }

        Matrix operator+(const Matrix& matrix);

        std::vector<std::vector<int>> GetContent() const;
        void SetContent(std::vector<std::vector<int>> newContent);
        int UpdateIndex(int row, int col, int value);
        int GetCols() const;
        int GetRows() const;
        bool SameSize(const Matrix& matrix) const;
        void PrintMatrix();
    private:
        int rows;
        int cols;
        std::vector<std::vector<int>> content;
    };

}
