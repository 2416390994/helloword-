#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int L = 0;
	int R = (sizeof(arr) / sizeof(arr[0]));
	int M;
	int num;
	scanf("%d", &num);
	while (L < R)
	{
		M = (L + R) / 2;
		if (num>arr[M])
			L = M + 1;
		else if (num < arr[M])
			R = M;
		else if (num == arr[M])
		{
			printf("%d", M);
			break;
		}
		if (L >= R)
			printf("没有你要找的数字\n");
	}
}