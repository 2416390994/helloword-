#include<iostream>
using namespace std;
class A
{
public:

	A()
	{
		cout << "A�Ĺ��캯��" << endl;
	}
	virtual void func()
	{
	
	}
	~A()
	{
		cout << "A����������" << endl;
	}
};

class B:public A
{

public:
	B()
	{
		cout << "B�Ĺ��캯��" << endl;
	}

	virtual void func()
	{

	}
	~B()
	{
		cout << "B����������" << endl;
	}
};
class B :public A
{

public:
	B()
	{
		cout << "B�Ĺ��캯��" << endl;
	}

	virtual void func()
	{

	}
	~B()
	{
		cout << "B����������" << endl;
	}
};
int main()
{
	//B b;
	A* a = new B();
	delete a;
	return 0;
}