#include<iostream>
#include<string.h>
using namespace std;
int*  test(int *a, int length, int find);
int main()
{
	int a[] = { 1, 3, 4, 6, 7, 9, 10, 16, 18, 25, 33 };
	int * p = a;
	int *ret = test(a, sizeof(a) / sizeof(int),33);
	if (ret == nullptr)
	{
		cout << "没有" << endl;
	}
	else
		cout << "找到了 :"<<*ret << endl;
	return 0;
}
int*  test(int *a, int length, int find)
{
	int  *L = a;
	int *R = (a + length-1);
	int w;
	int *middle = L;
	while (*R >= *L)
	{
		w = (R - L) / 2;
		cout << w << endl;
		middle = (L + w);
		cout << *L << "  " << *middle << "  " << *R << endl;
		if (find > *middle)
		{
			L = middle+1;
		}
		else if (find < *middle)
		{
			R = middle-1;
		}
		else
		{
			return middle;
		}
	}
	return nullptr;
}
//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int num = 11;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int lead = 0;
//	int read = (sizeof(arr) / sizeof(arr[0])) - 1;
//	while (lead <= read)     //这里的判断条件用的是小于，而不是小于等于
//	{
//		int mid = (lead + read) / 2;
//		if (num > arr[mid])
//		{
//			lead = mid + 1;
//		}
//		else if (num < arr[mid])
//		{
//			read = mid;
//		}
//		else if (num == arr[mid])
//		{
//			printf("%d", mid);
//			break;
//		}
//	}
//	if(lead > read)  //判断完前面之后，要是在lead<read的时候没有，找到这个数字，那么当他们俩相等的时候就说明你查找的区域没有你要找的数字 
//	{
//		printf("没找到这个数字");
//	}
//	system("pause");
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int num = 11;
//	int arr[11] = { 1, 3, 4, 6, 7, 9, 10, 16, 18, 25, 33 };
//	int lead = 0;
//	int read = (sizeof(arr) / sizeof(arr[0])) - 1;
//	while (lead < read)     
//	{
//		int mid = (lead + read) / 2;
//		//printf("%d,%d,%d\n", arr[lead], arr[mid], arr[read]);
//		if (num > arr[mid])
//		{
//			lead = mid + 1;
//		}
//		else if (num < arr[mid])
//		{
//			read = mid;
//		}
//		else if (num == arr[mid])
//		{
//			printf("%d", mid);
//			break;
//		}
//	}
//	if (lead > read)  
//	{
//		printf("没找到这个数字");
//	}
//	system("pause");
//	return 0;
//}
//#include<iostream> 
//using namespace std;
//int BinarySearch(int *p,const int x,const int n)
//{	
//	int left=0,right=n-1;	
//	while(left<=right)	
//	{		
//		int middle=(left+right)/2;		
//		if(x<p[middle])		
//		{			
//			right=middle-1;		
//		}		
//		else if(x>p[middle])		
//		{			
//			left=middle+1;		
//		}		
//		else		
//		{			
//			return middle;		
//		}	
//	}	
//	return -1;
//} 
//int main()
//{	
//	int a[11] = { 1, 3, 4, 6, 7, 9, 10, 16, 18, 25, 33 };
//	int y=10;	
//	int ret=BinarySearch(a,y,11);	
//	if(-1==ret)	
//	{		
//		cout<<y<<" 不存在！"<<endl;	
//	}	
//	else	
//	{		
//		cout<<y<<"的下标是： "<<ret<<endl;	
//	}	
//	return 0;
//}
