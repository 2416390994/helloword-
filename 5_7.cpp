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
//	A = B;  //��ֵ���ݹ������������ ���Ը�ֵ�� ����Ķ��� / �����ָ�� / ��������á������и������˵������Ƭ�����иԢ����������и����ǲ���������ֵ��ȥ��
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

	A()  //�������ܱ��̳��õ��ĺ���������˽��
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
//	A b(A::init(10));  //����ͨ����������������
//	return 0;
//}















