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
			delete[] this->m_name;
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
	person p3("��ë");
	p2 = p1 = p3;//���Ⱦ���Ҫ��������ķ���ֵΪ����
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
	person p1("����");
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
		cout << "�����вι��캯��" << endl;
		this->m_name = new char[strlen(a) + 1];
		strcpy(this->m_name, a);
	}
	person(const person& a)
	{
		cout << "��ʱ�������캯��" << endl;
		this->m_name = new char[strlen(a.m_name) + 1];
		strcpy(this->m_name, a.m_name); //��������Ҫǿ��һ���������������ַ�ʽ���п�������this->m_name 	= a.m_name����Ļ�Ҳ��ʹ��������ָ��ͬһ�������ڵ�������������ʱ����Ȼ�����
	}                                   //�����ԭ������Ϊ this->m_name���ݵ���ָ�루m_name�������ָ�룩������ָ�������������ȥ����ʵ������Ҳ��Ҳ��ָ�룬��strcpy���ǰ����ݽ��������
	~person()
	{
		if (this->m_name != NULL)
		{
			cout << "��������\n";
			delete[]this->m_name;
			this->m_name = NULL;
		}
	}
	char *m_name;
};
void test()
{
	person p1("��ʺ");
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
		cout << "�����Ĭ�Ϲ��캯��\n";
	}
	person1(int a)
	{
		this->a = a;
		cout << "����Ĺ��캯��\n";
	}
	int a;
};
class person2 : public person1
{
public:
	person2(int a) 
	{
		cout << "������вι���\n";
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
		cout << "������˵��\n";
	}
};
class Cat : public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��\n";
	}
};
void dospeak(Animal & animal)
{
	animal.speak();
}
//��������˼̳еĹ�ϵ������������������͵�ת��
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
template <class T>   //���߱����������������T��Ҫ����T��һ��ͨ������
void myswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
//1.�Զ���������
//2.��ʾָ������
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









