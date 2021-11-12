#pragma once
#include <vector>
#include <iostream>

namespace Mathify::Math
{
    class Point {
    public:
            char option;
            int coordinate;

            Point(char option, int coordinate) {
                this->option = option;
                this->coordinate = coordinate;
            }
    };

    class Matrix
    {
    public:
        Matrix()
        {
            this->rows = 3;
            this->cols = 3;
            // Initialize content to 0s.
            this->content = std::vector<std::vector<int>>(this->rows, std::vector(this->cols, 0));
        }

        Matrix(int rows, int cols)
        {
            this->rows = rows;
            this->cols = cols;
            // Initialize content to 0s.
            this->content = std::vector<std::vector<int>>(this->rows, std::vector(this->cols, 0));
        }

        Matrix(int rows, int cols, std::vector<std::vector<int>> content)
        {
            this->rows = rows;
            this->cols = cols;
            this->content = content;
        }

        /**
         ** Returns a Matrix with the sum of each matrix equivalent index.
         *
         * @warning Make sure that BOTH Matrices have the same dimensions.
         * @param matrix Matrix to add to the current matrix.
         * @return Matrix the summed Matrix.
         */
        Matrix operator+(Matrix& matrix);
        /**
         ** Returns a Matrix with the subtracted numbers of each matrix equivalent index.
         *
         * @warning Make sure that BOTH Matrices have the same dimensions.
         * @param matrix Matrix to subtract to the current matrix.
         * @return Matrix the subtracted Matrix.
        */
        Matrix operator-(Matrix& matrix);
        /**
         ** Multiply the current Matrix by a given One.
         *
         * @warning Make sure that dimensions are correct: m x n && n x p
         * @param matrix Matrix to multiply to the current matrix.
         * @return Matrix the multiplied one.
        */
        Matrix operator*(Matrix& matrix);

        Matrix Transport();
        Point BestChoice();
        double Determinant();

        Matrix Minor(int x, int y);
        std::vector<std::vector<int>> GetContent();
        void SetContent(std::vector<std::vector<int>> newContent);
        int UpdateIndex(int row, int col, int value);
        int GetCols();
        int GetRows();
        bool SameSize(Matrix& matrix);
        void PrintMatrix();
    private:
        int rows;
        int cols;
        std::vector<std::vector<int>> content;
    };
}
