#if 0
#include<iostream>
using namespace std;
class person
{
public:
	person()
	{

	}
	person(int a)
	{
		this->a = a;
	}
	static void aaa()
	{
		cout << b;
	}
private:
	static int a;
	int b;
};
int person::a = 10;
void test()
{
	person p1(20);
	person p2;
	p1.a--;
	printf("%d", p2.a);
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
class person
{
public:
	static person *get()
	{
		return a;
	}
	void persons(const string &b)
	{
		cout << b;
		count++;
		cout << count << endl;

	}
private:
	person()
	{
	}
	static person * a;
	int count=1;
};
person *person::a = new person;
void test()
{
	person*pp = person::get();
	pp->persons("��ҹ��������˯\n");
	/*person *p = new person;
	person p1;*/

}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class person
{
public:
	person(int a)    //�вι��캯��
	{
		m_age = a;
	}
	void add1(person &p)             //���ﷵ�ص���һ��void���ͣ��൱��ֻ�ܽ���һ�μӷ�
	{
		this->m_age += p.m_age;
	}
	person& add2(person &p)           //���ﷵ�ص���һ�������͵Ķ���
	{
		this->m_age += p.m_age;
		return *this;                 //��Ϊ���ص��������͵Ķ�������Ҫ��this���н�����
	}
	void func()
	{
		cout << this->m_age << endl;
	}


private:
	int m_age;
};
void test()
{
	person p1(10);
	person p2(10);
	p2.add1(p1);                      //����add1����ֻ�ܵ���һ��        
	p2.add2(p1).add2(p2).add2(p2);    //����add2���͵ĺ����������������ֳ�����ʽ���
	p2.func();

}
int main()
{
	test();
	return 0;
}
#endif
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person()
//	{}
//	void read()
//	{
//	}
//
//};
//
//int main()
//{
//	const person p1;
//	//p1.read();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	((a++)++);
//	(++(++a));
//	return 0;
//}








