#include<iostream>
using namespace std;
//class Base
//{
//public:
//	Base()
//	{}
//	Base(int pri)
//		:_pri(pri)
//	{}
//private:
//	int _pri;
//};
//class Derived :public Base
//{
//public:
//	Derived(int priD, int proD)
//		:_priD(priD)
//		, _proD(proD)
//		, Base(50)
//	{}
//private:
//	int _priD;
//	int _proD;
//};
//int main()
//{
//	Base A(10);
//	Derived B(10, 20);
//	A = B;  //赋值兼容规则，派生类对象 可以赋值给 基类的对象 / 基类的指针 / 基类的引用。这里有个形象的说法叫切片或者切割。寓意把派生类中父类那部分切来赋值过去。
//	return 0;
//}

class A
{
public:
	static A& init()
	{
		return A();
	}
	static A& init(int a)
	{
		return A(a);
	}
//private:

	A()  //将所有能被继承用到的函数都给成私有
	{}
	A(int a)
		:_a(a)
	{}
	int _a;
};
class B : public A
{
public:

	//  bnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn         virtual
private:
	int b;
};
int main()
{
	B b;
	b.init(10);
	return 0;
}





//
//int main()
//{
//	A b(A::init(10));  //可以通过这样来创建对象
//	return 0;
//}















