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
	pp->persons("今夜不让你入睡\n");
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
	person(int a)    //有参构造函数
	{
		m_age = a;
	}
	void add1(person &p)             //这里返回的是一个void类型，相当于只能进行一次加法
	{
		this->m_age += p.m_age;
	}
	person& add2(person &p)           //这里返回的是一个类类型的对象
	{
		this->m_age += p.m_age;
		return *this;                 //因为返回的是类类型的对象，所以要对this进行解引用
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
	p2.add1(p1);                      //调用add1函数只能调用一次        
	p2.add2(p1).add2(p2).add2(p2);    //调用add2类型的函数可以连续调用又称作链式编程
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








