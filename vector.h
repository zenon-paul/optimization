#ifndef MATRIX_VECTOR_
#define MATRIX_VECTOR_
#include<vector>
#include"matrix.h"

namespace basicmatrix{
	template <typename T>
	class Vector :public virtual Matrix<T> {
	private:
		bool is_row_vector;//óÒÅ@çsÅ@ÇÃãÊï ÇÕVector ì∆ì¡ÇÃÇ‡ÇÃ
	public:
		Vector(int, T,bool f = true);
		uint16_t size()const override;
		void resize(uint16_t,T) override;
	};

	template <typename T>
	Vector<T>::Vector(int n, T val,bool f) 
		:Matrix<T>(f?1:n,f?n:1, val),is_row_vector(f){
	}
	template <typename T>
	uint16_t Vector<T>::size()const{
		auto [n, m] = this->size();
		if (this->is_row_vector) return m;
		else return n;
	}
	template <typename T>
	void Vector<T>::resize(uint16_t new_s, T val) {
		if (this->is_row_vector) this->row_resize(new_s, val);
		else this->column_rezise(new_s,val);
	}
}
#endif