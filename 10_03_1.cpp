#include<iostream>
using namespace std;
//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====定义引用类型
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//}
//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a;   // 该语句编译时会出错，a为常量
//	const int& ra = a;
//	// int& b = 10; // 该语句编译时会出错，b为常量
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	const int& rd = d;
//}

	//TestRef();
	//TestConstRef();
	/*const int a = 10;
	const int& b = a;
	const int& c = 10;
	double d = 12.34;
	const int& ret = d;
	cout << a << endl << b << endl << c << endl << ret << endl;*/
void func(int &c)
{
	cout << c << endl;
	cout << &c << endl;
}
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}
//int  main()
//{
//	int a = 10;
//	cout << &a << endl;
//	int* b = &a;
//	func(a);
//	return 0;
//}