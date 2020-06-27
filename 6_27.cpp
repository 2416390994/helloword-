#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
#include<functional>
using namespace std;
template<class T1>
class mystring
{
public:
	mystring& operator=(const mystring& p)
	{
		if (&p != this)
		{
			
		}
		return *this;
	}

};

void func()
{

}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "almost every programmer should know memset!";
//	memset(str, '-', 6);
//	puts(str);
//	return 0;
//}
class String
{
	String(char* p = "")
	{
		if (p == nullptr)
			p = "";
		_p = new char[strlen(p) + 1];
		strcpy(_p, p);
	}

	String(String& p)
	{
		if (&p != this)
		{
			_p = new char[p.size() + 1];
			strcpy(_p, p._p);
		}
	}
	int size()
	{
		return strlen(_p);
	}

	String& operator=(String& p)
	{
		if (&p != this)
		{
			delete _p;
			_p = new char[p.size() + 1];
			strcpy(_p, p._p);
		}
		return *this;
	}

private:
	char* _p;
};

void func1(vector<int> vec)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		//int j = i;
		while (vec[i] > vec[(i - 1) / 2])
		{
			swap(vec[i], vec[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	while (size)
	{
		swap(vec[0], vec[--size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int great = left + 1 < size && vec[left] < vec[left + 1] ? left + 1 : left;
			great = vec[great] > vec[index] ? great : index;
			if (great == index)
				break;
			swap(vec[index],vec[great]);
			index = great;
			left = index * 2 + 1;
		}
	}
	for (auto e : vec)
		cout << e << endl;

}


template<class y,typename x>
class my
{


};

#include <stdio.h>
#include <string.h>
int main()
{
	int N = 10;
	vector<int> vec(N, N);
	vector<int> vec{ 2, 58, 9, 4, 1, 3, 1, 4, 47 };
	//priority_queue<int,vector<int>,greater<int>> p(vec.begin(), vec.end());
	func1(vec);

	//mystring<int> mm;
	//char* c = "xxxx";
	//string s(c);
	//char str1[] = "Sample string";
	//char str2[40];
	//char str3[40];
	//memcpy(str2, str1, strlen(str1) + 1);//不会自动拷贝最后的\0需要加1
	////strcpy会自动拷贝最后的\0
	//memcpy(str3, "copy successful", 16);
	//printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}