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

class ����
{
public:
	����(string ����,string �Ա�,int ����)
		:_����(����)
		, _�Ա�(�Ա�)
		, _����(����)
	{}
	virtual void ��Ʊ()
	{
		cout << "ȫ��Ʊ" << endl;
	}
protected:
	string _����;  //����
	string _�Ա�;   //�Ա�
	int _����;  //����
};

class ѧ���� : public ����
{
public:
	ѧ����(string ����, string �Ա�, int ����, int ѧ��)
		:����(����, �Ա�, ����)
		,_ѧ��(ѧ��)
	{}
	virtual void ��Ʊ()
	{
		cout << "���Ʊ" << endl;
	}
protected:
	int _ѧ��;  //ѧ��
};
class ������ : public ����
{
public:
	������(string ����, string �Ա�, int ����, string ����)
		:����(����, �Ա�, ����)
		, _����(����)
	{}
	virtual void ��Ʊ()
	{
		cout << "��Ʊ" << endl;
	}
protected:
	string _����;  //ѧ��
};
//int main()
//{
//	������ �ų���("�ų���", "��", 28,"����");
//	ѧ���� С��("С��", "��", 20, 1740);
//	����& ��һ������ = �ų���;  //������̬
//	����& С�� = С��;   //������̬
//	��һ������.��Ʊ();
//	С��.��Ʊ();
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
//	 ~A()  //ע�����ｫ���������������麯��
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
//	virtual void ����()
//	{
//		cout << "A" << endl;
//	}
//};
//class B : public A 
//{
//public:
//	virtual void ����()
//	{
//		cout << "B" << endl;
//	}
//};
//void test()
//{
//	B b;
//	A& p = b;
//	p.����();
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