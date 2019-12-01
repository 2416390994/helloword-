//#include<iostream>
//using namespace std;
////class Base
////{
////public:
////	virtual void func1()
////	{
////		cout << "Base::func1()" << endl;
////	}
////	virtual void func2()
////	{
////		cout << "Base::func2()" << endl;
////	}
////	virtual void func3()
////	{
////		cout << "Base::func3()" << endl;
////	}
////	void func4()
////	{
////		cout << "Base::func4()" << endl;
////	}
////	int _a = 10;
////};
////class Derivate : public Base
////{
////public:
////	virtual void func1()
////	{
////		cout << "Derivate::func1()" << endl;
////	}
////	virtual void func2()
////	{
////		cout << "Derivate::func2()" << endl;
////	}
////	virtual void func3()
////	{
////		cout << "Derivate::func3()" << endl;
////	}
////	void func4()
////	{
////		cout << "Derivate::func4()" << endl;
////	}
////	int _a = 20;
////};
//////虚函数的调用通过基类的指针或者引用来调用
////void testfunc(Base* ps)
////{
////	ps->func1();
////	ps->func2();
////	ps->func3();
////	ps->func4();
////}
////int main()
////{
////	
////	Base bas;
////	//testfunc(&bas);
////	Derivate der;
////	Base* pb1 = (Base*)&der;
////	Base* pb2 = (Base*)&der;
////	pb1->func4();
////	pb2->func1();
////	cout << pb1->_a << endl;
////	//testfunc(&der);
////	return 0;
////}
////带有虚函数的多继承派生类对象模型
//
////class B1
////{
////public:
////	virtual void func1()
////	{
////		cout << "B1::func1()" << endl;
////	}
////	virtual void func2()
////	{
////		cout << "B1::func2()" << endl;
////	}
////private:
////	int _b1;
////};
////class B2
////{
////public:
////	virtual void func3()
////	{
////		cout << "B2::func3()" << endl;
////	}
////	virtual void func4()
////	{
////		cout << "B2::func4()" << endl;
////	}
////private:
////	int _b2;
////};
////class C : public B1,public B2
////{
////public:
////	virtual void func1()
////	{
////		cout << "C::func1()" << endl;
////	}
////	virtual void func4()
////	{
////		cout << "C::func4()" << endl;
////	}
////	virtual void func5()
////	{
////		cout << "C::func5()" << endl;
////	}
////private:
////	int _c;
////};
////void test()
////{
////
////}
////int main()
////{
////
////	return 0;
////}
////#include<iostream>
////#include<string>
////#include<vector>
////using namespace std;
//int zuidagongyueshu(int num1, int num2)
//{
//	if (num1 < num2)
//		swap(num1, num2);
//	int num = 1;
//	for (int i = 2; i <= num2; ++i)
//	{
//		if (num1 % i == 0 && num2 % i == 0)
//		{
//			num = num * i;
//			num1 /= i;
//			num2 /= i;
//			i = 2;
//		}
//	}
//	return num;
//}
//int gcd(int m, int n)
//{
//	if (n == 0)
//		return m;
//
//	int temp = m%n;
//	m = n;
//	n = temp;
//	return gcd(m, n);
//}
//int main()
//{
//	int a1;
//	int a2;
//	while (cin >> a1 >> a2)
//	{
//		cout << zuidagongyueshu(a1, a2) << endl;
//		//cout << gcd(a1, a2) << endl;
//	}
//	return 0;
//}
////int main()
////{
////	string str;
////	vector<int> vec;
////	while (getline(cin, str))
////	{
////		for (int i = 5; i < str.size() - 6; ++i)
////		{
////				int a = 0;
////				while (str[i] != ' ' && i < str.size() - 6)
////				{
////					a = (a*10) +str[i] - '0';
////					i++;
////				}
////				vec.push_back(a);
////		}
////		for (int i = 0; i < vec.size(); ++i)
////		{
////			int b = vec[i++];
////			int c = vec[i++];
////			for (int j = 0; j < b; ++j)
////			{
////				if (c >= vec[i])
////				{
////					c = c + vec[i];
////				}
////				else
////				{
////					c += zuidagongyueshu(vec[i], c);
////				}
////				i++;
////			}
////			cout << c << endl;
////		}
////	}
////	return 0;
////}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int zuidagongyueshu(int num1, int num2)
//{
//	if (num1 == 0)
//		return num2;
//	if (num1 < num2)
//		swap(num1, num2);
//	int num = 1;
//	for (int i = 2; i <= num2; ++i)
//	{
//		if (num1 % i == 0 && num2 % i == 0)
//		{
//			num = num * i;
//			num1 /= i;
//			num2 /= i;
//		}
//	}
//	return num;
//}
//int main()
//{
//	int a;
//	int b;
//	while (cin >> a >> b)
//	{
//		int c;
//		for (int i = 0; i < a; ++i)
//		{
//			cin >> c;
//			if (c <= b)
//			{
//				b = b + c;
//			}
//			else
//			{
//				b += zuidagongyueshu(b, c);
//			}
//		}
//		cout << b << endl;
//	}
//	return 0;
//}
////#include <iostream>
////#include <vector>
////using namespace std;
////int zuidagongyueshu(int num1, int num2)
////{
////	if (num1 < num2)
////		swap(num1, num2);
////	int num = 1;
////	for (int i = 2; i <= num2; ++i)
////	{
////		if ((num1 % i == 0) && (num2 % i == 0))
////		{
////			num = num * i;
////			num1 /= i;
////			num2 /= i;
////		}
////	}
////	return num;
////}
////int main()
////{
////	int n, ans;
////	while (cin >> n >> ans)
////	{
////		while (n>0)
////		{
////			int cur;
////			cin >> cur;
////			ans = ans + ((ans<cur) ? zuidagongyueshu(cur, ans) : cur);
////			n--;
////		}
////		cout << ans << endl;
////	}
////	return 0;
////}
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{}
//	virtual ~A()
//	{
//		cout << "A::~A()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	B(int num)
//	{
//		_p = new int(num);
//	}
//	~B()
//	{
//		delete _p;
//		cout << "B::~B()" << endl;
//	}
//	int* _p;
//};
//void func(A* a)
//{
//	a = new B(10);   //动态多态
//}
//int main()
//{
//	A* a = new B(10);   //静态多态
//	func(new B(20));//动态多态,函数调用参数在运行时才会传递，才会确定积累的指针或者引用到底指向哪个子类对象
//	delete a;
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getValue(vector<int> gifts, int n) {
	int count;
	int size = 0;
	for (int i = 0; i < n; ++i)
	{
		if (size == 0)
		{
			count = gifts[i];
			size++ ;
			continue;
		}
		if (count == gifts[i])
			++size;
		else
			--size;
	}
	sort(gifts.begin(), gifts.end());
	if (gifts[n / 2] != count)
		return 0;
	else
		return count;
}
int main()
{
	vector<int> vec = { 2, 5, 5, 2, 2};
	cout<<getValue(vec, 5);
}
