﻿#include <iostream>

#include "Math/Matrix.h"

namespace LES
{
    void Initialize()
    {
        std::cout << "Initializing Linear Equation Solver v0.0.1" << std::endl;
        const auto myMatrix = new Math::Matrix(3,3);
        myMatrix->PrintMatrix();
        const auto myMatrix2 = new Math::Matrix(4,5);
        myMatrix2->PrintMatrix();
    }
};

int main(int argc, char* argv[]) {
    try
    {
        LES::Initialize();
        while (true)
        {
            
        }
    } catch (...) {}
    return 0;
}