#include"matrix.h"
#include"matrix_algorithm.h"

namespace basicmatrix {
	float determinant(const Matrix<float>& a) {
		float det = 0;
		return det;
	}
	std::tuple<Matrix<float>, Matrix<float>> lu(const Matrix<float>& a) {
		return std::tuple{ Matrix<float>(0,0,0),Matrix<float>(0,0,0) };
	}
	Matrix<float>& gauss_elimination(Matrix<float>& a) {
		return a;
	}
	Matrix<float>& gauss_jordan_elimination(Matrix<float>& a) {
		return a;
	}
	Matrix<float> inverse_matrix(const Matrix<float>& a) {
		auto [n, m] = a.size();
		if (n != m) return Matrix<float>(0, 0, 0);
		if (n == 1 && a[0][0]!= 0) {
			return Matrix<float>{ {1/a[0][0]}};
		}
		else if (n == 2) {
			float det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
			return Matrix<float>{{a[1][1]/det,-a[0][1]/det},
								 {-a[1][0]/det,a[0][0]/det}};
		}
		else {
			return Matrix<float>(0,0,0);
		}
	}
}