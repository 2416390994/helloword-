#include<iostream>
using namespace std;
#if 0
#include<iostream>
using namespace std;
class Base
{
public:
	Base()
	{}
	Base(int pri)
		:_pri(pri)
	{}
private:
	int _pri;
};
class Derived :public Base
{
public:
	Derived(int priD,int proD)
		:_priD(priD)
		, _proD(proD)
	{}
private:
	int _priD;
	int _proD;
};
int main()
{
	Base *A;
	Derived c(10,20);
	A = &c;
	Derived *d = (Derived*)A;  
	return 0;
}
#endif 
#if 0
class A
{
public:
	//此时基类中没有默认构造函数
	A(int a)  //当用户显示给出有参构造函数时，编译器将不再提供默认的构造函数
	:_a(a)
	{}
private:
	int _a;
};
class B : public A
{
	B()
	:A(10) //此时就必须显示调用 .
	{}
private:
	int _b;
};
int main()
{

	return 0;
}
# endif
#if 0
class A
{
public:
	A()
	{}
	A(int a)
	{
		_a = a;
		cout << 2 << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
	A& operator=(const A& a)
	{
		if (this != &a)
		{
			_a = a._a;
		}
		return *this;
	}
private:
	int _a;
};
class B : public A
{
public:
	B() :A()
	{}
	B(int b,int a)
		:_b(b)
		, A(a)
	{
		cout << 1 << endl;
	}
	B(const B&b)
		:A(b)
	{
		_b = b._b;
		cout << "B(const B& b)" << endl;
	}
	B& operator=(const B& b)
	{
		if (this != &b)
		{
			A::operator=(b);
			_b = b._b;
		}
		return *this;
	}
private:
	int _b;
};
#endif
//class A
//{
//public:
//	A()
//	{
//		cout << "A的构造函数" << endl;
//	}
//	~A()
//	{
//		cout << "A的析构函数" << endl;
//	}
//private:
//	int _a;
//};
//class B : public A
//{
//public:
//	B()
//	{
//		cout << "B的构造函数" << endl;
//	}
//	~B()
//	{
//		cout << "B的析构函数" << endl;
//	}
//private:
//	int _b;
//};
//class A
//{
//public:
//	static A& init()
//	{
//		return A();
//	}
//	static A& init(int a)
//	{
//		return A(a);
//	}
//private:
//	A()  //将所有能被继承用到的函数都给成私有
//	{}
//	A(int a)
//	{}
//	int _a;
//};
//int main()
//{
//	A b(A::init(10));  //可以通过这样来创建对象
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int getLCA(int a, int b) {
//	if (a < b)
//	{
//		swap(a, b);
//	}
//	int num1 = 1;
//	int num2 = 1;
//	while (num2 < b)
//	{
//		num2 = (num1 * 2) - 1;
//		num1 = num1 * 2;
//	}
//	while (a > num2)
//	{
//		a = a / 2;
//	}
//	while (a != b)
//	{
//		a = a / 2;
//		b = b / 2;
//	}
//	return a;
//}
class A
{
public:
	int _a;
};
class B : public A
{
public:
	int _b;
};
class C :public A
{
public:
	int _c;
};
class D : public B ,public C
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._a = 1;
	return 0;
}