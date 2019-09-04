//#include<iostream>
//using namespace std;
//void func(int *a, int length, int find)
//{
//	int L = 0;
//	int R = length;
//	while (L < R)
//	{
//		int middle = L + ((R - L) >> 1);
//		if (find < a[middle])
//		{
//			R = middle;
//		}
//		else if (find > a[middle])
//		{
//			L = middle + 1;
//		}
//		else
//		{
//			printf("%d\n", middle);
//			break;
//		}
//	}
//	if (L >= R)
//	{
//		printf("没找到\n");
//	}
//}
//int main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	func(a, 10, 10);
//	return  0;
//}
//#include<iostream>
//using namespace std;
//void func(int *a, int length, int find)
//{
//	int L = 0;
//	int R = length - 1;
//	int flat = 0;
//	while (L <= R)
//	{
//		int middle = L + ((R - L) >> 1);
//		if (find < a[middle])
//		{
//			R = middle - 1;
//		}
//		else if (find > a[middle])
//		{
//			L = middle + 1;
//		}
//		else
//		{
//			printf("%d\n", middle);
//			flat = 1;
//			break;
//		}
//	}
//	if (flat  = 0)
//	{
//		printf("没找到\n");
//	}
//}
//int main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	func(a, 10, 10);
//	return  0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = -1;
//	int c = a >> 1;
//	cout << c << endl;
//	cout << -1 / 2 << endl;
//	int b = 0xffffffff;
//	cout << b << endl;
//	cout << (b>>1) << endl;
//	int d = 0;
//	cout << (d >> 1) << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func(int *a, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - 1 -i; ++j)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
}
void test(int *a,int length)
{
	int max;
	for (int i = 0; i < length - 1; ++i)
	{
		max = i;
		for (int j = i; j < length - 1; ++j)
		{
			if (a[j]>a[max])
				max = j;
		}
		swap(&a[max], &a[i]);
	}
}
void charu(int *a, int length)
{
	for (int i = 1; i < length; ++i)
	{
		//for (int j = i; j > 0; --j)
		//{
		//	if (a[j] > a[j - 1])
		//	{
		//		swap(&a[j], &a[j - 1]);
		//	}
		//	else
		//		break;    //这一步只要是为了是为了缩短步骤，不必每次都遍历到最后一个数字
		//}
		for (int j = i; j > 0 && a[j] > a[j - 1]; --j)    //这样写的话完就不必担心上面的问题了
		{
			swap(&a[j], &a[j - 1]);
		}
	}
}
int main()
{
	int a[] = { 2, 1, 3, 5, 9, 8, 7, 4, 6, 0 };
	//func(a, 10);
	//test(a, 10);
	charu(a, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << endl;
	}
	return 0;
}