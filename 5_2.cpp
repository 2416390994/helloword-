#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;
//void func()
//{
//	int a = 10;
//	bitset<8> c(a);
//	cout << c << endl;
//	cout << typeid(c).name() << endl;
//	cout << sizeof(c) << endl;
//}
void func()
{
	int * p = new int;
	cout << *p << endl;
}


int main()
{
	func();
	return 0;
}