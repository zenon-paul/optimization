#ifndef INTERNAL_VECTOR_
#define INTERNAL_VECTOR_

#include<vector>
#include<cstdint>

namespace basicmatrix {
	template<typename T, typename Allocator = std::allocator<T>>
	class vector_ :public std::vector<T, Allocator> {
	public:
		vector_(uint16_t s, const T& v, const Allocator& a = std::allocator<T>::allocator()) :std::vector<T, Allocator>(s, v, a) {}
		const T& operator[](uint16_t n)const& {
			if (this->size() == 0) {
				throw std::out_of_range("error:empty object.\n");
			}
			if (n >= this->size()) {
				throw std::out_of_range("error:index out of range.\n");
			}
			return this->at(n);
		}
		T& operator[](uint16_t n)& {
			if (this->size() == 0) {
				throw std::out_of_range("error:empty object.\n");
			}
			if (n >= this->size()) {
				throw std::out_of_range("error:index out of range.\n");
			}
			return this->at(n);
		}
		T operator[](uint16_t n)const&& {
			if (this->size() == 0) {
				throw std::out_of_range("error:empty object.\n");
			}
			if (n >= this->size()) {
				throw std::out_of_range("error:index out of range.\n");
			}
			return this->at(n);
		}
	};
}
#endif