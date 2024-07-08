#include"matrix.h"
#include<iostream>


int main() {
	Matrix<int>n(2, 3,2);
	Matrix<int>m(3, 2, 1);
	//n = m;
	//n.print();
	m[1][1] = 4;
	//std::cout << m.n<<m.m<<m[1][1];
	//m.print();
	(n*m).print();
	//r.print();
}