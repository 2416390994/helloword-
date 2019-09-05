//#include<stdio.h>
//int main()
//{
//	//devenv / ResetSkipPkgs
//	return 0;
//}
////∂—≈≈–Úªÿ“‰
//#include<iostream>
//using namespace std;
//void swap(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void paixu(int *a,int size)
//{
//	int nn = 0;
//	int left = nn * 2 + 1;
//	while (left < size)
//	{
//		int larger = left + 1 < size&&a[left+1] > a[left] ? left+1 : left;
//		larger = a[larger] > a[nn] ? larger : nn;
//		if (larger == nn)
//		{
//			break;
//		}
//		swap(&a[larger], &a[nn]);
//		nn = larger;
//		left = nn * 2 + 1;
//	}
//}
//void jiandiu(int *a, int length)
//{
//	if (length == NULL || length < 1)
//	{
//		return;
//	}
//	for (int i = 0; i < length; ++i)
//	{
//		while (a[i]>a[(i-1)/2])
//		{
//			swap(&a[i], &a[(i - 1)/2]);
//			i = (i - 1) / 2;
//		}
//	}
//	while (length > 0)
//	{
//		swap(&a[0], &a[--length]);
//		paixu(a, length);
//	}	
//}
//
//int main()
//{
//	int a[] = { 2, 5, 8, 9, 3, 4, 8, 2, 5, 5, 3, 5, 1, 5, 4 };
//	jiandiu(a, 15);
//	for (int i = 0; i < 15; ++i)
//	{
//		cout << a[i] << endl;
//	}
//	return 0;
//}
//√∞≈›≈≈–Ú
//#include<iostream>
//using namespace std;
//void swap(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int a[] = { 2, 3, 6, 5, 4 };
//	int size = sizeof(a) / sizeof(int);
//	/*for (int i = 0; i <size-1 ; ++i)
//	{
//		for (int j = 0; j < size - 1 - i; ++j)
//		{
//			if (a[j]>a[j + 1])
//				swap(&a[j], &a[j + 1]);
//		}
//	}
//*/
//	for (int i = 0; i < size; ++i)
//	{
//		cout << a[i] << endl;
//	}
//
//	return 0;
//}
//—°‘Ò≈≈–Ú
//#include<iostream>
//using namespace std;
//void swap(int *a,  int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int a[] = { 2, 5, 9, 8, 7, 5 };
//	int size = sizeof(a) / sizeof(int);
//	for (int i = 0; i < size - 1; ++i)
//	{
//		int max = i;
//		for (int j = i; j < size; ++j)
//		{
//			if (a[max]<a[j])
//				max = j;
//		}
//		swap(&a[max], &a[i]);
//	}
//	for (int i = 0; i < size; ++i)
//	{
//
//		cout << a[i] << endl;
//	}
//
//	return 0;
//}
//≤Â»Î≈≈–Ú
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int a[] = { 5, 8, 9, 7, 6, 5, 1 };
//	int size = sizeof(a) / sizeof(int);
//	for (int i = 1; i < size; ++i)
//	{
//		for (int j = i; j>0 && a[j] > a[j - 1]; --j)
//		{
//			swap(a[j], a[j - 1]);
//		}
//	}
//	for (int i = 0; i < size; ++i)
//	{
//		cout << a[i] << endl;
//	}
//
//	return 0;
//}
//#include<stdio.h>
//#include<ctype.h>
//#include<cerrno>
//int main()
//{
//	int c;
//	int A = 0, B = 0, C = 0;
//	//while ((c = getchar()) != EOF)
//	while ((c = getchar()) != '\n')
//		//putchar(toupper(c));
//		//putchar(tolower(c));
//	{
//		if (c > 'A'&&c < 'Z')
//			A++;
//		if (c>'a'&&c < 'z')
//			B++;
//		else
//			C++;
//	}
//	int ret = printf("%d,%d,%d\n", A, B, C);
//	if (ret != 0)
//	{
//		printf("%d\n", 10111);
//		perror("fdehqiu");
//	}
//	return 0;
//}
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h> 
int main(void)
{    
	extern int errno;
	errno = 10;
	//extern int a;
	//a = 10;
	printf("%d\n", errno);
	/*for(int i = 0; i < 140; i++)
	{        
		printf("%4d:%s\n", i, strerror(i));    
	}     */
	if (errno == 10){
		perror("opendir: ");
	}
	exit(0);
}
