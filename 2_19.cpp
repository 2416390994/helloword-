#include<iostream>
using namespace std;
int func(int* a,int b,int&c)
{
	cout << "func"<<&a << endl;
	cout << "func" << &b << endl;
	cout << "func" << &c << endl;
	return 0;
}
int** func2()
{
	int a = 10;
	int* b = new int[10];
	cout << &b << endl;
	//cout << &a << endl;
	return &b;
}
int main()
{
	int** a = func2();
	delete[] *a;
	cout << &a << endl;

	/*char* e = "123";
	int* a = nullptr;
	int b = 2;
	int c = 10;
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	int d = func(a, b, c);*/
	return 0;
}