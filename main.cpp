#include"matrix.h"
#include<iostream>
#include<tuple>
//#include<boost>boost c++のライブラリ実装の前段階にある者たち
namespace mmt = basicmatrix;
//mmt::Matrix<int> AI(5, 6);
//mmt::Matrix<int> I(30);
//mmt::Matrix<int> s(30,1,0);
//mmt::Matrix<int> q = AI.joint_right(I);
/*void gxor() {
	for (int i = 0; i < 30;i++) {
		if (q[i][i] == 0) {
			for (int k = i+1; k < 30;k++) {
				if (q[k][i] == 1) {
					q.row_swap(i,k);
				}
			}
		}
		for (int j = 0; j < 30;j++) {
			if (q[j][i] == 1 && j!= i) {
				q.row_calc(i, j, [](int v1, int v2) {return std::tuple{v1,(v1!=v2?1:0)}; });
				//q.print();
				//printf("\n");
			}
		}
	}
}*/
void func(mmt::Matrix<float> b) {

}
int main() {
	//q[24][30] = 1;
	//q[29][30] = 1;	
	//mmt::Matrix<int> h;
	//mmt::Matrix<int>nn(2, 4,2);
	//mmt::Matrix<int>kk(2, 4,1);
	//std::cout << nn.mat.size() << nn.mat[0].size()<< std::endl;
	//std::cout << kk.mat.size() << kk.mat[0].size()<< std::endl;
	//h = nn + kk;
	//h.print();
	//auto [y, x] = n.size();
	//printf("%d %d",x,y);
	//m[0][0] = 3;
	//m[0][1] = 4;
	//m.print();
	//(m.row_swap(0,1) + n).print();
	//n.joint_top(m).print();
	//n.joint_buttom(m).print();
	//Matrix<int>r = n.joint_right(m);
	//m.row_swap(0, 1).print();
	//q.print();
	//gxor();
	//q.print();
	//printf("%d %d",q.n,q.m);
	//r.row_gauss(0, 1, [](double v1, double v2) {std::tuple<double, double> res{ v1 + v2,v2 }; return res; });
	//r.print();
	//Matrix<int> test(5,6);
	//test.print();
	//n = m;
	//n.print();
	//std::cout << m.n<<m.m<<m[1][1];
	//m.print();
	//(n*m).print();
	//r.print();
	//mmt::Matrix<int> a(2,3,1);
	//a[1][1] = 2;
	//a.print();
	//mmt::Vector<int> v(3,3);
	//v.print();
	//(a*v).print();
	/*int n[3]{1,2,3};
	int k = 0;
	int i = 3;
	try {
		if (i >= 3) {
			throw ("this is throw test");
		}
	}catch(const char* s){//文字列だからconst char*だよ
		std::cout << s << std::endl;
	}
	printf("end\n");
    mmt::Matrix<int>m(5,5,1);
	m[2][2] = 4;
	m.column_swap(2, 3).print();
	m.resize(10,3,5);
	m.transposition().print();
	mmt::Matrix<int> mmm(2,3,4);
	mmt::Matrix<int> jjj(mmm);
	std::vector<int>::iterator itr1 = mmm.mat[0].begin();
	std::vector<int>::iterator itr2 = jjj.mat[0].begin();
	std::cout << &*itr1 << std::endl;
	std::cout << &*itr2 << std::endl;
	std::vector<std::vector<int>> s(2, std::vector<int>(2, 4));
	std::vector<std::vector<int>> s2;
	s2 = s;
	s2[1][1] = 3;
	std::cout << s[1][1] << s2[1][1] << std::endl;*/
	/*std::vector<int> v{2,3};
	std::vector<int> vv(2, 3);
	for (auto val :v) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
	for (auto val:vv) {
		std::cout << val << " ";
	}*/
	/*mmt::Matrix<float> t(2,5,2.0f);
	mmt::Matrix<float> m = { {1.5f,2.5f,3.5f},
							{2.2f,3.2f,4.2f,5.2f,6.2f}};
	mmt::Matrix<float> m2 = m;
	t.print();
	m.print();
	t.transposition();
	(t+m).print();
	mmt::Matrix<float> h = m * t;
	mmt::Matrix<float> u = mmt::Matrix<float>(2,2,9.0f);
	auto [nnum, mnum] = h.size();
	std::cout << nnum << " " << mnum << std::endl;
	h.print();*/
	mmt::Matrix<float> a(1,2,5);
	mmt::Matrix<float> f = mmt::Matrix<float>(1, 2, 3);
	mmt::Matrix<float> fff = a + f;
	(a + f).print();
	a = f;
	func(a);
	mmt::vector_<int> v(2, 3);
	mmt::vector_<int> b(5, 7);
	std::copy(b.begin(),b.end(),std::back_inserter(v));
	std::fill<std::vector<int>::iterator, int>(v.begin(),v.end(),5);
	v.swap(b);
	for (const auto num : v) {
		std::cout << num << " ";
	}
	std::cout<<std::endl;
}