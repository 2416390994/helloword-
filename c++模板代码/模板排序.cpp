#if 0
#include<iostream>
using namespace std;
template<class T>
void myswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void mysort(T array[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		int max = i;
		int j = i + 1;
		for(j; j < len; ++j)
		{
			if (array[max] < array[j])
				max = j;
		}
		if (max != i)
			myswap(array[i], array[max]);
	}
}
template<class T>
void printfs(T array[],int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << array[i]<<" ";
	}
	cout << endl;
}
void test()
{
	char a[] = "helloworld";
	int b[] = { 5, 8, 7, 4, 6, 3, 1, 9, 2, 0 };
	int num = sizeof (a) / sizeof (a[0]);
	mysort(a, num);
	printfs(a, num);
	int num1 = sizeof (b) / sizeof (b[0]);
	mysort(b, num1);
	printfs(b, num1);
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
template<class T>
void plus1(T &a,T &b)
{
	cout << a + b << endl;
}
void plus2(int a, int b)
{
	cout << a + b << endl;
}
int main()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	plus1(a, b);
	//plus(a, c);����ģ�岻�ܽ�����ʿ����ת��
	plus2(a, c);
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
template<class T>
void func(T a, T b)
{
	cout << "����ģ�����\n";
}
void func(int a, int b)
{
	cout << "��ͨ��������\n";
}

int main()
{
	int a = 10;
	int b = 20;
	func(a, b);
	//����
	//1.������ֺ������أ���ô���ȵ�����ͨ������������ͨ����ֻ������û�ж��壬����Ҳ���ȵ�����ͨ����
	//2.�����Ҫǿ�Ƶ��ú���ģ�壬��ô��Ҫ�ÿյĲ����б����磺func<>(a, b);ǿ�Ƶ��ú���ģ��
	//3.����ģ��Ҳ���Է������أ�ʾ�������棩
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class person
{
public:
	person(T1 a,T2 b)
	{
		this->name = a;
		this->ages = b;
	}
	void printfs()
	{
		cout << this->ages << endl << this->name << endl;
	}
	T1 name;
	T2 ages;
};
void test()
{
	//person p("�����"��10);����Ǵ����д����Ϊ��ģ�岻֧���Զ������ݣ�ֻ֧����ʾ������
	person<string, int>p("�����",10);
	p.printfs();
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
class person1
{
public:
	person1()
	{
		cout << "person1�ĺ�������\n";
	}
};

class person2
{
public:
	person2()
	{
		cout << "person2�ĺ�������\n";
	}
};

template<class T>
class myperson
{
public:
	T a;
	void myperson1()
	{
		T.person1;
	}
};
void test()
{
	myperson<person1>p;
	p.myperson1();
}
int main()
{
	test();
	return 0;
}
#endif
















