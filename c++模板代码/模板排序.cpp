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
	//plus(a, c);函数模板不能进行隐士类型转换
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
	cout << "函数模板调用\n";
}
void func(int a, int b)
{
	cout << "普通函数调用\n";
}

int main()
{
	int a = 10;
	int b = 20;
	func(a, b);
	//结论
	//1.如果出现函数重载，那么优先调用普通函数，就算普通函数只有声明没有定义，报错也优先调用普通函数
	//2.如果想要强制调用函数模板，那么就要用空的参数列表。例如：func<>(a, b);强制调用函数模板
	//3.函数模板也可以发生重载（示例在下面）
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
	//person p("孙悟空"，10);这个是错误的写法因为类模板不支持自动的推演，只支持显示化调用
	person<string, int>p("孙悟空",10);
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
		cout << "person1的函数调用\n";
	}
};

class person2
{
public:
	person2()
	{
		cout << "person2的函数调用\n";
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
















