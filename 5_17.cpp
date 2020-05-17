#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
void Fun(int &x)
{
	cout << "lvalue ref" << endl; 
}
void Fun(int &&x)
{
	cout << "rvalue ref" << endl;
}
void Fun(const int &x)
{
	cout << "const lvalue ref" << endl; 
}
void Fun(const int &&x)
{
	cout << "const rvalue ref" << endl; 
}
template<typename T>
void PerfectForward(T &&t)
{
	Fun(std::forward<T>(t)); 
}
//int main()
//{
//
//	//PerfectForward(10); // rvalue ref
//
//	//int a;
//	//PerfectForward(a); // lvalue ref
//	//PerfectForward(std::move(a)); // rvalue ref
//	//const int b = 8;
//	//PerfectForward(b); // const lvalue ref
//	//PerfectForward(std::move(b)); // const rvalue ref
//
//	//vector<int> vec = { 7, 4, 1, 8, 5, 2, 0, 9, 6, 3 };
//	//sort(vec.begin(), vec.end());
//	////上述的默认是升序排序
//
//	//sort(vec.begin(), vec.end(), greater<int>());
//
//	int a = 10, b = 20, c = 30;
//	auto Swap = [](int& L,int& R)
//	{
//		int temp = L;
//		L = R;
//		R = temp;
//	};
//	Swap(a, b);
//	cout << a << " " << b<<endl;
//
//	return 0;
//}
int main()
{
	int a = 10, b = 20, c = 30;
	auto p1 = [&a](){ a = 20; };
	p1();
	cout << a << endl;

	auto p2 = [&](){a = 30, b = 10, c = 20; };
	p2();
	cout << a <<" "<< b <<" "<< c << endl;

	//值传递的在内部无法修改
	auto p3 = [=]()mutable{ a = 10000, b = 20000, c = 30000; };
	cout << a << " " << b << " " << c << endl;

	cout << a << endl;

}