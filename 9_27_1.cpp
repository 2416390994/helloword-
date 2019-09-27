//#include<iostream>
//using namespace std;
//void sort_1(int *a,int length)
//{
//	for (int i = 0; i < length - 1; ++i)
//	{
//		int max = i;
//		for (int j = i + 1; j < length; ++j)
//		{
//			if (a[max] < a[j])
//			{
//				max = j;
//			}
//		}
//		swap(a[max], a[i]);
//	}
//}
//void sort_2(int *a,int length)
//{
//	for (int i = 0; i < length - 1; ++i)
//	{
//		for (int j = 0; j < length - i - 1; ++j)
//		{
//			if (a[j]>a[j+1])
//			{
//				swap(a[j], a[j+1]);
//			}
//		}
//	}
//}
//void sort_3(int *a,int length)
//{
//	for (int i = 1; i < length; ++i)
//	{
//		for (int j = i; j>0 && a[j] > a[j - 1]; --j)
//		{
//			swap(a[j], a[j - 1]);
//		}
//	}
//}
//
//void heapsort(int *a, int index, int length);
////Ω®∂—
//void sort_4(int *a, int length)
//{
//	int size = length;
//	while (a == nullptr || length <= 2)
//		return;
//	
//	for (int i = 0; i < length; ++i)
//	{
//		while (a[i]>a[(i - 1) / 2])
//		{
//			swap(a[i], a[(i - 1) / 2]);
//			i = (i -1)/2;
//		}
//	}
//	while (size > 0)
//	{
//		swap(a[0], a[--size]);
//		heapsort(a, 0, size);
//	}
//}
//
////≈≈–Ú
//void heapsort(int *a,int index,int length)
//{
//	int left = index * 2 + 1;
//	while (left < length)
//	{
//		int larger = left + 1 < length && a[left + 1] > a[left] ? left + 1 : left;
//		larger = a[larger]>a[index] ? larger : index;
//		if (larger == index)
//			break;
//		swap(a[index], a[larger]);
//		index = larger;
//		left = index * 2 + 1;
//	}
//}
//void sort_5(int *a,int length)
//{
//	int ges = length;
//	while (ges > 1)
//	{
//		ges = ges / 3 + 1;
//		int i = ges;
//		for (i ; i < length;  i +=ges)
//		{
//			for (int j = i; j>0 && a[j] > a[j - ges]; j -= ges)
//			{
//				swap(a[j], a[j - ges]);
//			}
//		}
//	}
//}
//void sort_5(int *a, int length)
//{
//	int ges = length;
//	while (ges > 1)
//	{
//		ges = ges / 3 + 1;
//		int i = ges;
//		for (i; i < length; i += ges)
//		{
//			for (int j = i; j>0 && a[j] > a[j - ges]; j -= ges)
//			{
//				swap(a[j], a[j - ges]);
//			}
//		}
//	}
//}
//struct a_b
//{
//	int a;
//	int b;
//};
//a_b func(int *a,int L,int R)
//{
//	int less = L - 1;
//	int more = R;
//	while (L < more)
//	{
//		if (a[L]>a[R])
//			swap(a[L], a[--more]);
//		else if (a[L] < a[R])
//			swap(a[++less], a[L++]);
//		else
//			L++;
//	}
//	swap(a[more], a[R]);
//	a_b c;
//	c.a = less;
//	c.b = more + 1;
//	//return new int[]{less + 1, more};
//	return c;
//
//}
//void sort_6(int *a,int L,int R)
//{
//	if (L < R)
//	{
//		swap(a[L+rand() % (R - L) + 1], a[R]);
//		a_b ret = func(a, L, R);
//		sort_6(a, L, ret.a);
//		sort_6(a, ret.b, R);
//	}
//}
//#include<time.h>
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int a[] = { 5, 6, 9, 8, 4, 3, 1, 0, 7, 2 };
//	int length = sizeof(a)/sizeof(0);
//	//sort_1(a,length);  —°‘Ò≈≈–Ú
//	//sort_2(a, length);  √∞≈›≈≈–Ú
//	//sort_3(a, length);   ≤Â»Î≈≈–Ú
//	//sort_4(a, length);   ∂—≈≈–Ú
//	//sort_5(a, length);   œ£∂˚≈≈–Ú
//	sort_6(a, 0,length-1);
//	for (int i = 0; i < length; ++i)
//	{
//		cout << a[i];
//	}
//	cout << endl;
//	return 0;
//}
//
////#include<stdio.h>
////#include<time.h>
////#include<stdlib.h>
////void quitesort(int *a, int L, int R);
////void swap(int *a, int *b)
////{
////	int temp = *a;
////	*a = *b;
////	*b = temp;
////}
////int * func(int *a, int L, int R)
////{
////	int less = L - 1;
////	int more = R;
////	while (L < more)
////	{
////		if (a[L] < a[R])
////		{
////			swap(&a[L++], &a[++less]);
////		}
////		else if (a[L]>a[R])
////		{
////			swap(&a[L], &a[--more]);
////		}
////		else
////		{
////			L++;
////		}
////	}	
////	swap(&a[more], &a[R]);
////	printf("%d,%d\n", less + 1, more);
////	return new int[]{less + 1, more};
////}
////void quitesort(int *a, int L, int R)
////{
////	if (L < R)
////	{
////		swap(&a[L + rand() % (R - L) + 1], &a[R]);
////		int * p = func(a, L, R);
////		//printf("%d,%d\n", *p, *(p++));
////		printf("%d,%d", p[0], p[1]);
////		quitesort(a, L, p[0] - 1);
////		quitesort(a, p[1] + 1, R);
////	}
////}
////int main()
////{
////	srand((unsigned int)time(NULL));
////	int a[] = { 7, 8, 5, 4, 6, 2, 1, 2, 2, 1, 1, 1, 3, 3 };
////	int c = sizeof(a) / sizeof(int);
////	quitesort(a, 0, c - 1);
////	for (int i = 0; i < c; ++i)
////	{
////		printf("%d\n", a[i]);
////	}
////	return 0;
////}
