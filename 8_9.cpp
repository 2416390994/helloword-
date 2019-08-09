//稳定的冒泡排序
/*
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a[] = { 4, 5, 4, 6, 9, 9, 8, 7, 2, 2, 5, 6, 5 };
	int c = sizeof(a) / sizeof(int);
	for (int i = 0; i < c - 1; ++i)
	{
		for (int j = 0; j < c - 1 - i; ++j)
		{
			if (a[j]>a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				if (a[j + 1] == a[j + 2])  //加上这一段就可以使冒泡排序变成稳定的排序
				{
					j++;
				}
			}
		}
	}
	for (int i = 0; i < c; ++i)
	{
		printf("%d", a[i]);
	}
	return 0;
}
*/

/*
#include<stdio.h>
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
int main()
{
int a[] = { 4, 5, 4, 6, 9, 9, 8, 7, 2, 2, 5, 6, 5 };
int c = sizeof(a) / sizeof(int);
for (int i = 1; i < c; ++i)
{
for (int j = i; j>0 && a[j] > a[j - 1]; --j)
{
swap(&a[j], &a[j - 1]);
}
}
for (int i = 0; i < c; ++i)
{
printf("%d", a[i]);
}
return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a[] = { 4, 5, 4, 6, 9, 9, 8, 7, 2, 2, 5, 6, 5 };
	int c = sizeof(a) / sizeof(int);
	//printf("%d", c);
	int i;
	int j;
	for (i = 0; i < c - 1; i++)
	{
		int max = i;
		for (j = i + 1; j < c; j++)
		{
			if (a[j] > a[max])
			{
				max = j;
			}
		}
		swap(&a[i], &a[max]);
	}
	for (i = 0; i < c; ++i)
	{
		printf("%d", a[i]);
	}
	return 0;
}
*/
/*
//归并排序
#include<stdio.h>
void sort(int *a, int L, int M, int R)
{
	int *p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = a[p1] >= a[p2] ? a[p1++] : a[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = a[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = a[p2++];
	}
	for (i = 0; i < R - L + 1; ++i)
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
	int a[] = { 5, 8, 9, 6, 3, 4, 7, 2, 1, 0 ,0};
	func(a, 0, 10);
	for (int i = 0; i < 11; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
*/

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
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if ((a[L]) % 2 == 0)
		{
			less++;
			L++;
		}
		else
		{
			swap(&a[L], &a[more--]);
		}
	}
}
int main()
{
	int a[] = { 5, 7, 8, 9, 6, 3, 5, 4, 1, 2 };
	func(a, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
*/
/*
//将一个数组构造成为一个堆
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapInser(int *a, int i)
{
	while (a[i] > a[(i - 1) / 2])   //我们这里构造的就是大堆
	{
		swap(&a[i], &a[(i - 1) / 2]); //当子节点大于父节点的值的时候就一直while循环网往上换，直到找到合适的位置
		i = (i - 1) / 2;   //这一步的目的就是上面一步 交换完之后万比交换后的位置的父节点还要大那么就要准备在while中做第二次循环了，所以要改变i的位置，确保交换的是同一个数字
	}
}
void heapsort(int *a, int L)
{
	if (a == NULL || L < 2)
	{
		return;
	}
	for (int i = 0; i < L; i++)
	{
		heapInser(a, i);
	}
}
int main()
{
	int a[] = { 5, 0, 7, 6, 8 };
	int L = sizeof(a) / sizeof(int);
	heapsort(a, L);
	printf("%d", a[0]);
	printf("%d", a[1]);
	printf("%d", a[2]);
	printf("%d", a[3]);
	printf("%d", a[4]);
	//printf("%d", a[5]);
	//printf("%d", a[6]);
	return 0;
}
*/

#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapInser(int *a, int i)
{
	while (a[i] > a[(i - 1) / 2])     // 
	{
		swap(&a[i], &a[(i - 1) / 2]); 
		i = (i - 1) / 2;   
	}
}
void heapify(int *a, int index, int size)
{
	int left = index * 2 + 1;
	//int largest = a[left] > a[left + 1] ? left : left + 1;
	while (left < size)   //判断是不是存在左子树，要是存在的话才能进入循环
	{
		int largest = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;//要确保这个largest是左右孩子里面的最大的 
		largest = a[largest]>a[index] ? largest : index;//这一步拿到的是三个元素中的最大者，也就是哦安定要不要进行再往下交换
		if (largest == index)
		{
			break;
		}
		swap(&a[largest], &a[index]);
		index = largest;   //交换下标，跟踪同一个元素
		left = index * 2 + 1;    //确定下一个左孩子
	}
}
void heapsort(int *a, int L)
{
	int size = L;
	if (a == NULL || L < 2)
	{
		return;
	}
	for (int i = 0; i < L; i++)
	{
		heapInser(a, i);
	}
//=============================================================================//
	//接下来的操作就是在 上面已经将数组变成大堆的基础上进行排序
	while (size > 0)
	{
		swap(&a[0], &a[--size]);
		heapify(a, 0, size);
	}
}
int main() 
{
	int a[] = { 5, 0, 7, 6, 8 };
	int L = sizeof(a) / sizeof(int);
	heapsort(a, L);
	printf("%d", a[0]);
	printf("%d", a[1]);
	printf("%d", a[2]);
	printf("%d", a[3]);
	printf("%d", a[4]);
	//printf("%d", a[5]);
	//printf("%d", a[6]);
	return 0;
}
















