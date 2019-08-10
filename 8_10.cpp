/*
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapinser(int *a, int index)
{
	while (a[index] > a[(index - 1) / 2])
	{
			swap(&a[index], &a[(index - 1) / 2]);
			index = (index - 1) / 2;
	}
}
void sort(int *a, int index, int size)
{
	int left = index * 2 + 1;
	while (left < size)            //���ж��Ǻ����Ƿ����
	{
		int larger = left + 1;
		if (larger < size)      //�����ж��Һ����Ƿ���ڣ����ڵĻ�Ѱ�ң����ӣ��Һ��ӣ���Ҫ����λ�õĴ�С
		{
			larger = a[left] > a[left + 1] ? left : larger;
			larger = a[larger] > a[index] ? larger : index;
			if (larger == index)
			{
				break;
			}
			swap(&a[larger], &a[index]);
			index = larger;
			left = (index * 2) + 1;
		}
		else   //���û���Һ�������ߵ���һ������һ���жϵľ������Ӻ���Ҫ����λ�õĴ�С
		{
			larger = a[index] > a[left] ? index : left;
			if (larger == index)
			{
				break;
			}
			swap(&a[larger], &a[index]);
			index = larger;
			left = (index * 2) + 1;
		}
	}
}
void sort(int *a, int index, int size)
{
	int left = index * 2 + 1;
	while (left < size)
	{	
			int larger = (left + 1 < size && a[left + 1]) > a[left] ? left + 1 : left;
			larger = a[larger] > a[index] ? larger : index;
			if (larger == index)
			{
				break;
			}
			swap(&a[larger], &a[index]);
			index = larger;
			left = (index * 2) + 1;
	}
}
void heapsort(int *a, int length)
{
	
	int size = length;
	if (a == NULL || size < 2)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		heapinser(a, i);
	}
	while (size > 0)
	{
		swap(&a[0], &a[--size]);
		sort(a, 0, size);
	}
}

int main()
{
	int a[] = { 5, 8, 6, 7, 4, 5, 9, 9, 8, 3, 6, 4, 1, 1, 0, 2, 5, 4, 6, 2, 5, 5 };
	int c = sizeof(a) / sizeof(int);
	heapsort(a, c);
	for (int i = 0; i < c	; ++i)
	{
		printf("%d", a[i]);
	}
	return 0;
}
*/

#include<stdio.h>
#include<iostream>
using namespace std;
void sort(int *a, int length)
{
	int max = a[0];                   //һ���������ó���������е����ֵ
	for (int i = 0; i < length; ++i)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}                              //�ȵ���һ�������Ѿ��õ�����������ֵ
	int *p = new int[max + 1];         //�õ����ֵ�Ļ�������0-���ֵ֮����ռ��С������
	printf("%d", p[0]);
	for (int i = 0; i < max + 1; ++i)    //�õ�����֮��Ҫ���ǳ�ʼ�����Ȱ����ݳ�ʼ����0
	{
		p[i] = 0;
	}
	for (int i = 0; i < length; ++i)      //Ȼ���ٴ���Ҫ������������氤���ó������ڽ���ͳ�Ƶ�����������
	{
		p[a[i]]++;                   
	}
	int j = 0;                 
	for (int i = 0; i < max + 1; ++i)         //��һ�������ٰ�������䵽ԭ������������
	{
		while ((p[i]--)>0)
		{
			a[j++] = i;
		}
	}
}
int main()
{
	int a[] = { 9, 7, 8, 5, 4, 6, 2, 1, 3, 0, 5, 8, 9, 2, 5, 2, 4, 6, 2, 4, 8, 2, 1, 5, 3, 2, 2, 1, 4, 7, 8, 9, 6, 3, 0, 1, 2, 5, 4, 8, 9, 6, 4 };
	int c = sizeof(a) / sizeof(int);
	sort(a, c);
	/*for (int i = 0; i < c; ++i)
	{
		printf("%d", a[i]);
	}*/
	return 0;
}


