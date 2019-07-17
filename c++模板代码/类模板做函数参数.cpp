#if 0
#include<iostream>
#include<string>
using namespace std;
template <class T1, class T2>
class person
{
public:
	person(T1 a, T2 b)
	{
		this->name = a;
		this->ages = b;
	}
	void func()
	{
		cout << this->name << endl << this->ages << endl;
	}
	T1 name;
	T2 ages;
};
//1.指定传入参数
void funcs(person<string, int> &a)
{
	a.func();
}
void test()
{
	person<string, int>p1("猪八戒", 10);
	funcs(p1);
}
int main()
{
	test();
	return 0;
}
#endif
#include<iostream>
#include<string>
using namespace std;
template <class T1, class T2>
class person
{
public:
	person(T1 a, T2 b)
	{
		this->name = a;
		this->ages = b;
	}
	void func()
	{
		cout << this->name << endl << this->ages << endl;
	}
	T1 name;
	T2 ages;
};
template<class T>
void funcs(T &a)
{
	cout << typeid(T).name() << endl;
	a.func();
}
void test()
{
	person<string, int>p1("猪八戒", 10);
	funcs(p1);
}
int main()
{
	test();
	return 0;
}