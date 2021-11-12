#include "Vector.h"

namespace Mathify::Math {
    Vector Vector::operator+(Vector& vector) 
    {
        if (SameDimension(vector)) {
            for (int i = 0; i < this->dimension; i++) {
                this->content[i] += vector.GetContent()[i];
            }
            return *this;
        }
        return Vector();
    }

    Vector Vector::operator-(Vector& vector)
    {
        if (SameDimension(vector)) {
            for (int i = 0; i < this->dimension; i++) {
                this->content[i] -= vector.GetContent()[i];
            }
            return *this;
        }
        return Vector();
    }

    Vector Vector::operator*(Vector& vector)
    {
        if (SameDimension(vector)) {
            for (int i = 0; i < this->dimension; i++) {
                this->content[i] *= vector.GetContent()[i];
            }
            return *this;
        }
        return Vector();
    }

    std::vector<double> Vector::GetContent()
    {
        return this->content;
    }

    int Vector::UpdateIndex(int position, int value)
    {
        this->content[position] = value;
        return this->content[position];
    }

    int Vector::GetDimension()
    {
        return this->dimension;
    }

    bool Vector::SameDimension(Vector vector)
    {
        return this->dimension == vector.GetDimension();
    }

    void Vector::PrintVector()
    {
        std::string result = "";
        for (int i = 0; i < this->dimension; i++)
        {
            std::cout << this->content[i] << " ";
        }
        std::cout << "\n";
    };
}