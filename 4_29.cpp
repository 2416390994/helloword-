#include<iostream>
#include<string>
#include<vector>
#include<time.h>
using namespace std;
#define M 10;
typedef  int INT;

void funv()
{

	
	clock_t a;
	clock_t b;

	a = clock();
	int xc = 10;
	for (int i = 0; i <= 1000000000; ++i)
	{
		xc++;
	}
	b = clock();
	cout << b - a << endl;
}

void func(int& a,int& x)
{
	int temp = a;
	a = x;
	x = temp;

}

int main()
{/*
	int a = 10;
	int* p = nullptr;
	func(a, *p);*/
	/*INT a = 10;
	cout << a << endl;*/

	auto x = 0;


	int a = 10;
	auto e = a;
	string s;
	decltype(a) c = 10;

	/*const int a = 10;
	int const b = 20;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << a << " " << b << endl;
*/
	/*int a = 10;
	int c = 20;
	int   &b = a;
	cout << a << endl;
	*/
	//funv();
	return 0;
}