#include "Matrix.h"

#include <string>

namespace Mathify::Math
{
    Matrix Matrix::operator+(Matrix& matrix)
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                int updatedValue = this->UpdateIndex(i, j, this->content[i][j] + matrix.GetContent()[i][j]);
            }
        }
        return *this;
    }

    Matrix Matrix::operator-(Matrix& matrix)
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                int updatedValue = this->UpdateIndex(i, j, this->content[i][j] - matrix.GetContent()[i][j]);
            }
        }
        return *this;
    }

    Matrix Matrix::operator*(Matrix& matrix)
    {
        const auto multipliedMatrix = new Matrix(this->rows, matrix.GetCols());
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < matrix.GetCols(); j++)
            {
                float sum = 0;
                for (int k = 0; k < this->cols; k++)
                {
                    sum += this->content[i][k] * matrix.GetContent()[k][j];
                }
                multipliedMatrix->UpdateIndex(i, j, sum);
            }
        }
        return *multipliedMatrix;
    }

    Matrix Matrix::Transport()
    {
        Matrix tempMatrix = Matrix(this->rows, this->cols, this->content);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                tempMatrix.UpdateIndex(j, i, this->content[i][j]);
            }
        }
        return tempMatrix;
    }

    Point Matrix::BestChoice()
    {
        int rowZeroCount = 0;
        int _row = 0;
        for (int i = 0; i < this->rows; i++) {
            int temp = 0;
            for (int j = 0; j < this->cols; j++) {
                temp += this->content[i][j] ? 0 : 1;
            }
            rowZeroCount = temp > rowZeroCount ? temp : rowZeroCount;
            _row = temp > rowZeroCount ? i : _row;
        }

        int colZeroCount = 0;
        int _col = 0;
        for (int j = 0; j < this->cols; j++) {
            int temp = 0;
            for (int i = 0; i < this->rows; i++) {
                temp += this->content[i][j] ? 0 : 1;
            }
            colZeroCount = temp > colZeroCount ? temp : colZeroCount;
            _col = temp > colZeroCount ? j : _col;
        }

        return rowZeroCount > colZeroCount ? Point('r', _row) : Point('c', _row);
    }

    double Matrix::Determinant()
    {
        Point coordinate = BestChoice();
        long double sum = 0.0;
        if (coordinate.option == 'r') {
            if (this->rows == 1) {
                return this->content[0][0];
            }
            else {
                for (int c = 0; c < this->cols; c++) {
                    if (this->content[coordinate.coordinate][c]) {
                        sum += ((coordinate.coordinate + c) % 2 ? -1 : 1)
                            * this->content[coordinate.coordinate][c] *
                            this->Minor(coordinate.coordinate, c).Determinant();
                    }
                }
            }
        }
        else if (this->cols == 1) {
            return this->content[0][0];
        }
        else {
            for (int r = 0; r < this->rows; r++) {
                if (this->content[r][coordinate.coordinate]) {
                    sum += ((coordinate.coordinate + r) % 2 ? -1 : 1) *
                        this->content[r][coordinate.coordinate] *
                        this->Minor(r, coordinate.coordinate).Determinant();
                }
            }
        }
        return sum;
    }

    Matrix Matrix::Minor(int x, int y)
    {
        int x1 = 0;
        int y1 = 0;
        Matrix result = Matrix(this->rows - 1, this->cols - 1);
        for (int i = 0; i < this->rows; i++) {
            if (i == x) {
                x1 = 1;
                continue;
            }
            for (int j = 0; j < this->cols; j++) {
                if (j == y) {
                    y1 = 1;
                    continue;
                }
                result.UpdateIndex(i - x1, j - y1, this->content[i][j]);
            }
            y1 = 0;
        }
        return result;
    }

    std::vector<std::vector<int>> Matrix::GetContent()
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

    int Matrix::GetCols()
    {
        return this->cols;
    }

    int Matrix::GetRows()
    {
        return this->rows;
    }

    bool Matrix::SameSize(Matrix& matrix)
    {
        return matrix.GetCols() == this->cols && matrix.GetRows() == this->rows;
    }

    void Matrix::PrintMatrix()
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
