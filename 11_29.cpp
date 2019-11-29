#include<iostream>
using namespace std;
class Base
{
public:
	/*virtual void func1()
	{
		cout << "base::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "base::func2()" << endl;
	}
	virtual void func3()
	{
		cout << "base::func3()" << endl;
	}*/
	void func4()
	{
		cout << "base::func4()" << endl;
	}
	int a = 20;
};
class Dev : public Base
{
public:
	/*virtual void func1()
	{
		cout << "func1" << endl;
	}
	virtual void func2()
	{
		cout << "func2" << endl;
	}
	virtual void func3()
	{
		cout << "func3" << endl;
	}*/
	void func4()
	{
		cout << "func4" << endl;
	}
	int a = 30;
};
void TestVirtual(Base* pb)
{
	pb->func4();
	pb->a = 10;
}
int main()
{
	Base a;
	Dev b;
	b.Base::func4();
	TestVirtual(&b);
	cout << a.a << endl;
	cout << b.a << endl;
	
	return 0;
}