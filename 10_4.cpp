//#pragma pack(1)
#include<iostream>
#include<time.h>
using namespace std;
class A2 {
public:
	void f2() {}
};
void sort_1(int *a,int length)    //冒泡排序
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (a[j]>a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
void sort_2(int *a, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int max = i;
		for (int j = i; j < length; ++j)
		{
			if (a[max] < a[j])
				max = j;
		}
		swap(a[max], a[i]);
	}
}
//struct Date
//{
//	char month;  //
//	char day;  //4
//	int year;  //4
//};
//struct Student
//{
//	char num;   //1
//	char name[20];   //3+17
//	char sex;   //1+2
//	int age;    //4
//	struct Data mmc;   //6
//	//char addr[30];   //32
//};
void sort_3(int *a, int length)
{
	for (int i = 1; i < length; ++i)
	{
		for (int j = i; j>0 && a[j] > a[j - 1]; --j)
		{
			swap(a[j], a[j - 1]);
		}
	}
}
void sort_4(int *a, int length)
{
	int ges = length;
	while (ges > 1)
	{
		ges = ges / 3 + 1;
		for (int i = ges; i < length; i += ges)
		{
			for (int j = i; j>0 && a[j] > a[j - ges]; j -= ges)
			{
				swap(a[j], a[j - ges]);
			}
		}
	}
}
void heapsort(int *a, int index, int size)
{
	int left = index * 2 + 1;
	while (left < size)
	{
		int large = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;
		large = a[index] > a[large] ? index : large;
		if (index == large)
			break;
		swap(a[index], a[large]);
		index = large;
		left = index * 2 + 1;
	}
}
void sort_5(int *a, int length)
{
	if (a == nullptr || length < 2)
		return;
	for (int i = 0; i < length; ++i)
	{
		while (a[(i-1)/2]<a[i])   //大堆
		{
			swap(a[(i - 1) / 2], a[i]);
			i = (i - 1) / 2;
		}
	}
	int size = length;
	while (size > 0)
	{
		swap(a[0], a[--size]);
		heapsort(a, 0, size);
	}
}
class d
{
	d(const d& c)
	{
	}
};
class Date
{
public:
	
	// 如果用户显式定义了构造函数，编译器将不再生成
	Date (int year, int month, int day)
	{
	_year = year;
	_month = month;
	_day = day;
	}
	
private:
	int _year;
	int _month;
	int _day;
	//d a;
};
void Test()
{
	// 没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
		Date d(1,2,3);
}
struct A_B
{
	int a;
	int b;
};
A_B helanflash(int *a,int L,int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (a[L] < a[R])
			swap(a[L++], a[++less]);
		else if (a[L]>a[R])
			swap(a[L], a[--more]);
		else
			L++;
	}
	swap(a[R], a[more]);
	A_B c;
	c.a = less;
	c.b = more + 1;
	return c;
}
void sort_6(int *a,int L,int R)
{
	if (L < R)
	{
		swap(a[L + rand() % (R - L) + 1], a[R]);
		A_B ret = helanflash(a, L, R);
		sort_6(a, 0, ret.a);
		sort_6(a, ret.b, R);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//A2 a;
	//cout << sizeof(a);
	//Test();
	//cout << sizeof(Student);
	int a[] = { 5, 8, 9, 6, 3, 2, 7, 4, 1, 0 };
	int length = sizeof(a) / sizeof(a[0]);
	//sort_1(a,length);
	//sort_2(a,length);
	//sort_3(a, length);
	//sort_4(a, length);
	//sort_5(a, length);
	sort_6(a,0, length-1);
	for (auto e : a)
		cout << e << endl;
	return 0;
}
//class Date
//{
//public:
//	/*void PrintA()
//	{
//		cout << _a << endl;
//	}*/
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	Date* p = NULL; //p->PrintA();
//	p->Show();
//}