#include "InputHandler.h"

#include <iostream>
#include <format>
#include <vector>
#include <string>

#include "../Log/Log.h"

namespace Mathify::Input
{
    InputHandler::InputHandler() {}
    
    Math::Matrix InputHandler::RequestMatrix() {
        int cols = 0;
        int rows = 0;
        Log::info("How many columns does the Matrix have?: ");
        std::cin >> cols;
        Log::info("How many rows does the Matrix have?: ");
        std::cin >> rows;
        
        return ReadMatrixFromInput(cols, rows);
    }

    Math::Vector InputHandler::RequestVector()
    {
        int dimension = 0;
        Log::info("Please enter the dimension of the Vector: ");
        std::cin >> dimension;
        return ReadVectorFromInput(dimension);
    }

    Math::Matrix InputHandler::ReadMatrixFromInput(const int rows, const int cols)
    {
        auto matrix = Math::Matrix(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value = 0;
                std::cin >> value;
                matrix.UpdateIndex(i,j, value);
            }
        }
        return matrix;
    }
    Math::Vector InputHandler::ReadVectorFromInput(const int dimension)
    {
        auto vector = Math::Vector(dimension);
        for (int i = 0; i < dimension; i++) {
            int value = 0;
            std::cin >> value;
            vector.UpdateIndex(i, value);
        }
        return vector;
    }
}
