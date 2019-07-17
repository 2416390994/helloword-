#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class person
{
public:
	person(char *a)          //传进来的是字符数组
	{
		this->m_name = new char[strlen(a) + 1];
		strcpy(this->m_name, a);
	}
	person& operator=(const person &b)          //这里为什么要返回引用呢？根据我的观察只要是返回值是*this都是传&
	{
		if (this->m_name != NULL)
		{
			delete[] this->m_name;
			this->m_name = NULL;
		}
		this->m_name = new char[strlen(b.m_name) + 1];
		//this->m_name = a.m_name;
		strcpy(this->m_name, b.m_name);
		return *this;               //this只是一个指针，根据下面两个连等说明从右往左进行中返回的值是对象，所以this解引用就是对象
	}
	~person()
	{
		if (this->m_name != NULL)
		{
			delete[] this->m_name;
			this->m_name = NULL;
		}
	}
	char *m_name;
};
void test()
{
	person p1("狗蛋");
	person p2("狗剩");
	person p3("狗毛");
	p2 = p1 = p3;//连等就需要考虑上面的返回值为引用
	cout << p2.m_name << endl;
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class person
{
public:
	person(char * p)
	{
		this->a = new char[strlen(p)+1];
		strcpy(this->a, p);
	}
	person(const person & pp)
	{
		this->a = new char[strlen(pp.a)+1];
		strcpy(this->a, pp.a);
	}
	char *a;
	~person()
	{
		if (this->a != NULL)
		{
			delete[]this->a;
			this->a = NULL;
		}
	}
};
void test()
{
	person p1("垃圾");
	person p2(p1);
	cout << p2.a<<endl;
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class person
{
public:
	person(char *a)
	{
		cout << "我是有参构造函数" << endl;
		this->m_name = new char[strlen(a) + 1];
		strcpy(this->m_name, a);
	}
	person(const person& a)
	{
		cout << "我时拷贝构造函数" << endl;
		this->m_name = new char[strlen(a.m_name) + 1];
		strcpy(this->m_name, a.m_name); //在这里我要强调一下这里必须采用这种方式进行拷贝，用this->m_name 	= a.m_name构造的话也会使两个对象指向同一块区域在调用析构函数的时候依然会崩掉
	}                                   //我想的原因是因为 this->m_name操纵的是指针（m_name本身就是指针），两个指针在这里等来等去，其实操作的也就也是指针，而strcpy则是把数据进行了填充
	~person()
	{
		if (this->m_name != NULL)
		{
			cout << "析构函数\n";
			delete[]this->m_name;
			this->m_name = NULL;
		}
	}
	char *m_name;
};
void test()
{
	person p1("吃屎");
	person p2(p1);
	cout << p2.m_name << endl;
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
class person1
{
public:
	person1()
	{
		cout << "基类的默认构造函数\n";
	}
	person1(int a)
	{
		this->a = a;
		cout << "基类的构造函数\n";
	}
	int a;
};
class person2 : public person1
{
public:
	person2(int a) 
	{
		cout << "子类的有参构造\n";
		this->a = a;
	}
	int b;
};

int main()
{
	person2 p1(10);
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class Animal
{
public:
	void speak()
	{
		cout << "动物在说话\n";
	}
};
class Cat : public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话\n";
	}
};
void dospeak(Animal & animal)
{
	animal.speak();
}
//如果发生了继承的关系，编译器允许进行类型的转换
void test()
{
	Cat cat;
	dospeak(cat);
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
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
template <class T>   //告诉编译器下面如果出现T不要报错，T是一个通用类型
void myswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
//1.自动类型推演
//2.显示指定类型
int main()
{
	int a = 10;
	int b = 20;
	double c = 3.14;
	double d = 4.23;
	myswap<int>(a, b);
	myswap<double>(c, d);
	cout << a << endl << b << endl;
	cout << c << endl << d << endl;
	return 0;
}
#endif









