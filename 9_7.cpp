//#include<iostream>
//using namespace std;
//void swap(int *x, int *y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//void func(int *a, int length)
//{
//	for (int i = 0; i < length - 1; ++i)
//	{
//		for (int j = 0; j < length - 1 - i; ++j)
//		{
//			if (a[j]>a[j + 1])
//			{
//				swap(&a[j], &a[j + 1]);
//			}
//		}
//	}
//}
//void func2(int *a, int length)
//{
//	for (int i = 0; i < length - 1; ++i)
//	{
//		int max = i;
//		for (int j = i; j < length; ++j)
//		{
//			if (a[j]>a[max])
//			{
//				max = j;
//			}
//		}
//		swap(&a[max], &a[i]);
//	}
//
//}
//void func3(int *a, int length)
//{
//	for (int i = 1; i < length; ++i)
//	{
//		for (int j = i; j>0 && a[j] > a[j - 1]; --j)
//		{
//			swap(&a[j], &a[j - 1]);
//		}
//	}
//}
////堆排序
//void paixu(int *a, int size)
//{
//	int index = 0;
//	int left = index * 2 + 1;
//	while (left<size)
//	{
//		int larger = left + 1 < size&&a[left + 1] > a[left] ? left + 1 : left;//这里的顺序很是重要
//		larger = a[larger]>a[index] ? larger : index;
//		if (larger == index)
//			break;
//		swap(&a[larger], &a[index]);
//		index = larger;
//		left = index * 2 + 1;
//	}
//}
//void jiandui(int *a, int index)
//{
//	int father = (index - 1) / 2;
//	while (a[index]>a[father])
//	{
//		swap(&a[index], &a[father]);
//		father = (father - 1) / 2;
//	}
//}
//void hastsort(int *a, int length)
//{
//	if (length == 0 || length < 2)
//		return;
//	for (int i = 0; i < length; ++i)
//	{
//		jiandui(a, i);
//	}
//	//建堆完毕开始排序
//	while (length>0)
//	{
//		swap(&a[0], &a[--length]);
//		paixu(a, length);
//	}
//}
//int main()
//{
//	int a[] = { 2, 5, 8, 9, 7, 4, 5 };
//	int L = sizeof(a) / sizeof(int);
//	//func(a, L);
//	//func2(a, L);
//	//func3(a, L);
//	hastsort(a, L);
//	for (int i = 0; i < L; ++i)
//	{
//		cout << a[i] << endl;
//	}
//	return 0;
//}
#include<stdio.h>
void test(const int *a)
{
	
}
void test1(const int *a)
{

}
int main()
{
	const int a = 10;
	test(&a);
	int b = 30;
	test1(&b);
	return 0;
}