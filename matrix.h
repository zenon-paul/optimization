#ifndef MATRIX_H//vectorがswapの謎技以外でメモリ開放する方法内のま？
#define MATRIX_H
#include<cstdint>
#include<vector>
#include<iostream>
template <typename T>
class Matrix;
template <typename T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b);

template<typename T>
class Matrix {
private:
	std::vector<std::vector<T> > mat;
public:
	int n;
	int m;
	Matrix(int,int,T);
	void print(void)const;

	Matrix& operator=(const Matrix&)&;

	const std::vector<T>& operator[](int)const&;
	std::vector<T>& operator[](int)&;

	template <typename U>
	friend Matrix<U> operator+(const Matrix<U>&,const Matrix<U>&);
	template <typename U>
	friend Matrix<U> operator-(const Matrix<U>&,const Matrix<U>&);
	template <typename U>
	friend Matrix<U> operator*(const Matrix<U>&,const Matrix<U>&);

};

template <typename T>
Matrix<T>::Matrix(int n, int m,T val) :n(n), m(m) {
	this->mat.resize(n);
	for (int i = 0; i < n; i++) {
		this->mat[i].resize(m);
		std::fill(this->mat[i].begin(),this->mat[i].end(),val);
	}
};

template <typename T>
void Matrix<T>::print(void) const{
	for (int i = 0; i < this->n;i++) {
		for (int j = 0; j < this->m;j++) {
			std::cout << this->mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& a) &{
	if (this == &a) return *this;
	std::vector <std::vector<T>>().swap(this->mat);
	this->mat = a.mat;
	this->n = a.n;
	this->m = a.m;
	return *this;
}

template <typename T>
const std::vector<T>& Matrix<T>::operator[](int i)const&{
	if (i >= this->n) {
		throw std::out_of_range("error:index out of range.\n");
	}
	if (this->n == 0) {
		throw std::out_of_range("error:empty object.\n");
	}
	return this->mat[i];
}

template <typename T>
std::vector<T>& Matrix<T>::operator[](int i) &{
	if (i >= this->n) {
		throw std::out_of_range("error:index out of range.\n");
	}
	if (this->n == 0) {
		throw std::out_of_range("error:empty object.\n");
	}
	return this->mat[i];
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
	if (a.n != b.n || a.m != b.m) return Matrix<T>(0, 0, 0);
	Matrix<T> res(a.n, a.m, 0);
	for (int i = 0; i < a.n;i++) {
		for (int j = 0; j < a.m;j++) {
			res[i][j] = a[i][j] + b[i][j];
		}
	}
	return res;
}
template <typename T>
Matrix<T> operator-(const Matrix<T>& a,const Matrix<T>& b) {
	if (a.n != b.n || a.m != b.m) return Matrix<T>(0, 0, 0);
	Matrix<T> res(a.n, a.m, 0);
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.m; j++) {
			res[i][j] = a[i][j] - b[i][j];
		}
	}
	return res;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
	if (a.m != b.n) return Matrix<T>(0, 0, 0);
	Matrix<T> res(a.n, b.m, 0);
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < b.m; j++) {
			T sum = 0;
			for (int k = 0; k < a.m;k++) {
				sum += a[i][k] * b[k][j];
			}
			res[i][j] = sum;
		}
	}
	return res;
}
#endif