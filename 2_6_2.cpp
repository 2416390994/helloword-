#include<iostream>
using namespace std;
//int func()
//{
//	return 0;
//}
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48    数组名   代表首元素的地址，在sizeof中数组名代表整个数组元素，这里就是整个数组元素 
//	printf("%d\n", sizeof(a[0][0]));//4，  a[0][0]的值 
//	printf("%d\n", sizeof(a[0]));//16       一维数组名   代表第0行的元素 
//	printf("%d\n", sizeof(a[0] + 1));//4           .a[0][1]的地址 
//	printf("%d\n", sizeof(a + 1));//4.          第2行的地址 
//	printf("%d\n", sizeof(&a[0] + 1));//4     第2行的地址 
//	printf("%d\n", sizeof(*a));//16.      a代表数组首元素的地址，即第一行的地址，这里的值为第一行的元素大小 
//	printf("%d\n", sizeof(a[3]));//16 
//	return 0;
//}

int x;
int y;
int addtwonum()
{
	// 函数内声明变量 x 和 y 为外部变量
	//extern int x;
	//extern int y;
	//int x;
	//int y;
	// 给外部变量（全局变量）x 和 y 赋值
	x = 1;
	y = 2;
	cout << x << endl;
	cout << y << endl;
	return x + y;
}

int main()
{
	
	int result;
	// 调用函数 addtwonum
	result = addtwonum();
	cout << ::x << endl;
	cout << ::y << endl;
	printf("result 为: %d", result);
	return 0;
}

