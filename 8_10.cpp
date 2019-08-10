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
	while (left < size)            //先判断是孩子是否存在
	{
		int larger = left + 1;
		if (larger < size)      //再判判断右孩子是否存在，存在的话寻找，左孩子，右孩子，和要调整位置的大小
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
		else   //如果没有右孩子则会走到这一步，这一步判断的就是左孩子和需要调整位置的大小
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
	int max = a[0];                   //一个数组先拿出这个数组中的最大值
	for (int i = 0; i < length; ++i)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}                              //等到这一步结束已经拿到了数组的最大值
	int *p = new int[max + 1];         //拿到最大值的话就申请0-最大值之间个空间大小的数组
	printf("%d", p[0]);
	for (int i = 0; i < max + 1; ++i)    //拿到数组之后不要忘记初始化，先把数据初始化成0
	{
		p[i] = 0;
	}
	for (int i = 0; i < length; ++i)      //然后再从需要排序的数组里面挨个拿出数字在进行统计的数组中自增
	{
		p[a[i]]++;                   
	}
	int j = 0;                 
	for (int i = 0; i < max + 1; ++i)         //这一步就是再把数据填充到原来的数组里面
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


