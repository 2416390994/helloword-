//#if 0
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	/*person(int a, int b, int c)
//	{
//		m_a = a;
//		m_b = b;
//		m_c = c;
//	}*/
//
//
//	person(int a, int b, int c)
//		: m_a(a)
//		, m_b(b)
//		, m_c(c)
//	{
//	
//	}
//
//	int m_a;
//	int m_b;
//	int m_c;
//};
//
//void test()
//{
//	person p1(10, 20, 30);
//	cout << p1.m_a;
//	cout << p1.m_b;
//	cout << p1.m_c;
//}
//
//
//
//int main()
//{
//	test();
//	return 0;
//}
//#endif
//#if 0
//#include<iostream>
//#include<string>
//using namespace std;
//
//class phone
//{
//public:
//	phone()
//	{
//		cout << "����phone�Ĺ��캯��" << endl;
//	}
//
//	phone(string shoujihaoma)
//	{
//		m_shoujihaoma = shoujihaoma;
//	}
//
//	~phone()
//	{
//		cout << "����phone����������" << endl;
//	}
//
//	string m_shoujihaoma;
//};
//
//class game
//{
//public:
//	game()
//	{
//		cout << "����game�Ĺ��캯��" << endl;
//	}
//
//	game(string youxiname)
//	{
//		m_youxiname = youxiname;
//	}
//
//	~game()
//	{
//	
//		cout << "����game����������" << endl;
//	}
//	string m_youxiname;
//
//};
//
//class person
//{
//public:
//	person()
//	{
//		cout << "����person�Ĺ��캯��" << endl;
//	}
//	person(string name,string shouji, string youxi)
//		: m_name(name)
//		, shouji(shouji)
//		, youxi(youxi)
//	{}
//
//	void dayin()
//	{
//		cout << m_name << "����" << shouji.m_shoujihaoma << "����" << youxi.m_youxiname << endl;
//	}
//
//	~person()
//	{
//		cout << "����person����������" << endl;
//	}
//	string m_name;
//	phone shouji;
//	game youxi;
//};
//
//void test()
//{
//	person p("��ë","ŵ����","̰����");
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//#endif
//#include<iostream>
#if 0
#include"person.h"

template<class t1,class t2>
person<t1, t2>::person(t1 name, t2 age)
{
	this->a = name;
	this->b = age;
}

template<class t1, class t2 >
void person <t1, t2>::show()
{
	cout << this->a << endl << this->b << endl;
}
#endif 
/////////////////////////////////////////////////////////////////////////////
//������ķ�װ
#if 0
#include<iostream>
#include<string>
#include"person.hpp"
using namespace std;

void test()
{
	array p3(10);
	for (int i = 0; i < 9; i++)
	{
		p3.push_back(i);
	}
	//cout << p3.getdata(4);	
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
	person()
	{}

	person(int a, int b)
		:m_a(a)
		, m_b(b)
	{}

	person operator+(person& p)    //�Ӻ����������
	{
		person temp;
		temp.m_a = this->m_a + p.m_a;
		temp.m_b = this->m_b + p.m_b;
		return temp;
	}

	int m_a;
	int m_b;
};
void test()
{
	person p(10,10);
	person p1(10, 10);
	person p3 = p1 + p;
	cout << p3.m_a << endl << p3.m_b << endl;
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
	person()
	{}
	person(int a, int b)
		:m_a(a)
		, m_b(b)
	{}
	int m_a;
	int m_b;
};
person operator+(person &p, person &pp)
{
	person temp;
	temp.m_a = p.m_a + pp.m_a;
	temp.m_b = p.m_b + pp.m_b;
	return temp;
}
void test()
{
	person p(10, 10);
	person p1(10, 10);
	person p3 = p1 + p;
	cout << p3.m_a << endl << p3.m_b << endl;
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
	friend	ostream& operator<<(ostream &cout, person &a);            //��ΪҪ����˽�г�Ա����Ҫô�ṩ����Ľӿڣ�Ҫô������Ԫ����
	person()                            //Ĭ�Ϲ���
	{}
	person(int a,int b)                  //�вι���
		:m_a(a)
		, m_b(b)
		{}
private:
	int m_a;
	int m_b;
};
ostream& operator<<(ostream &cout,person &a)             //����ķ���ֵ������������ͣ�ԭ������ΪҪ����cout����ôΪʲôҪ����cout�أ�
{                                                        //�������Ϊ���������cout��ô�ں����ⲿ����Ҳû�취ʹ������cout���endl
	cout << a.m_a << a.m_b;                              //��������һ�����÷���ֵ
	return cout;
}
void test()
{
	person p(10, 10);
	cout << p << endl;                //��ִ�е�һ��<<��ʱ��ͻ��ȥ���������������������صĺ����ڲ���ͬʱcoutҲһ���ȥ
}                                     //��ִ�еڶ���<<��ʱ��ǰһ��<<�˳�������coutҲ�˳����غ�����Ȼ�����ִ��endl
int main()
{
	test();
	return 0;
}
#endif

////////////////////////////////////////////////////////////ǰ��++���ͺ���++������
#if 0
#include<iostream>
using namespace std;
class person
{
public:
	friend ostream& operator<<(ostream &cout, person& p);       
	person()                 //Ĭ�Ϲ��캯��
	{
		this->m_num = 0;
	}
	person& operator++()    //ǰ��++�����أ�ע������ķ���ֵ������
	{
		++this->m_num;
		return *this;
	}
	person operator++(int)     //����++�����أ�ע������ķ���ֵ����
	{
		person temp = *this;    //�Ȱ�ֵ��������
		this->m_num++;
		return temp;
	}
private:
	int m_num;
};
ostream& operator<<(ostream &cout,person& p)
{
	cout << p.m_num;
	return cout;
}
void test()
{
	person p;
	cout << ++p << endl;
	cout << p++ << endl;
	cout << p << endl;
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
	person (int a)
	{
		this->m_age = a;
	}

	void showage()
	{
		cout<< this->m_age;
	}
	~person()
	{
		
	}
private:
	int m_age;
};
class smartpoint                    //����ָ�룬�ڲ�ά��һ��person���͵�ָ��
{
public:
	smartpoint(person *p)//�вι��캯��
	{
		this->person = p;
	}
	person* operator->()//����->
	{
		return this->person;
	}
	person& operator*()//����*
	{
		return *(this->person);
	}
	~smartpoint()
	{
		if (this->person != NULL)
		{
			delete this->person;
			this->person = NULL;
		}
	}
private:
	person *person;
};
void test()
{
	smartpoint sp(new person(10));           //new ����һ�οռ䷵����һ��person*���͵�ֵ���÷��ص�person*���͵�ֵ�����ù��캯����ʼ��sp
	sp->showage();                           //�����Ƚ��е���->������spֻ�Ǵ������������
	(*sp).showage();
	//person *pp = new person(10);
	//person p(10);
	//cout << pp->showage();
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
	person(int aa)
	{
		this->m_age = aa;
	}
	person(person &a)
	{
		this->m_age = a.m_age;
	}

	int m_age;

};
void test()
{
	person p(10);
	person pp(p);
	cout << &pp.m_age << endl;
	cout << &p.m_age << endl;
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
#include<string.h>
using namespace std;
class person
{
public:
	person(char *a)          //�����������ַ�����
	{
		this->m_name = new char[strlen(a) + 1];
		strcpy(this->m_name, a);
	}
	person& operator=(const person &b)          //����ΪʲôҪ���������أ������ҵĹ۲�ֻҪ�Ƿ���ֵ��*this���Ǵ�&
	{
		if (this->m_name != NULL)
		{
			delete [] this->m_name;
			this->m_name = NULL;
		}
		this->m_name = new char[strlen(b.m_name) + 1];
		//this->m_name = a.m_name;
		strcpy(this->m_name, b.m_name);
		return *this;               //thisֻ��һ��ָ�룬����������������˵��������������з��ص�ֵ�Ƕ�������this�����þ��Ƕ���
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
	person p1("����");
	person p2("��ʣ");
	person p3("������");
	p2 = p1 = p3;
	cout << p2.m_name << endl;
}
int main()
{
	test();
	return 0;
}
#endif
//#if 0
//#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//
//using namespace std;
//
//struct person
//{
//	char person1[20];
//	void _person()
//	{
//		cout << person1 << endl;
//	}
//};
//
//void test()
//{
//	person p1;
//	strcpy(p1.person1, "����");
//	p1._person();
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//#endif
//#if 0
//#include<iostream>
//using namespace std;
//class point    //����һ������
//{
//public:
//	int  getx()     //��ȡ������x
//	{
//		return x;
//	}
//	int gety()     //��ȡ������y
//	{
//		return y;
//	}
//	void chuanx(int _x)    //ͨ����������˽�г�Ա����x
//	{
//		x = _x;
//	}
//	void chuany(int _y)    //ͨ����������˽�г�Ա����y
//	{
//		y = _y;
//	}
//
//private:
//	int x;
//	int y;
//};
//
//class cricle          //����һ��Բ��
//{
//public:
//	point getyuanxin()
//	{
//		return yuanxin;
//	}
//	int  getbanjing()
//	{
//		return banjing;
//	}
//	void setyuanxin(point _yuanxin )
//	{
//		yuanxin = _yuanxin;
//	}
//	void setbanjing(int _banjing)
//	{
//		banjing =_banjing;
//	}
//
//
//private:
//	point yuanxin;    //����һ��Բ��
//	int banjing;      //һ���뾶
//};
//
//void panduan(point &a, cricle &b)
//{
//	int R = (b.getyuanxin().getx() - a.getx())*(b.getyuanxin().getx() - a.getx()) + (b.getyuanxin().gety() - a.gety())*(b.getyuanxin().gety() - a.gety());
//	int R2 = (b.getbanjing()) * (b.getbanjing());
//	if (R == R2)
//	{
//		printf("����Բ��\n");
//	}
//	else if (R < R2)
//	{
//		printf("����Բ��\n");
//	}
//	else
//	{
//		printf("����Բ��\n");
//	}
//}
//void test()
//{
//	point a;
//	a.chuanx(10);
//	a.chuany(9);
//
//	cricle b;
//	point center;
//	center.chuanx(10);
//	center.chuany(0);
//	b.setbanjing(10);
//	b.setyuanxin(center);
//
//	panduan(a, b);
//	
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//#endif
//#if 0
//#include<iostream>
//using namespace std;
//
//class person
//{
//public:
//	person()
//	{
//		cout << "���ǹ��캯��" << endl;
//	}
//
//	person(int a)
//	{
//		cout << "�����вι��캯��" << endl;
//	}
//
//	person(const person& p1)
//	{
//		age = p1.age;      //������age��һ������˼�ǰ�p1��age���������Լ������age����Ϊ�����������Բ���Ҫ���������޶���
//		cout << "���ǿ������캯��" <<endl;
//	}
//
//	~person()
//	{
//		cout << "������������" << endl;
//	}
//	int age;
//
//};
//void test()
//{
//
//	person p;
//	person pp(1);
//	pp.age = 10;
//	person p2(pp);
//	cout << p2.age << endl;
//}
//
//void work(person pp)    //person pp=person(p)�������캯��
//{
//	pp.age = 100;
//	cout << pp.age;
//}
//
//void test1()
//{
//	person p;
//	p.age = 10;
//	work(p);
//}
//
//int main()
//{
//	//test();
//	
//	test1();
//	return 0;
//}
//#endif
//#if 0
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//struct node{
//	int data;
//	node* next;
//};
//
//struct node* Create_link(int* a, int n)
//{
//	int i;
//	node *p, *pre, *head;  //����һ��˵֪��һ���ڵ��λ�ã���ô���ָ��һ����ָ������ڵ��ǰһ���ڵ㣬��pre������Ҫ
//	head = new node;
//	head->next = NULL;
//	pre = head;
//	for (i = 0; i<n; i++)
//	{
//		p = new node;
//		p->data = a[i];
//		p->next = NULL;
//		pre->next = p;
//		pre = p;
//	}
//	return head;
//}
//
//void dayin(node *p)
//{
//	while (p != NULL)
//	{
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//}
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	node *p, *head;
//	head = Create_link(a, 5);
//	p = head->next;
//	/*while (p != NULL)
//	{
//		printf("%d  ", p->data);
//		p = p->next;
//	}*/
//	dayin(p); //��װ�ɺ���
//	return 0;
//}
//#endif
//#if 0
//#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<stdlib.h>
//#include<assert.h>
//using namespace std;
//
//class person
//{
//public:
//	//person(int v)        //���캯��
//	//{
//	//	m_age = v;
//	//}
//	person(char *name, int v)        //���캯��
//	{
//		m_name = (char *)malloc(strlen(name) + 1);
//		strcpy(m_name, name);
//		m_age = v;
//	}
//
//	person(const person& p)       //���,�������캯��
//	{
//		m_age = p.m_age;
//		m_name = (char*)malloc(strlen(p.m_name) + 1);
//		strcpy(m_name, p.m_name);
//	}
//	int  get()
//	{
//		return m_age;
//	}
//	char * get1()
//	{
//		return m_name;
//	}
//	
//	~person()
//	{
//		if (m_name != NULL)
//		{
//			free(m_name);
//			m_name = NULL;       //��ֹҰָ��
//		}
//	}
//
//private:
//	char *m_name;
//	int m_age;
//};
//
//void test()
//{
//	person p("�󼦰�", 10);
//	person p1 = (p);      //���ÿ������캯��
//	cout << p1.get() << p1.get1();
//
//}
//
//
//int main()
//{
//	test();
//	return 0;
//}
//
//#endif
//#if 0
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	for (int i = 1; i < 100; i++)
//	{
//		int j = 0;
//		int k = sqrt(i);
//		for (j = 2; j <= k; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j >=k+1)
//			printf("%d\n", i);
//	}
//	return 0;
//}
//#endif
//#if 0
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	for (int i = 1; i < 100; i++)
//	{
//		int j = 0;
//		int k = (int)sqrt(i);
//		for (j = 2; j <= k; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j >= k + 1)
//			printf("%d\n", i);
//	}
//	return 0;
//}
//#endif
//
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "This is C++ program.\n";
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, sum;
//	cin >> a >> b;
//	sum = a + b;
//	cout << "a+b=" << sum<<endl;
//	return 0;
//}


//<<���������
//>>��ȡ�����

//#if 0;
//#include <iostream>
//using namespace std;
//
////int max(int x, int y)
////{
////	return (x > y) ? x : y;
////}
//class student
//{
//private:
//	int num;
//	int score;
//public:
//	void setdata()
//	{
//		cin >> num;
//		cin >> score;
//	}
//	void display()
//	{
//		cout << "num=" << num << endl;
//		cout << "score=" << score << endl;
//	}
//};
//
//
//student stud1, stud2;
//
//int main()
//{
//	/*int a, b;
//	cin >> a >> b;
//	if (a > b)
//		cout << a;
//	else
//		cout << b;*/
//	/*int max(int a, int b);
//	int a, b;
//	cin >> a >> b;
//	cout << max(a, b) << endl;*/
//	stud1.setdata();
//	stud2.setdata();
//	stud1.display();
//	stud2.display();
//	return 0;


//#include <iostream>
//using namespace std;
//int main()
//{
//	char name[10];
//	int age;
//	cin >> name;
//	cin >> age;
//	cout << name << endl;
//	cout << age << endl;
//	return 0;
//}
#if 0
#include<iostream>
using namespace std;

int  app(int a = 10, int b = 20)
{
	return a + b;
}

int main()
{
	int a, b;
	int  app(int a = 10, int b = 20)
		a = app();
	cout << a << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Time
{
public:
	void set_time();
	void show_time();
private:
	int hour;
	int minute;
	int sec;
};

int main()
{
	Time time1;
	time1.set_time();
	time1.show_time();
	Time time2;
	time2.set_time();
	time2.show_time();
	return 0;
}

void Time::set_time()
{
	cin >> hour;
	cin >> minute;
	cin >> sec;
}
void Time::show_time()
{
	cout << hour << ':' << minute << ':' << sec << endl;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Lei
{
public:
	void set_value();
	void max_value();
	void show_value();
private:
	int array[10];
	int max;
};
int main()
{
	Lei MAX;
	MAX.set_value();
	MAX.max_value();
	MAX.show_value();
	return 0;
}
void Lei::set_value()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cin >> array[i];
	}
}

void  Lei::max_value()
{
	int j;
	max = array[0];
	for (j = 1; j < 10; j++)
	{
		if (max < array[j])
			max = array[j];
	}
}

void Lei::show_value()
{
	cout << "max=" << max << endl;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string pre = " ";
	string sss;
	while (cin >> sss)
	{
		if (pre == sss)
			cout << "repeated word:" << sss;//<< endl;
		pre = sss;
		cout << pre;//<< endl;
	}
	return 0;
}

#endif
//#include<iostream>
//using namespace std;
//const int a = 10;
//int b()
//{
//	const int  a = 10;
//	int* p =(int*)&a;
//	*p = 20;
//	cout << *p;
//	cout << a;
//	return 0;
//}
//int main()
//{
//	b();
//	return 0;
//}

//
//#include"��ͷ.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap(&a, &b);
//	cout << a << b << endl;
//	swap2(a, b);
//	cout << a << b << endl;
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int *  const c = &a;
//	*c = 20;
//	printf("%d", a);
//	return 0;
//}


//#include<iostream>
//using namespace std;
#if 0
const double pi = 3.14;
class circle
{
public:
	double getC()
	{
		return 2 * R*pi;
	}
	int R;
};
void test()
{
	circle c1;
	c1.R = 10;
	cout << c1.getC();
}
#endif
//#include <string>
#if 0
class student
{
public:
	int  name;
	string age;
	void _name(int _name)
	{
		name = _name;
	}
	void _age(string _age)
	{
		age = _age;
	}
};

void test()
{
	student zhangsan;
	zhangsan._name(10);
	zhangsan._age("����");
	cout << zhangsan.age << '\n' << zhangsan.name << endl;
}
#endif
#if 0
#define and(a,b) (a+b)
void test()
{
	int ret = and(10, 20);
}
int main()
{
	test();
	return 0;

}
#endif


//#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//
//using namespace std;
//
//struct person 
//{
//	char person1[20];
//	void _person()
//	{
//		cout << person1 << endl;
//	}
//};
//
//void test()
//{
//	person p1;
//	strcpy(p1.person1, "����");
//	p1._person();
//}
//
//int main()
//{
//	test();
//	return 0;
//}
#if 0
#include <iostream>
using namespace std;
typedef struct Listnode
{
	int v;
	struct Listnode* next;
}node;

node *yitihua(int *a, int x)
{
	node *n, *h;
	h = (node *)malloc(sizeof (node));
	h->next = NULL;
	for (int i = x - 1; i >= 0; i--)
	{
		n = (node *)malloc(sizeof (node));
		n->v = a[i];
		n->next = h->next;
		h->next = n;
	}
	return h;
}


int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	node *p, *h;
	p = yitihua(a, 5);
	h = p->next;
	while (h != NULL)
	{
		printf("%d", h->v);
		h = h->next;
	}
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class person
{
public:
	person(char *name, int v)        //���캯��
	{
		m_name = (char *)malloc(strlen(name) + 1);
		strcpy(m_name, name);
		m_age = v;
	}
private:
	char *m_name;
	int m_age;
};

void test()
{
	person p = ("hjsgd", 10);
}


int main()
{
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
class printer
{


private:
	printer()
	{
	}
	printer(const printer &a)
	{
	}
public:
	static printer * get()
	{
		return signleman;
	}
	void printfe(const string &b)
	{
		cout << b << endl;;
		count++;
		cout << count << endl;        //��ӡ��ӡ����
	}
private:
	static printer * signleman;
	int count = 0;
};
printer * printer::signleman = new printer;
void test()
{
	printer *p = printer::get();
	p->printfe("nihao");       //ͨ��ָ����д���
	p->printfe("nihao");
	p->printfe("nihao");
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
	friend void f(person &p);
	person()    //�вι��캯��
	{
		m_age = 100;
		a = 10;
	}
	int a;
private:
	int m_age;
};
void f(person &p)
{
	cout << p.a;
	cout << p.m_age;
}

void test()
{
	person p;
	f(p);

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
class building
{
	friend class person;
public:
	building()
	{
		this->m_kitchen = "aa";
		this->m_room = "bb";
	}
	string m_kitchen;
private:
	string m_room;
};
class person
{
	//	friend class building;
public:
	person()
	{
		laji = new building;
	}
	void visoon()
	{
		cout << this->laji->m_kitchen;
		cout << this->laji->m_room;
	}

private:
	building * laji;
};


void test()
{
	person gg;
	gg.visoon();
}


int main()
{

	return 0;
}
#endif
#if 0
#include<stdio.h>
void push(int *a, int length)
{
	int j = 1;
	for (j; j < length; j++)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > a[i + 1])
		{
			a[i + 1] = a[i];
			a[i] = key;
			i--;
		}
	}
}
void printf_s(int *a)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

}

int main()
{
	int array[10] = { 2, 4, 5, 8, 9, 7, 6, 3, 1, 0 };
	push(array, 10);
	printf_s(array);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void  MergeDate(int *array, int left, int right, int *temp)
{
	int mid = left + ((right - left) >> 1);
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;
	while (begin1< end1&&begin2 < end2)
	{
		if (array[begin1]< array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	while (begin1<end1)
		temp[index++] = array[begin1++];
	while (begin2<end2)
		temp[index++] = array[begin2++];
}


void  _MergeSort(int *array, int left, int right, int *temp)
{
	//int*temp = malloc(sizeof(array[left])*(right - left));
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		MergeDate(array, left, mid, temp);
		memcpy(array + left, temp + left, sizeof(array[left])*(right - left));
	}
}

void MergeSort(int *array, int size)
{
	int *temp = (int *)malloc(sizeof(array[0])*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	_MergeSort(array, 0, size, temp);
	free(temp);
}
void printf_s(int *a)
{
	for (int i = 0; i < 9; i++)
	{
		printf("%d\n", a[i]);

	}
}
int main()
{
	int a[] = { 2, 5, 4, 8, 22, 2, 65, 4, 13 };

	MergeSort(a, 9);
	printf_s(a);
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
#include"6-7.cpp"
using namespace std;



int main()
{
	person<int, string> p(10, "�Ҵ����");
	p.show();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
#include"person.hpp"
using namespace std;
//template<class t1,class t2>
int main()
{
	person<string, int>p("��ͼ�", 10);
	return 0;
}
#endif
#if 0
#pragma once
#include<string>
using namespace std;
template<class t1, class t2>
class person
{
public:
	person(t1 name, t2 age)
	{

	}
	void show()
	{

	}
	t1 a;
	t2 b;

};
#endif

#if 0
#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class t1, class t2>
class person
{
public:
	person(t1 name, t2 age);
	void show();
	t1 m_name;
	t2 m_age;
};
template<class t1, class t2>
person<t1, t2>::person(t1 name, t2 age)
{
	this->m_name = name;
	this->m_age = age;
}
template<class t1, class t2>
void person<t1, t2>::show()
{
	cout << this->m_age << endl;
	cout << this->m_name << endl;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
class array
{
public:
	array();//Ĭ�Ϲ��캯��,Ĭ���������Ǹ���100
	array(int capacity);//�вι���
	array(const array& a);//�������캯��
	~array();//��������
	void push_back(int a);//β��
	int  getdata(int a);//�����±��ѯ����ĳ��λ�õ�����
	void setdata(int a, int b);//������������ֵ
private:
	int m_size;
	int m_capacity;
	int *m_array;
};

array::array()
{
	cout << "����Ĭ�Ϲ��캯��" << endl;
	this->m_capacity = 100;//����һ��Ĭ�Ͽռ��С
	m_array = new int(this->m_capacity);//����ռ�
	this->m_size = 0;//��ʼ������
}
array::array(int capacity)
{
	cout << "�����вι��캯��" << endl;
	this->m_capacity = capacity;
	this->m_array = new int(this->m_capacity);
	this->m_size = 0;
}
array::array(const array& a)
{
	cout << "���ǿ������캯��" << endl;
	this->m_capacity = a.m_capacity;       //�������ǰ������Ĵ��ݷ�����ǰ��
	this->m_array = new int(this->m_capacity);  //����������֮�������ô��ݵ��������п��ٿռ䣬�м���һ��ܹؼ�
	this->m_size = a.m_size;
	for (int i = 0; i < a.m_size; i++)
	{
		this->m_array[i] = a.m_array[i];
	}
}
array::~array()
{
	cout << "������������" << endl;
	if (this->m_array != NULL)
	{
		delete[] this->m_array;
		this->m_array = NULL;
	}
}
void array::push_back(int a)
{
	//�������ǲ��������ݣ�Ĭ����������
	this->m_array[this->m_size] = a;
	this->m_size++;
}
int  array::getdata(int a)
{
	return this->m_array[a];
}
void array::setdata(int a, int b)
{
	this->m_array[a] = b;
}
#endif
#if 0

#include<iostream>
#include<string>
using namespace std;

class phone
{
public:
	phone()
	{
		cout << "����phone�Ĺ��캯��" << endl;
	}

	phone(string shoujihaoma)
	{
		m_shoujihaoma = shoujihaoma;
	}

	~phone()
	{
		cout << "����phone����������" << endl;
	}

	string m_shoujihaoma;
};

class game
{
public:
	game()
	{
		cout << "����game�Ĺ��캯��" << endl;
	}

	game(string youxiname)
	{
		m_youxiname = youxiname;
	}

	~game()
	{

		cout << "����game����������" << endl;
	}
	string m_youxiname;

};

class person
{
public:
	person()
	{
		cout << "����person�Ĺ��캯��" << endl;
	}
	person(string  name, string m_shoujihaoma, string youxiname)
		: m_name(name)
		, shouji(m_shoujihaoma)
		, youxi(youxiname)
	{}

	void dayin()
	{
		cout << m_name << "����" << shouji.m_shoujihaoma << "����" << youxi.m_youxiname << endl;
	}

	~person()
	{
		cout << "����person����������" << endl;
	}
	string m_name;
	phone shouji;
	game youxi;
};

void test()
{
	person p("laji", "ŵ����", "̰����");
	p.dayin();
}

int main()
{
	test();
	return 0;
}
# endif
#if 0
#include<iostream>
using namespace std;
class person
{
public:
	person()             //Ĭ�Ϲ��캯��
	{
		cout << "����Ĭ�Ϲ��캯��" << endl;
	}
	person(int A)
	{

	}

	person(const person &a)  //�������캯��
	{

	}
	~person()
	{
		cout << "������������" << endl;
	}


};

void test()
{
	//person p;
	person *p1 = new person;
	/*person p1;
	person p2 = p1;
	person p3 = 10;*/
	delete p1;

}

int main()
{
	person* pp = new person[10];
	int a[2] = { int(1), int(2) };
	printf("%d", a[1]);
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
	person()
	{
		cout << "����Ĭ�Ϲ��캯��" << endl;
	}
};

//int person::count = 0;
void test()
{
	person p;
	person *pp = new person;
	/*person p1;
	person p2;
	person p3;
	person p4;
	person p5;
	cout << person::count << endl;*/
}


int main()
{
	test();
	return 0;
}
# endif
#if 0
#include<iostream>
using namespace std;
class chairmain
{

private:
	chairmain()
	{
		cout << "����";
	}
	chairmain(const chairmain&c)
	{

	}
public:

	static chairmain * get()
	{
		return singleman;
	}

private:
	static chairmain * singleman;
};
chairmain  *chairmain::singleman = new chairmain;
void test()
{
	chairmain  *ppp = chairmain::get();
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
class printf
{
public:
	static printf * get()
	{
		return signleman;
	}

private:
	printf()
	{

	}
	printf(const printf &A)
	{

	}
private:
	static printf * signleman;

};

printf * printf::signleman = new printf;

void test()
{
	printf *p = printf::get();
}

int mian()
{

	return 0;
}
#endif
#if 0
#include<stdio.h>
swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bopsort(int *a)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8 - j; i++)
		{
			if (a[i] > a[i + 1])
				swap(&a[i], &a[i + 1]);
		}
	}

}
int main()
{
	int a[9] = { 5, 4, 6, 9, 8, 7, 1, 2, 3 };
	bopsort(a);
	for (int i = 0; i < 9; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}
#endif 
//#include<stdio.h>
//int main()
//{
//	//int a = 1;
//	//char *b = &a;
//	//*(b + 0) = 10;
//	//*(b + 1) = 0;
//	//*(b + 2) = 0;
//	//*(b + 3) = 0;
//	//int a = 2200000000;
//	printf("%d", a);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int i, j, k;
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 2 - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 4 - 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif 
#if 0
#include <stdio.h>
#include <math.h>
int main()
{
	int i;
	int j;
	for (i = 1; i <= 1000; i++)
	{
		int k = sqrt(i);
		for (j = 2; j <= k; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j >= k + 1)
			printf("%d\n", i);
	}
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int j;
	int k;
	int array[1000];
	for (i = 1; i <= 1000; i++)
		array[i] = i;
	for (i = 1; i <= 1000; i++)
	{
		k = sqrt(i);
		for (j = 2; j <= k; j++)
		{
			if (array[i] % j == 0)
			{
				array[i] = 0;
				break;
			}
		}
	}
	for (i = 1; i <= 1000; i++)
	{
		if (array[i] != 0)
			printf("%d\n", array[i]);
	}
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int j;
	int array[1001];
	for (i = 1; i <= 1000; i++)
		array[i] = i;
	for (j = 2; j <= sqrt(1000); j++)
	{
		for (i = j + 1; i <= 1000; i++)
		{
			if (array[i] != 0 && array[j] != 0)
			if (array[i] % array[j] == 0)
				array[i] = 0;
		}
	}
	for (i = 1; i <= 1000; i++)
	{
		if (array[i] != 0)
			printf("%d\n", array[i]);
	}
	return 0;
}
#endif
#if 0
//��������mix��ַ��ʧ��Ӧ���ڽ���֮ǰ��mix�ĵ�ַ��������
#include<stdio.h>
int main()
{
	int i;
	int mix;
	int count = 0;
	void swap(int *x, int *y);
	int a[10] = { 5, 4, 6, 0, 8, 2, 1, 3, 9, 7 };
	for (i = 0; i < 10; ++i)
	{
		int *p1 = &a[i];
		int *p2 = p1 + 1;
		mix = i;
		while (count++ < 8)
		{
			if (a[mix] > *p2)
				a[mix] = *p2;
			p2++;
		}
		swap(&a[i], &a[mix]);
	}
	for (i = 0; i < 10; i++)
		printf("%d", a[i]);
	return 0;
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
#endif

#if 0
#include<stdio.h>
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int i;
	int j;
	int mix;
	int a[10] = { 2, 4, 5, 6, 8, 7, 1, 9, 3, 0 };
	for (i = 0; i < 10; i++)
	{
		mix = i;
		for (j = i + 1; j < 10; j++)
		{
			if (a[mix]>a[j])
				mix = j;
		}
		swap(&a[i], &a[mix]);
	}
	for (i = 0; i < 10; i++)
		printf("%d", a[i]);
	return 0;
}
#endif

#if 0
#include<stdio.h>
int main()
{
	int i;
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int add1 = 0;
	int add2 = 0;
	int j = 2;
	for (i = 0; i < 3; i++)
	{
		add1 += a[i][i];
	}
	for (i = 0; i < 3; i++)
	{
		add2 += a[i][j--];
	}
	printf("%d%d", add1, add2);

	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	int i;
	int pop = 6;
	int a[10] = { 0, 1, 2, 3, 4, 5, 7, 8, 9 };
	for (i = 0; i < 10; i++)
	{
		if (a[i]>pop)
		{
			for (int j = 9; j >= i; --j)
			{
				a[j + 1] = a[j];
			}
			a[i] = pop;
			i = 10;
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d", a[i]);
	return;
}
#endif

#if 0
#include<stdio.h>
int main()
{
	int i;
	int b[10];
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *p = &a[sizeof (a) / sizeof(0) - 1];      //����һ��ָ�룬��ָ��ָ�������������һ��λ��
	for (i = 0; i < 10; i++)
		b[i] = *p--;                              //�������������������ֵ������b
	for (i = 0; i < 10; i++)
		printf("%d", b[i]);                       //�ٴ�ӡ������b
	return 0;
}
//��д��һ�δ���Ȼ������ȥ����δ������Ż��������Ķ�������ַ���
#endif
#if 0
//�ص�����
#include<stdio.h>
#include<stdlib.h>
void b(int *array, int size, int suijizhi(void))
{
	for (int i = 0; i< size; i++)
		array[i] = suijizhi();
}
int suijizhi(void)
{
	return rand();
}
int main(void)
{

	int a[10];
	b(a, 10, suijizhi);
	for (int i = 0; i < 10; i++)
		printf("%d\n", a[i]);
	return 0;
}
#endif

#if 0
#include<stdio.h>
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int i;
	int a[7] = { 0, 1, 2, 3, 4, 5, 6 };
	int b = (sizeof (a) / sizeof (0)) / 2;
	for (i = 1; i <= b; i++)
	{
		swap(&a[b + i], &a[b - i]);
	}
	for (i = 0; i < 7; i++)
		printf("%d", a[i]);
	return 0;
}
#endif
#if 0
#include<stdio.h>
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int i;
	int a[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int left = 0;
	int right = 7;
	while (a[left + 1] != a[right])
	{
		swap(&a[left], &a[right]);
		left++;
		right--;
	}
	for (i = 0; i < 8; i++)
		printf("%d", a[i]);
	return 0;
}
#endif

#if 0
#include<stdio.h>
#define   N   10
int main()
{
	int i, j;
	int a[N][N];
	for (int i = 0; i < 10; i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (i = 2; i < N; i++)
	for (j = 1; j < N; j++)
	{
		if (i == j)
			break;
		else
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	}
	for (i = 0; i < N; i++)
	for (j = 0; j < N; j++)
	{
		printf("%d", a[i][j]);
		if (i == j)
		{
			printf("\n");
			break;
		}
	}
	return 0;
}
#endif

#if 0
#include<stdio.h>
#define   N   10
int main()
{
	int i, j;
	int a[N][N];
	for (int i = 0; i < 10; i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (i = 2; i < N; i++)
	for (j = 1; j < i; j++)
	{
		a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%-6d", a[i][j]);
		printf("\n");

	}
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	int i, j, b, flat = 0;
	int max, mix;
	int a[3][4] = { 12, 45, 8, 7, 6, 60, 35, 54, 98, 70, 24, 16 };
	for (i = 0; i < 3; i++)
	{
		max = a[i][0];
		for (j = 0; j < 4; j++)
		{
			if (a[i][j + 1]>a[i][j])
			{
				max = a[i][j + 1];
				b = j + 1;
			}
		}
		for (i = 0; i < 3; i++)
		{
			if (a[i][b] > a[i + 1][b])
			{
				mix = a[i + 1][b];
			}
		}
		if (max == mix)
		{
			flat = 1;
			break;
		}
	}
	if (flat == 1)
	{
		printf("%d", max);
	}
	else
	{
		printf("NO");
	}
	return 0;
}
#endif
#if 0
//���ַ�����һ������
#include<stdio.h>
int main()
{
	int mid;
	int find;
	scanf_s("%d", &find);
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int left = 0;
	int right = sizeof(a) / sizeof(0) - 1;
	while (left < right)
	{
		mid = (right + left) / 2;
		if (find>a[mid])
		{
			left = mid + 1;
		}
		if (find < a[mid])
		{
			right = mid;
		}
		if (find == a[mid])
		{
			break;
		}
	}
	if (left != right)
	{
		printf("%d", mid);
	}
	else
	{
		printf("NO");
	}
	return 0;
}
#endif

//#include <stdio.h>
//void swap(int x, int y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//int main()
//{
//int a = 10;
//int *b = &a;
//const int e ;
//int *c = NULL;
//c = &a;
//printf("%d", *c);
//int *p = 0;//   ������ʵ�ǽ�0��Ϊһ��NULL������ģ�����������Ĵ�ӡ�������ӡ��ֵ
//printf("%d", *p);
/*int **c = &b;
int *hoge;*/
//printf("%d", e);
/* printf("%p\n", &a);
printf("%p\n", b);
printf("%d\n", *b);
printf("%d\n", *b);
printf("%d\n", *b);
printf("%p\n", c);
printf("%p\n", *c);*/
/*int a = 5;
int b = 3;
swap(a, b);
*/
//int a = 0x12345678;
/*printf("%x\n", *(char*)&a  2);
printf("%x\n", *(char*)&a  3);*/
/*printf("%x", a);
return 0;
}*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int daxie, xiaoxie, shuzi, kongge, qita;
	daxie = xiaoxie = shuzi = kongge = qita = 0;
	char laji[3][80];
	for (int i = 0; i < 3; i++)
	{
		printf("�������%d���ַ���", i + 1);
		gets(laji[i]);
		for (int j = 0; j < 80 && laji[i][j] != '\0'; j++)
		{
			if (laji[i][j] >= 'a'&&laji[i][j] <= 'z')
				xiaoxie++;
			else if (laji[i][j] >= 'A'&&laji[i][j] <= 'Z')
				daxie++;
			else if (laji[i][j] >= '0'&&laji[i][j] <= '9')
				shuzi++;
			else if (laji[i][j] == ' ')
				kongge++;
			else
				qita++;
		}
	}
	printf("%d\n%d\n%d\n%d\n%d", daxie, xiaoxie, shuzi, kongge, qita);

	return 0;
}
#endif 
#if 0
#include<stdio.h>
int main()
{
	char c;
	int daxie, xiaoxie, shuzi, kongge, qita;
	daxie = xiaoxie = shuzi = kongge = qita = 0;
	while ((c = getchar()) != '\n')
	{
		if (c >= 'a'&&c <= 'z')
			xiaoxie++;
		else if (c >= 'A'&&c <= 'Z')
			daxie++;
		else if (c >= '0'&&c <= '9')
			shuzi++;
		else if (c == ' ')
			kongge++;
		else
			qita++;

	}
	printf("%d\n%d\n%d\n%d\n%d", daxie, xiaoxie, shuzi, kongge, qita);
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	int i, j, k;
	int a, b;
	printf("��������Ҫ��ӡ�ļ��м��У�");
	scanf_s("%d %d", &a, &b);
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < a; j++)
		{

			printf("*");
		}
		printf("\n");
		for (k = 0; k <= i; k++)
			printf(" ");
	}
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	int i, j;
	int a[10][10];
	for (i = 0; i < 10; i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (i = 2; i < 10; i++)
	{
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%-6d", a[i][j]);
			if (i == j)
			{
				printf("\n");
				break;
			}
		}
	}


	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	int n = 0;
	char a[80], b[80];
	printf("���������룺");
	gets(a);
	while (a[i] != '\0')
	{
		if (a[i] >= 'A'&&a[i] <= 'Z')
			b[i] = 'A' + 'Z' - a[i];
		else if (a[i] >= 'a'&&a[i] <= 'z')
			b[i] = 'a' + 'z' - a[i];
		else
			b[i] = a[i];
		i++;
	}
	n = i;
	for (i = 0; i < n; i++)
	{
		putchar(b[i]);
	}

	return 0;
}
#endif 
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	int m;

	char a[6] = "abcdef";
	//char a[10];
	//gets(a);
	scanf_s("%d", &m);
	void fanzhuan(char *s, int size, int m);
	fanzhuan(a, strlen(a), m);
	printf("%s", a);

	return 0;
}
void fanzhuan(char *s, int size, int m)
{
	while (m--)
	{
		char t = s[0];
		for (int i = 1; i < size; i++)
		{
			s[i - 1] = s[i];
		}
		s[size - 1] = t;
	}
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10] = "abcdef";
	//gets(a);
	int m;
	scanf("%d", &m);
	void fanzhuan(char *s, int chushi, int m);
	fanzhuan(a, 0, m);
	fanzhuan(a, m, strlen(a));
	fanzhuan(a, 0, strlen(a));
	printf("%s", a);
	return 0;
}
void fanzhuan(char *s, int chushi, int m)
{
	for (int i = chushi; i < m; i++)
	{
		char t = s[i];
		s[i] = s[m - 1];
		s[m - 1] = t;
		m--;
	}

}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int m;
	printf("�����������뷴ת��������");
	char a[16] = "I am a student.";
	scanf("%d", &m);
	int count(char *s, int size, int geshu);
	void fanzhuan2(char *s, int chushi, int shuzi);
	int c = count(a, strlen(a), m);
	fanzhuan2(a, 0, c);
	fanzhuan2(a, c, strlen(a));
	fanzhuan2(a, 0, strlen(a));
	printf("%s", a);
	return 0;
}
int count(char *s, int size, int geshu)
{
	int i;
	int j;
	int count = 0;
	for (i = 0; i < size; i++)
	{
		if (s[i] == ' ')
		{
			count++;
			char t = s[i];
			for (j = 0; j < i; j++)
			{
				char t = s[j];
				s[j] = s[j - 1];
				s[i - 1] = t;
			}
		}
		if (count == geshu)
			break;
	}
	if (i != size - 1)
		return i;
	else
		return size - 1;
}

void fanzhuan2(char *s, int chushi, int m)
{
	for (int i = chushi; i < m; i++)
	{
		char t = s[i];
		s[i] = s[m - 1];
		s[m - 1] = t;
		m--;
	}
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
int main()
{
	void func(char a[], int k);
	char a[26] = "abcdef";
	func(a, 0);

	return 0;
}

void func(char a[], int k){
	int i, temp;
	if (k == strlen(a)){
		printf("%s ", a);
	}
	for (i = k; i < strlen(a); i++){
		temp = a[k];
		a[k] = a[i];
		a[i] = temp;

		func(a, k + 1);

		temp = a[k];
		a[k] = a[i];
		a[i] = temp;
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10] = "abcdef";
	char b[10] = "bcd";
	int  panduan(char *a, char *b, int   sizea, int   sizeb);
	int c = panduan(a, b, strlen(a), strlen(b));
	printf("%d", c);
	return 0;
}

int  panduan(char *a, char *b, int  sizea, int  sizeb)
{
	for (int i = 0; i < sizeb; i++)
	{
		int j;
		for (j = 0; j < sizea; i++)
		{
			if (a[j] != b[i])
				;
			else
				break;
		}
		if (j >= sizea)
			return 0;
	}
	return 1;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>
int main()
{
	char *a = "bbbcccccccef";
	char *b = "bcd";
	int  panduan(char *a, char *b, int   sizea, int   sizeb);
	panduan(a, b, strlen(a), strlen(b));
	return 0;
}

int  panduan(char *a, char *b, int  sizea, int  sizeb)
{
	int count = 0;
	for (int i = 0; i < sizeb; i++)
	{
		int j;
		for (j = 0; j < sizea; j++)
		{
			if (a[j] == b[i])
				count++;
		}
	}
	if (count >= sizeb)
		printf("laji");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>
int main()
{
	char *a = "abcdef";
	char *c = "bcd";
	int  panduan(char *a, char *c, int sizea, int sizec);
	int b = panduan(a, c, strlen(a), strlen(c));
	printf("%d", b);
	return 0;
}
int  panduan(char *a, char *c, int sizea, int sizec)
{
	int i = 0;
	int j = 0;
	for (i; i < sizea;)
	{
		while (i < sizea&&a[i] < c[j])
			++i;
		if (i >= sizea || a[i] > c[j])
			return 0;
		++j;
	}
	return 1;

}
#endif

#if 0
#include<stdio.h>
#include<string.h>
int panduan(char *a, char *b, int sizea, int sizeb)
{
	int great1 = 0;
	int great2 = 0;
	for (int i = 0; i < sizea; i++)
	{
		great1 = great1 | (1 << (a[i] - 'A'));
	}

	/*for (int i = 0; i < sizeb; i++)
	{
	if ((great1&(1 << (b[i] - 'A'))) == 0)
	return 0;
	else
	return 1
	}*/

	for (int j = 0; j < sizeb; j++)
	{
		great2 = great2 | (1 << (b[j] - 'A'));
	}
	if ((great1&great2) == great2)
		return 1;
	else
		return 0;
}

int main()
{
	char *a = "abcdef";
	char *b = "bcdw";
	int panduan(char *a, char *b, int sizea, int sizeb);
	int c = panduan(a, b, strlen(a), strlen(b));
	printf("%d", c);
	return 0;
}

#endif
#if 0
#include<stdio.h>
int main()
{
	int c;
	int count = 1;
	scanf_s("%d", &c);
	//(c >> 1) & 1) != 1
	while ((c & 1) != 1)
	{
		count = count * 2;
		c = c >> 1;
	}
	printf("%d", count);
	return 0;
}
#endif

#if 0
#include<stdio.h>
int main()
{
	int c;
	scanf_s("%d", &c);
	int a = ((c - 1)&c) ^ c;
	//int a=c&(-c);
	printf("%d", a);
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a[20];// = "-12345678910";
	gets(a);
	int _chuan(const char *s);
	int c = _chuan(a);
	printf("%d", c);
	return 0;
}

int _chuan(const char *s)
{
	static const int max = (int)((unsigned)~0 >> 1);
	static const int mix = -(int)((unsigned)~0 >> 1) - 1;
	int n = 0;
	int sign = 1;
	if (*s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '\0')
	{
		int d = *s - '0';
		if (sign > 0 && (n > max / 10 || (n == max / 10 && d > max % 10)))
		{
			n = max;
			break;
		}
		else if (sign < 0 && (n >(unsigned)mix / 10 || (n == (unsigned)mix / 10 && d > (unsigned)mix % 10)))
		{
			n = mix;
			break;
		}
		n = n * 10 + d;
		s++;
	}
	return sign > 0 ? n : -n;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; i <= 9; j++)
		{
			printf("%d*%d=%d   ", i, j, i*j);
			if (i == j)
			{
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
#endif

#if 0
#include<stdio.h>
int main()
{
	char c;
	while (c = getchar())
	{
		if (c == 'a')
			printf("laji\t");
		if (c == 'b')
			printf("dalaji");
	}
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	int c;
	char buf[1024];
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d", &c);
	for (;;)
	{
		printf("%d\n", c);
		getchar();
		c++;
	}
	return 0;
}
#endif
//#include <stdio.h>
//
//int main()
//{
//	char sentence[] = "Rudolph is 12 years old";
//	char str[20];
//	int i;
//
//	sscanf(sentence, "%s%*s%d", str, &i);
//	printf("%s -> %d\n", str, i);
//
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//void fun(void)
//{
//
//}
//
//int main()
//{
//		
//	void fun(void);
//
//
//	printf("%p\n", fun);
//	printf("%p", &fun);
//	return 0;
//}
#if 0
#include<stdio.h>

int main()
{
	int a[10];
	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}
#endif
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct listnode
//{
//	int value;
//	struct listnode *next;
//}node;
//
//typedef struct slist
//{
//	node *first;
//}slist;
//
//void slistinit(slist *s)
//{
//	assert(s != NULL);
//	s->first->next = NULL;
//}
//
//void test()
//{
//	slist list;
//	slistinit(&list);
//	
//}
//
//int main()
//{
//
//
//}
#if 0
#include<stdlib.h>
#include<assert.h>

typedef struct ListNode
{
	int  value;
	struct ListNode *next;
} Node;


typedef struct SList
{
	Node*first;      //������Node*head����ʾ
}SList;

//��ʼ��
void SListInit(SList *s)
{
	assert(s != NULL);
	s->first = NULL;
}


void Test()
{
	SList list;   //һ�������ڱ����������ʱ���Ӧ����ͷ�ڵ�
	SListInit(&list);
}



//���룬ͷ��
void  SListPushFront(SList *s, int v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}

#if 0
typedef struct listnode
{
	int value;
	struct listnode *next;
}node;

typedef struct llist
{
	node *first;
}llist;

void chushihua(llist *s)
{
	assert(s != NULL);
	s->first = NULL;
}

void  listinte(llist *s, int v)
{
	node * n = (node*)malloc(sizeof (node));
	n->value = v;
	n->next = s->first;
	s->first = n;
}

void Test()
{
	llist s;
	chushihua(&s);
}
#endif
int main()
{
	SList s;
	SListInit(&s);

	SListPushFront(&s, 10);
	SListPushFront(&s, 20);
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//���������� 
typedef struct Node
{
	ElemType data;              //�������е������� 
	struct Node *next;          //�������ָ���� 
}Node, *LinkedList;

//������ĳ�ʼ��

LinkedList LinkedListInit()
{
	Node *L;
	L = (Node *)malloc(sizeof(Node));   //������ռ� 
	if (L == NULL)                       //�ж��Ƿ����㹻���ڴ�ռ� 
		printf("�����ڴ�ռ�ʧ��\n");
	L->next = NULL;  //��next����ΪNULL,��ʼ����Ϊ0�ĵ����� 
	return L;
}

//������Ľ���1��ͷ�巨����������

LinkedList LinkedListCreatH()
{
	Node *L;
	L = (Node *)malloc(sizeof(Node));   //����ͷ���ռ�
	L->next = NULL;                      //��ʼ��һ��������

	ElemType x;                         //xΪ�����������е�����
	while (scanf("%d", &x) != EOF)
	{
		Node *p;
		p = (Node *)malloc(sizeof(Node));   //�����µĽ�� 
		p->data = x;                     //���������ֵ 
		p->next = L->next;                    //�������뵽��ͷL-->|2|-->|1|-->NULL 
		L->next = p;
	}
	return L;
}
int main()
{

	LinkedListCreatH();
	return;
}
#endif
