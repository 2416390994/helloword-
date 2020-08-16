#include<iostream>
using namespace std;
//class A
//{
//public:
//	  ~A()
//	{
//		cout << "析构A" << endl;
//	}
//
//	//int a;
//};
//
//class B  :public A
//{
//public:
//	~B()
//	{
//		cout << "析构B" << endl;
//	}
//
//	int b;
//};
//void func(A* a)
//{
//	delete a;
//}
//
//
//
//int main()
//{
//
//	A* p = new B;
//	delete p;
//	return 0;
//}




//int main()
//{
//	int(*(*func)[5])(int* p);
//	int(******(******func)[5])(int* p);
//
//
//	return 0;
//}


//class A
//{
//public:
//	A()
//	{
//		cout << "A" << endl;
//	}
//	virtual ~A()  //注意这里将析构函数给成了虚函数
//	{
//		cout << "~A()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	B() :p(new int[10])
//	{
//		cout << "B" << endl;
//	}
//	~B()
//	{
//		delete[] p;
//		cout << "~B()" << endl;
//	}
//	int* p;
//};
//void test()
//{
//	A* p = new B;
//	delete p;
//}
//int main()
//{
//	test();
//	return 0;
//}

int func(int x, int y)
{
	if (x < y)
		swap(x, y);
	int temp = x % y;
	x = y;
	y = temp;
	return func(x, y);
}


















