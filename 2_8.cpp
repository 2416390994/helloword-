#include<iostream>
using namespace  std;
struct ss
{
	char g;
	short h;
	short s;
	char w;
};
struct Node
{
	int a;
	char b;
	char c;
	int d;
	ss s;
	short e;
};
class A
{
public:
	A()
	{
	}
	static void func()
	{
	
	}

private:
	static int b;
};
int A::b = 10;
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(Node) << endl;
	return 0;
}