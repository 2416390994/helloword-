
#if 0
#include<stdio.h>
#include<iostream>
using namespace std;
void sort(int *a, int L, int M, int R)
{
	int *b = new int[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
	while (p1 <= M && p2 <= R)
	{
		b[i++] = (a[p1] > a[p2])? a[p1++] : a[p2++];
	}
	while (p1 <= M)
	{
		b[i++] = a[p1++];
	}
	while (p2 <= R)
	{
		b[i++] = a[p2++];
	}
	for (i = 0; i < (R - L + 1); i++)
	{
		a[L + i] = b[i];
	}
}
void func(int *a, int L, int R)
{
	if (L == R)
	{
		return;
	}
	int M = L + ((R - L) >> 1);
	func(a, L,  M);
	func(a, M + 1, R);
	sort(a, L, M, R);
}
int main()
{
	int a[] = { 2, 5, 9, 8, 4, 6, 3, 1, 0, 7 };
	func(a, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
#endif

//һ�����������������ÿһ��Ԫ�صģ���ߵ�Ԫ�ر���С�ĺͣ������ⷨ��
#include<stdio.h>
int func(int *a,int len)
{
	int leng = len;
	int L = 0;
	int sun = 0;
	int add = 0;
	int i ;
	while (L < leng)
	{
		i = L;
		while (--i >= 0)
		{
			if (a[i] < a[L])
			{
				sun += a[i];
			}
		}	
		L++;
		add += sun;
		sun = 0;       //������add+��֮��Ҫ��һ��0����Ϊ������õĻ��ͻᱣ��sun����һ������
	}
	return add;
}
int main()
{
	int a[] = { 1, 7, 5, 10, 9, 3, 4, 8, 6, 2, 15, 13 };
	int ret = func(a,sizeof(a)/sizeof(int));
	printf("%d\n", ret);
	return 0;
}











