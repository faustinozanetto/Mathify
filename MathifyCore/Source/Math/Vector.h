#pragma once
#include <vector>
#include <iostream>

namespace Mathify::Math {
	class Vector {
	public:
		Vector() {
			this->dimension = 3;
			this->content = std::vector<double>(this->dimension, 0);
		}

		Vector(int dimension) {
			this->dimension = dimension;
			this->content = std::vector<double>(this->dimension, 0);
		}

		Vector(int dimension, std::vector<double> content) {
			this->dimension = dimension;
			this->content = content;
		}

		Vector operator+(Vector& vector);
		Vector operator-(Vector& vector);
		Vector operator*(Vector& vector);

		std::vector<double> GetContent();
		int UpdateIndex(int position, int value);
		int GetDimension();
		bool SameDimension(Vector vector);
		void PrintVector();

	private:
		int dimension;
		std::vector<double> content;
	};
}