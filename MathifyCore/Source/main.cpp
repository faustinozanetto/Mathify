#include <iostream>

#include "Input/InputHandler.h"
#include "Log/Log.h"
#include "Math/Matrix.h"

using namespace Mathify::Math;

namespace Mathify
{
    void Initialize()
    {
        Log::info("Initializing Mathify v0.0.1");
        auto inputHandler = new Input::InputHandler();
        Math::Matrix myMatrix = inputHandler->RequestMatrix();
        myMatrix.PrintMatrix();
        myMatrix.Transport().PrintMatrix();
        double determinant = myMatrix.Determinant();
        Log::debug("Determinant: %f", determinant);
    }
};

int main(int argc, char* argv[])
{
    try
    {
        Mathify::Initialize();
        std::cout << '\n' << "Press a key to continue...";
        while (std::cin.get() != '\n') { }
    }
    catch (...) {}
    return 0;
}
