#include<iostream>
#include<string>
using namespace std;

class A
{
	int _a;
};
class B
{
	int _b;
};
class C : public A, public B
{
	int _c;
};
int main()
{


	cout << sizeof(C) << endl;
	return 0;
}
