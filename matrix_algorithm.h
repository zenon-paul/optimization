#ifndef MATRIX_ALGORITHM
#define MATRIX_ALGORITHM
#include"matrix.h"
#include<tuple>
namespace basicmatrix {
	class MatrixAlgorithm{
	private:
	public:
		template <typename T>
		float determinant(const Matrix<T>&);

		template <typename T>
		std::tuple<Matrix<T>, Matrix<T>> lu(const Matrix<T>&);

		template <typename T>
		Matrix<T>& gauss_elimination(Matrix<T>&);

		template <typename T>
		Matrix<T>& gauss_jordan_elimination(Matrix<T>&);

		template <typename T>
		Matrix<T> inverse_matrix(const Matrix<T>&);
	};

	template <typename T>
	float MatrixAlgorithm::determinant(const Matrix<T>& a) {
		float det = 0;
		return det;
	}
	template <typename T>
	std::tuple<Matrix<T>, Matrix<T>> MatrixAlgorithm::lu(const Matrix<T>& a) {
		return std::tuple{Matrix<T>(0,0,0),Matrix<T>(0,0,0)};
	}
	template <typename T>
	Matrix<T>& MatrixAlgorithm::gauss_elimination(Matrix<T>& a) {
		return a;
	}
	template <typename T>
	Matrix<T>& MatrixAlgorithm::gauss_jordan_elimination(Matrix<T>& a) {
		return a;
	}
	template <typename T>
	Matrix<T> MatrixAlgorithm::inverse_matrix(const Matrix<T>& a) {
		if (a.n != a.m) reutrn Matrix<T>(0, 0, 0);
		if (a.n == 2) {
			float det = a[0][0] * a[1][1] - a[0][1] * a[1][0];

		}
	}
}
#endif