#ifndef MATRIX_H//vectorがswapの謎技以外でメモリ開放する方法内のま？
#define MATRIX_H//initializerlist使えるようにしたい
#include<cstdint>
#include<vector>
#include<iostream>
#include<tuple>
#include<cstdint>
#include<functional>//多分matricl_altgo classを作った方がよい
#include"internal_vactor.h"
static std::vector<std::tuple<int, int>> dirs = { {1,0},{-1,0},{0,1},{0,-1},{0,0} };
namespace basicmatrix {
	template <typename T>
	class Matrix;
	//template <typename T>
	//Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b);

	//template <typename T>
	//class vector_;
	

	template<typename T>
	class Matrix {
	private:
	public:
		std::vector<std::vector<T> > mat;
		uint16_t n;
		uint16_t m;

		Matrix(uint16_t, uint16_t, T);
		Matrix(const Matrix&);//コピーコンストラクタ
		Matrix(Matrix&& a)noexcept;//ムーブコンストラクタ
		Matrix();//引数なしコンストラクタ
		Matrix(std::initializer_list<std::initializer_list<T>>);//初期化リスト可能
		~Matrix();
		std::tuple<int, int> size()const;
		void print(void)const;
		void resize(uint16_t, uint16_t, T);
		std::tuple<int, int> size();
		Matrix& transposition();
		Matrix& row_calc(uint16_t, uint16_t, std::function<std::tuple<T, T>(T, T)>);
		Matrix& column_calc(uint16_t, uint16_t, std::function<std::tuple<T, T>(T, T)>);
		Matrix& row_swap(uint16_t, uint16_t);
		Matrix& column_swap(uint16_t, uint16_t);

		Matrix joint_left(const Matrix&)const;
		Matrix joint_right(const Matrix&)const;
		Matrix joint_top(const Matrix&);
		Matrix joint_buttom(const Matrix&);

		Matrix& operator=(const Matrix&)&;//コピー代入演算子
		Matrix& operator=(Matrix&& a) & noexcept;//ムーブ代入演算子

		const std::vector<T>& operator[](uint16_t)const&;//値参照用
		std::vector<T>& operator[](uint16_t)&;//値変更用
		std::vector<T> operator[](uint16_t)const&&;//右辺値用

		template <typename U>
		friend Matrix<U> operator+(const Matrix<U>&, const Matrix<U>&);
		template <typename U>
		friend Matrix<U> operator-(const Matrix<U>&, const Matrix<U>&);
		template <typename U>
		friend Matrix<U> operator*(const Matrix<U>&, const Matrix<U>&);

	};

	template <typename T>
	Matrix<T>::Matrix(uint16_t n, uint16_t m, T val) :n(n), m(m) {
		this->mat.resize(n);
		for (int i = 0; i < n; i++) {
			this->mat[i].resize(m);
			std::fill<std::vector<T>::iterator,T>(this->mat[i].begin(), this->mat[i].end(), val);
		}
	}
	/*template<typename T>
	Matrix<T>::Matrix(int n, int m) :n(n* m), m(n* m) {
		this->mat.resize(this->n);
		for (int i = 0; i < this->n; i++) {
			this->mat[i].resize(this->m);
			std::fill(this->mat[i].begin(), this->mat[i].end(), 0);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int row = i * m + j;
				for (auto dir : dirs) {
					auto [dx, dy] = dir;
					int nx = j + dx;
					int ny = i + dy;
					if (0 <= nx && nx < m && 0 <= ny && ny < n) {
						this->mat[row][m * ny + nx] = 1;
					}
				}
			}
		}
	}
	template <typename T>
	Matrix<T>::Matrix(int n) :n(n), m(n) {
		this->mat.resize(this->n);
		for (int i = 0; i < this->n; i++) {
			this->mat[i].resize(this->m);
			std::fill(this->mat[i].begin(), this->mat[i].end(), 0);
			this->mat[i][i] = 1;
		}
	}*/


	template <typename T>
	Matrix<T>::Matrix(const Matrix& a):n(a.n),m(a.m),mat(a.mat){
		//std::cout << "copy\n";
	}
	template <typename T>
	Matrix<T>::Matrix(Matrix&& a)noexcept{
		//std::cout << "move\n";
		if (this == &a) return;
		*this = std::move(a);
	}
	template <typename T>
	Matrix<T>::Matrix():n(0),m(0) {};
	template <typename T>
	Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init) {
		this->n = static_cast<uint16_t>(init.size());
		if (this->n == 0) {
			this->m = 0;
			this->mat = std::vector<std::vector<T>>(0, std::vector<T>(0));
			return;
		}
		this->mat.resize(this->n);
		uint16_t m_ = 0;
		for (auto& row: init) {
			if (m_ < static_cast<uint16_t>(row.size())) m_ = static_cast<uint16_t>(row.size());
		}
		this->m = m_;
		int i = 0;
		for (auto& row : init) {
			uint16_t size_ = static_cast<uint16_t>(row.size());
			//std::cout << size_ << std::endl;
			//std::cout << this->mat[i].size() << std::endl;
			std::copy(row.begin(), row.end(), std::back_inserter(this->mat[i]));
			this->mat[i].resize(m_);
			std::fill<std::vector<T>::iterator,T>(this->mat[i].begin() + size_, this->mat[i].end(), 0);
			i++;
		}
	}
	template <typename T>
	Matrix<T>::~Matrix() {
	}
	template <typename T>
	std::tuple<int, int> Matrix<T>::size()const {
		return std::tuple<int, int>{this->n, this->m};
	}
	template <typename T>
	void Matrix<T>::print(void)const{
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->m; j++) {
				std::cout << this->mat[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	template <typename T>
	void Matrix<T>::resize(uint16_t new_n, uint16_t new_m,T val) {
		this->mat.resize(new_n);
		for (auto& row : this->mat) {
			row.resize(new_m,val);
		}
		this->n = new_n;
		this->m = new_m;
	}
	template <typename T>
	std::tuple<int, int> Matrix<T>::size() {
		return std::tuple<int,int>{this->n,this->m};
	}
	template <typename T>
	Matrix<T>& Matrix<T>::transposition() {
		std::vector<std::vector<T>> new_mat(this->m,std::vector<T>(this->n,0));
		for (int i = 0; i < this->n;i++) {
			for (int j = 0; j < this->m;j++) {
				new_mat[j][i] = this->mat[i][j];
			}
		}
		std::vector<std::vector<T>>().swap(this->mat);
		this->mat = new_mat;
		std::swap(this->n,this->m);
		return *this;
	}
	template <typename T>
	Matrix<T>& Matrix<T>::row_calc(uint16_t l1, uint16_t l2, std::function<std::tuple<T, T>(T, T)> process) {
		if (l1 >= this->n || l2 >= this->n) return *this;
		for (int i = 0; i < this->m; i++) {
			auto [v1, v2] = process(this->mat[l1][i], this->mat[l2][i]);
			this->mat[l1][i] = v1;
			this->mat[l2][i] = v2;
		}
		return *this;
	}
	template <typename T>
	Matrix<T>& Matrix<T>::column_calc(uint16_t c1, uint16_t c2, std::function<std::tuple<T, T>(T, T)> process) {
		if (c1 >= this->m || c2 >= this->m) return *this;
		for (int i = 0; i < this->n; i++) {
			auto [v1, v2] = process(this->mat[i][c1], this->mat[i][c2]);
			this->mat[i][c1] = v1;
			this->mat[i][c2] = v2;
		}
		return *this;
	}
	template <typename T>
	Matrix<T>& Matrix<T>::row_swap(uint16_t l1, uint16_t l2) {
		if (l1 >= this->n) return *this;
		if (l2 >= this->n) return *this;
		this->mat[l1].swap(this->mat[l2]);
		return *this;
	}
	template <typename T>
	Matrix<T>& Matrix<T>::column_swap(uint16_t c1, uint16_t c2) {
		if (c1 >= this->m) return *this;
		if (c2 >= this->m) return *this;
		for (auto& row : this->mat) {
			std::swap(row[c1],row[c2]);
		}
		return *this;
	}
	template <typename T>
	Matrix<T> Matrix<T>::joint_right(const Matrix& a) const {
		if (a.n != this->n)return Matrix<T>(0, 0, 0);
		Matrix<T> res(n, 0, 0);
		for (int i = 0; i < a.n; i++) {
			std::copy(this->mat[i].begin(), this->mat[i].end(), std::back_inserter(res.mat[i]));
			std::copy(a.mat[i].begin(), a.mat[i].end(), std::back_inserter(res.mat[i]));
		}
		res.m = this->m + a.m;
		return res;
	}
	template <typename T>
	Matrix<T> Matrix<T>::joint_left(const Matrix& a) const {
		if (a.n != this->n)return Matrix<T>(0, 0, 0);
		Matrix<T> res(n, 0, 0);
		for (int i = 0; i < a.n; i++) {
			std::copy(a.mat[i].begin(), a.mat[i].end(), std::back_inserter(res.mat[i]));
			std::copy(this->mat[i].begin(), this->mat[i].end(), std::back_inserter(res.mat[i]));
		}
		res.m = this->m + a.m;
		return res;
	}
	template <typename T>
	Matrix<T> Matrix<T>::joint_top(const Matrix<T>& a) {
		if (a.m != this->m) return Matrix<T>(0, 0, 0);
		Matrix<T> res(a.n + this->n, 0, 0);
		int i = 0;
		for (; i < a.n; i++) {
			std::copy(a.mat[i].begin(), a.mat[i].end(), std::back_inserter(res.mat[i]));
		}
		for (int j = 0; j < this->n; j++) {
			std::copy(this->mat[j].begin(), this->mat[j].end(), std::back_inserter(res.mat[i]));
			i++;
		}
		res.m = a.m;
		return res;
	}
	template <typename T>
	Matrix<T> Matrix<T>::joint_buttom(const Matrix<T>& a) {
		if (a.m != this->m) return Matrix<T>(0, 0, 0);
		Matrix<T> res(a.n + this->n, 0, 0);
		int i = 0;
		for (; i < this->n; i++) {
			std::copy(this->mat[i].begin(), this->mat[i].end(), std::back_inserter(res.mat[i]));
		}
		for (int j = 0; j < a.n; j++) {
			std::copy(a.mat[j].begin(), a.mat[j].end(), std::back_inserter(res.mat[i]));
			i++;
		}
		res.m = a.m;
		return res;
	}

	template <typename T>
	Matrix<T>& Matrix<T>::operator=(const Matrix<T>& a)&/*右辺値に代入しないように*/ {
		//std::cout << "copy=\n";
		if (this == &a) return *this;
		std::vector<std::vector<T>>().swap(this->mat);//swap技は推奨されない
		this->mat = a.mat;
		this->n = a.n;
		this->m = a.m;
		return *this;
	}
	template <typename T>
	Matrix<T>& Matrix<T>::operator=(Matrix<T>&& a) & noexcept {
		//std::cout << "move=\n";
		if (this == &a) return *this;
		this->mat = std::move(a.mat);
		this->n = a.n;
		this->m = a.m;
		return *this;
	}
	template <typename T>
	const std::vector<T>& Matrix<T>::operator[](uint16_t i)const& {
		if (this->n == 0) {
			throw std::out_of_range("error:empty object.\n");
		}
		if (i >= this->n) {
			throw std::out_of_range("error:index out of range.\n");
		}
		return this->mat.at(i);
	}
	template <typename T>
	std::vector<T>& Matrix<T>::operator[](uint16_t i)& {
		if (this->n == 0) {
			throw std::out_of_range("error:empty object.\n");
		}
		if (i >= this->n) {
			throw std::out_of_range("error:index out of range.\n");
		}
		return this->mat.at(i);
	}
	template <typename T>
	std::vector<T> Matrix<T>::operator[](uint16_t i)const&& {
		if (this->n == 0) {
			throw std::out_of_range("error:empty object.\n");
		}
		if (i >= this->n) {
			throw std::out_of_range("error:index out of range.\n");
		}
		return this->mat.at(i);
	}

	template <typename T>
	Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
		if (a.n != b.n || a.m != b.m) return Matrix<T>(0, 0, 0);
		Matrix<T> res(a.n, a.m, 0);
		for (int i = 0; i < a.n; i++) {
			for (int j = 0; j < a.m; j++) {
				res[i][j] = a[i][j] + b[i][j];
			}
		}
		return res;
	}
	template <typename T>
	Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b) {
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
		std::cout << a.m << " " << b.n << std::endl;
		if (a.m != b.n) return Matrix<T>(0, 0, 0);
		Matrix<T> res(a.n, b.m, 0);
		for (int i = 0; i < a.n; i++) {
			for (int j = 0; j < b.m; j++) {
				T sum = 0;
				for (int k = 0; k < a.m; k++) {
					sum += a[i][k] * b[k][j];
				}
				res[i][j] = sum;
			}
		}
		return res;
	}

	template <typename T>
	class Vector :public virtual Matrix<T> {
	private:
	public:
		Vector(int, T);
	};
	template <typename T>
	Vector<T>::Vector(int n, T val) :Matrix<T>(n, 1, val) {
	};

}
#endif