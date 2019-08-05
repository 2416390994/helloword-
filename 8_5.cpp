//两个有序数组，查找两个数组中相同的元素，思想就是，两个数组有序，用两个指针，分别指向两个数组，向后遍历并比较，
//第一个数组大于第二个，则小的数组指针向后移动，实现最优的算法，时间复杂度就是两个数组的长度相加
#if 0
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
void func(int *a, int *b,int len1,int len2)
{
	int *p = a;
	int *p1 =b;
	int c = 0;
	int d = 0;
	while ((c != len1)|| (d !=len2))
	{
		if (*p > *p1)
		{
			p1++;
			c++;
		}
		else if (*p < *p1)
		{
			p++;
			d++;

		}
		else
		{
			cout << *p << endl;
			p++;
			p1++;
			c++;
			d++;
			
		}
	}
}
int main()
{
	int a[] = { 5, 9, 11, 15, 16, 18, 22 };
	int b[] = { 1, 6, 8, 14, 15, 16, 22 };
	func(a, b, (sizeof(a) / sizeof(a[0])), (sizeof(b) / sizeof(b[0])));
	return 0;
}
#endif
//冒泡排序
#if 0
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func(int *a,int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j]>a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}
void printfs(int *a,int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d   ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = { 5, 6, 8, 4, 7, 9, 2, 1, 3, 0 };
	func(a,sizeof(a)/sizeof(int));
	printfs(a, sizeof(a) / sizeof(int));
	return 0;
}
#endif
#if 0
//对数器，如何生成随机的数组里面的随机个数
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	int c = rand() % 10;
	int* a = new int[c];
	for (int i = 0; i < c; ++i)
	{
		a[i] = rand() % 100;
	}
	for (int i = 0; i < c; ++i)
	{
		cout << a[i] << endl;
		//a[i] = rand() % 100;
	}

	return 0;
}
#endif
#if 0 
//随机生成字符串的那种，其实就是类型转换
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	int c = rand() % 100;
	char* a = new char[c];
	int d = 0;
	for (int i = 0; i < c; ++i)
	{
		d = rand() % 10;
		if ((d % 2) == 0)
		{
			a[i] = char(rand() % 26 + 65);
		}
		else
		{
			a[i] = char(rand() % 26 + 97);
		}
	}
	for (int i = 0; i < c; ++i)
	{
		cout << a[i];
		//a[i] = rand() % 100;
	}

	return 0;
}
#endif

//插入排序
#include<stdio.h>
void func(int *a, int len)
{
	int j;
	int i;
	int temp;
	for (i = 1; i < len ; i++)
	{
		temp = a[i];
		for (j = i; j > 0 && a[j - 1] > temp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}
void printfs(int *a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d   ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = { 2, 1, 5, 6, 4, 7, 8, 3, 9, 0 };
	func(a, sizeof(a) / sizeof(int));
	printfs(a, sizeof(a) / sizeof(int));
	return 0;
}
