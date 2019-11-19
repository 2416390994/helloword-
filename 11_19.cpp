#include<iostream>
#include<string>
using namespace std;
//class A
//{
//public:
//	int _a;
//};
//class B : public virtual A
//{
//public:
//	int _b;
//};
//class C : public virtual A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//class A
//{
//public:
//	int _a;
//};
//class B : public virtual A
//{
//public:
//	int _b;
//};
/*cout << sizeof(D) << endl;
D d;
d._a = 1;
d._b = 2;
d._c = 3;
d._d = 4;*/

class 人类
{
public:
	人类(string 名字,string 性别,int 年龄)
		:_名字(名字)
		, _性别(性别)
		, _年龄(年龄)
	{}
	virtual void 买票()
	{
		cout << "全价票" << endl;
	}
protected:
	string _名字;  //姓名
	string _性别;   //性别
	int _年龄;  //年龄
};

class 学生类 : public 人类
{
public:
	学生类(string 名字, string 性别, int 年龄, int 学号)
		:人类(名字, 性别, 年龄)
		,_学号(学号)
	{}
	virtual void 买票()
	{
		cout << "半价票" << endl;
	}
protected:
	int _学号;  //学号
};
class 军人类 : public 人类
{
public:
	军人类(string 名字, string 性别, int 年龄, string 军衔)
		:人类(名字, 性别, 年龄)
		, _军衔(军衔)
	{}
	virtual void 买票()
	{
		cout << "免票" << endl;
	}
protected:
	string _军衔;  //学号
};
//int main()
//{
//	军人类 张超伦("张超伦", "男", 28,"大佐");
//	学生类 小董("小董", "男", 20, 1740);
//	人类& 九一刘先生 = 张超伦;  //发生多态
//	人类& 小王 = 小董;   //发生多态
//	九一刘先生.买票();
//	小王.买票();
//	return 0;
//}
//class Base
//{
//public:
//	virtual Base* test()
//	{
//		cout << "base()" << endl;
//		return this;
//	}
//};
//class Dri : public Base
//{
//public:
//	virtual Dri* test()
//	{
//		cout << "Dri()" << endl;
//		return this;
//	}
//};
//class A
//{
//public:
//	A()
//	{
//		cout << "A" << endl;
//	}
//	 ~A()  //注意这里将析构函数给成了虚函数
//	{
//		cout << "~A()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	B() :p(new int[10])
//	{
//		cout << "B" << endl;
//	}
//	~B()
//	{
//		delete[] p;
//		cout << "~B()" << endl;
//	}
//	int* p;
//};
//class A
//{
//public:
//	virtual void 函数()
//	{
//		cout << "A" << endl;
//	}
//};
//class B : public A 
//{
//public:
//	virtual void 函数()
//	{
//		cout << "B" << endl;
//	}
//};
//void test()
//{
//	B b;
//	A& p = b;
//	p.函数();
//}
#include<iostream>
#include<vector>
using namespace std;
bool test(int a)
{
	int x = 2;
	int flag = 0;
	for (int i = x; i <= sqrt(a); ++i)
	{
		while (a % i == 0)
		{
			flag = 1;
			break;
		}
		if (flag == 1)
			break;
	}
	if (a == 2 || flag == 1)
		return false;
	return true;
}
int main()
{
	int a;
	int b;
	cin >> a;
	int x = 2;
	int flag = 0;
	vector<int> vec;
	for (int i = 1; i < a; ++i)
	{
		if (test(i) == true)
			vec.push_back(i);
	}
	int a1 = 1000000;
	int a2 = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		auto it = find(vec.begin(), vec.end(), a - vec[i]);
		if (it != vec.end())
		{
			int a3 = vec[i];
			int a4 = *it;
			if (a3 < a4)
				swap(a3, a4);
			if (a1 - a2 > a3 - a4)
			{
				a1 = a3;
				a2 = a4;
			}
		}
	}
	cout << a1 << endl;
	cout << a2 << endl;
	return 0;
}