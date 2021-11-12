#pragma once
#include "../Math/Matrix.h"
#include "../Math/Vector.h"

namespace Mathify::Input
{
    class InputHandler
    {
    public:
        InputHandler();

        Math::Matrix RequestMatrix();
        Math::Vector RequestVector();
        Math::Matrix ReadMatrixFromInput(const int rows, const int cols);
        Math::Vector ReadVectorFromInput(const int dimension);
    private:
    
    };
};