#include<iostream>
using namespace std;
class A
{
public:

	A()
	{
		cout << "A的构造函数" << endl;
	}
	virtual void func()
	{
	
	}
	~A()
	{
		cout << "A的析构函数" << endl;
	}
};

class B:public A
{

public:
	B()
	{
		cout << "B的构造函数" << endl;
	}

	virtual void func()
	{

	}
	~B()
	{
		cout << "B的析构函数" << endl;
	}
};
class B :public A
{

public:
	B()
	{
		cout << "B的构造函数" << endl;
	}

	virtual void func()
	{

	}
	~B()
	{
		cout << "B的析构函数" << endl;
	}
};
int main()
{
	//B b;
	A* a = new B();
	delete a;
	return 0;
}