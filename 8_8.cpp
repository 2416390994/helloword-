#if 0
//归并排序
#include<stdio.h>
void sort(int *a, int L, int M, int R)
{
	int *p = new int[(R - L + 1)];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 << R)
	{
		p[i++] = (a[p1] > a[p2]) ? a[p1++] : a[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = a[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = a[p2++];
	}
	for (i = 0; i < (R - L + 1); ++i)
	{
		a[L + i] = p[i];
	}
}
void func(int *a, int L, int R)
{
	if (L == R)
		return;
	int M = L + ((R - L) >> 1);
	func(a, L, M);
	func(a, M + 1, R);
	sort(a, L, M, R);
}
int main()
{
	int a[] = { 8, 9, 6, 4, 2, 3, 5, 7, 1, 0 };
	func(a, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
#endif
#if 0
//使用归并排序的思想处理一个数组，每个元素左边的比他小的元素的和
#include<stdio.h>
int merge(int *a, int L, int M, int R)
{
	int *p = new int[(R - L + 1)];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	int ret = 0;
	while (p1 <= M && p2 << R)
	{
		ret += (a[p1] < a[p2]) ? (R - p2 + 1)*a[p1] : 0;
		p[i++] = (a[p1] > a[p2]) ? a[p1++] : a[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = a[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = a[p2++];
	}
	for (i = 0; i < (R - L + 1); ++i)
	{
		a[L + i] = p[i];
	}
	return ret;
}
int func(int *a, int L, int R)
{
	if (L == R)
		return 0;
	int M = L + ((R - L) >> 1);
	return func(a, L, M) + func(a, M + 1, R) + merge(a, L, M, R);
}
int main()
{
	int a[] = { 5, 8, 3, 6 };
	int ret = func(a, 0, 3);
	printf("%d", ret);
	return 0;
}
#endif
//快排思想
/*
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func(int *a, int L, int R)
{
	int mer = a[R];
	int min = 0;
	//while (i <= R)
	//{
	//	if (a[i] <= mer)
	//	{
	//		swap(&a[i], &a[min]);
	//		min++;
	//	}
	//	i++;
	//}
	for (int i; i <= R ; i++)
	{ 
		if (a[i] <= mer)
		{
			swap(&a[i], &a[min]);
			min++;

		}
	}
}
int main()
{
	int a[] = { 6, 9, 4, 2, 3 };
	func(a, 0, 4);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d", a[i]);
	}
	return 0;
}
*/



/*
//快排引出的荷兰国旗问题
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//一个问题的写法有很多，怎么想就怎么写，结果都是一样的
void func(int *a, int L, int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (a[L] > a[R])
		{
			swap(&a[L], &a[--more]);
		}
		else if (a[L] < a[R])
		{
			swap(&a[++less], &a[L++]);
		}
		else
		{
			L++;
		}
	}
	swap(&a[R], &a[more]);
}
#include<stdio.h>
int main()
{
	int a[] = { 7,6,4,4,3,7,3,2,4};
	int c = sizeof(a) / sizeof(int);
	func(a, 0, c-1);
	for (int i = 0; i < c; ++i)
	{
		printf("%d\n", a[i]);
	}


	int b[] = { 0,1,2,1,0,1,1,2,2,0,0,1 };
	int d = sizeof(b) / sizeof(int);
	func(b, 0, d - 1);
	for (int i = 0; i < d; ++i)
	{
		printf("%d", b[i]);
	}
	return 0;
}
*/

//快排



#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	int a[] = { 7, 6, 4, 4, 3, 7, 3, 2, 4 };
	int c = sizeof(a) / sizeof(int);
	func(a, 0, c - 1);
	for (int i = 0; i < c; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
void quitesort(int *a, int L, int R)
{
	if (L < R)
	{
		swap(&a[rand() % R + 1], &a[R]);
		int *p = func(a, L, R);
		quitesort(a, L, p[0]--);
		quitesort(a, p[1]++, R);
	}
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int* func(int *a, int L, int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (a[L] > a[R])
		{
			swap(&a[L], &a[--more]);
		}
		else if (a[L] < a[R])
		{
			swap(&a[++less], &a[L++]);
		}
		else
		{
			L++;
		}
	}
	swap(&a[R], &a[more]);
	return new int[]{less + 1, more};
}

















