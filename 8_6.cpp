#if 0
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func(int *a, int len)
{
	int i, j, k;
	for (i = 1; i < len; ++i)
	{
		//k = a[i];
		//for (j = i; j>0 && a[j - 1] > k; --j)   //a[j] >a[j-1]
		//	a[j] = a[j - 1];
		//	a[j] = k;
		for (j = i - 1; j >= 0 && a[j]>a[j + 1]; --j)
		{
			swap(&a[j + 1], &a[j]);
		}
	}
}
int main()
{
	int a[] = { 5, 8, 9, 7, 4, 3, 6, 1, 2, 0 };
	func(a,10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", a[i]);
	}

}
#endif
//归并排序
//用递归求一个数组的最大值
#if 0
#include<stdio.h>
void getmax(int *a, int L, int R)
{
	if (L == R)
	{
		return ;
	}
	int M = L + ((R - L) / 2);
	int Left = getmax(a, L, M);
	int Right = getmax(a, M + 1, R);
	return (Right > Left) ? Right : Left;
}
int main()
{
	int a[] = { 8, 6, 4, 9, 3, 1, 5, 7, 0, 2 };
	int ret = getmax(a, 0, 9);
	printf("%d", ret);
	return 0;
}
#endif
//归并排序
#include<stdio.h>
#include<iostream>
using namespace std;
void sort(int *a, int L, int M, int R)
{
	int* p = new int[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = (a[p1] < a[p2]) ? a[p1++] : a[p2++];
	}
	while (p2 <= R)
	{
		p[i++] = a[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = a[p1++];
	}
	for (i = 0 ; i < (R - L + 1); i++)
	{
		a[L + i] = p[i];
	}
}
void func(int *a, int L, int R)
{
	if (L == R)
	{
		return;
	}
	int M = L + ((R - L) >> 1);
	func(a, L, M);
	func(a, M + 1, R);
	sort(a, L, M, R);
}
int main()
{
	int a[] = { 1, 7, 9, 5, 4, 6, 3, 2, 0, 8 };
	func(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}

