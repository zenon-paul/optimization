#ifndef MATRIX_ALGORITHM
#define MATRIX_ALGORITHM
#include"matrix.h"
#include<tuple>
namespace basicmatrix {
	
	float determinant(const Matrix<float>&);

	std::tuple<Matrix<float>, Matrix<float>> lu(const Matrix<float>&);

	Matrix<float>& gauss_elimination(Matrix<float>&);

	Matrix<float>& gauss_jordan_elimination(Matrix<float>&);

	Matrix<float> inverse_matrix(const Matrix<float>&);

	
}
#endif