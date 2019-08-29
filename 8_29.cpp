//#include<iostream>
//#include<math.h>
//using namespace std;
/*
int func(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
		return func(n - 1) + func(n - 2);
}
int func2(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
		return func2(n - 1)* n;
}
void func3(int *a)
{
	for (int i = 2; i < 101; ++i)
	{
		if (a[i] != 0)
		{
			for (int j = 2 * i; j < 101;)
			{
				if (a[j] % a[i] == 0)
				{
					a[j] = 0;
					j = j + i;
				}
			}
		}
	}
}
void test1()
{
	int a[101];
	for (int i = 1; i < 101; ++i)
		a[i] = 1;
	func3(a);
	for (int i = 1; i < 101; ++i)
	{
		if (a[i] != 0)
		{
			cout << i << endl;
		}
	}
}
void test()
{
	int j;
	for (int i = 1; i < 100; ++i)
	{
		int k =(int)sqrt(i);
		for (j = 2; j <= k; ++j)
		{
			if (i%j == 0)
				break;
		}
		if (j>k)
		{
			cout << i << endl;
		}
	}
}
void test2()
{
	for (int i = 1; i <= 8; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << '*';
			for (int k = 1; k < i; ++k)
			{
				cout << '.';
			}
		}		
		cout << endl;
	}
}
char a[] = "hart";
char *p;
int length;
void lines(char a[],char p[],int length,int res,int start)
{
	for (int i = start; i < length; i++)
	{
		//cout << a[3];
		p[res] = a[start];
		p[res + 1] = 0;
		printf("%s\n", p);
		if (i < length - 1)
		{
			lines(a, p, length, res+1, start+1);
		}
	}
}

int main()
{

	//cout << func(3) << endl;
	//cout << func2(4) << endl;
	//test1();
	//test();
	//test2();
	
	length = strlen(a);
	p = (char*)malloc(length + 1);
	lines(a, p, length, 0, 0);
	return 0;
}
*/
//char str[] = "hart";
//int length;
//char *out;
//void func(char in[], char out[], int length, int rec, int start)
//{
//	int i;
//	for (int i = start; i < length; i++)
//	{
//		out[rec] = in[i];
//		out[rec + 1] = 0;
//		printf("%s\n", out);
//		if (i < length - 1)
//		{
//			func(in, out, length, rec + 1, i + 1);
//		}
//	}
//}
//int main()
//{
//	length = strlen(str);
//	out = (char *)malloc(length + 1);
//	func(str, out, length, 0, 0);
//	return 0;
//}

//void func(char a[], char p[], int length, int res, int start)
//{
//	for (int i = start; i < length; i++)
//	{
//		p[res] = a[i];
//		p[res + 1] = 0;
//		printf("%s\n", p);
//		if (i < length - 1)
//		{
//			func(a, p, length, res + 1, i + 1);
//		}
//	}
//}
//int main()
//{
//	char a[] = "hart";
//	int length = strlen(a);
//	char *p = (char *)malloc(length + 1);
//	func(a, p, length, 0, 0);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class func
{
public:
	func() :str(nullptr)
	{
		cout << "构造" << endl;
	}
	func(const func  &dc)
	{
		cout << "拷贝构造函数" << endl;
		this->str = new char[strlen(dc.str) + 1];
		strcpy(str, dc.str);
	}
	~func()
	{
		if (str)
		{
			//cout << (int*)this << endl << (int*)str << endl;
			cout << "析构" << endl;
			delete str;
		}
	}
	char * str;
};
int main()
{
	func d1;
	d1.str = new char[32];
	strcpy(d1.str, "nihao,hamamaipi");
	vector<func> *v= new vector<func>();
	v->push_back(d1);
	delete v;
	return 0;
}