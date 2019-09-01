/*
#include<iostream>
using namespace std;
bool check[10];

int main()
{
	int c = 0 % 4;
	cout << c << endl;
	cout << check[1] << endl;
	cout << check[2] << endl;
	cout << check[3] << endl;
	if (!check[1])
	{  
		check[1] = 1;
	}
	cout << check[1] << endl;
	return 0;
}
*/

#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
bool check[10];
vector<int> v ;
void nineBitInteger(int k,long long a)
{   //判断是否可以被位数（k）整除，不可则结束	
	if (k&&a%k != 0)return;	//第9位也符合条件则将数A保存起来	
	if (k == 9)	
	{		
		v.push_back(a);
		return;	
	}	
	//递归过程	
	for (int i = 1; i <= 9; i++)	
	{		
		if (!check[i])		
		{  //检测过则赋值为1			
			check[i] = 1;			
			nineBitInteger(k + 1, a * 10 + i);			
			check[i] = 0;		
		}	
	}
}
void main()
{
	time_t start, stop;//记录时间
	time(&start);
	
	nineBitInteger(0, 0);	
	for (int i = 0; i < v.size();i++)	
	{		
		cout << v[i] << endl;
	}	
	time(&stop);
	printf("一般变量用时: %ld 秒\n", stop - start);
	cout << endl;
}

//#include<iostream>
//#include<time.h>
//using namespace std;
//void test()
//{
//	int *a = new int[9];   //先申请一块内存空间9个位置
//	int flag;   //用来标记是否拥有最后一步判断资格的标志，0代表有1代表没有
//	int i;
//	int num; 
//	int sum;
//	int count;
//	for (i = 123456789; i <= 987654321; ++i)
//	{
//		num = i;    //首先对当前循环的i进行保存
//		flag = 0;   //每次循环的时候将该数的标志位设为0
//		for (int j = 0; j < 9; ++j)   //首先将循环到的数字按十进制数字1，2，3，4，5，6，7，8，9这样的形式写入数组
//		{
//			a[j] = num % 10;
//			num = num / 10;
//		}
//		for (int k = 0; k < 9; ++k)   //然后是判断该数字是否有资格进行下一步的判断
//		{
//			if (a[k] == 0)   //因为要求是123456789，9个数字，因为我们是一个一个加的，所以要是出现0，直接将标志位置1，然后跳出大循环
//			{
//				flag = 1;
//				break;
//			}
//			for (int v = k + 1; v < 9; ++v)  //接着是判断数字是否重复
//			{
//				if (a[k] == a[v])
//				{
//					flag = 1;
//					break;   //这个实现跳出小循环
//				}
//			}
//			if (flag == 1)   //这是是跳出大循环
//			{
//				break;
//			}
//		}
//		if (flag == 0)//这个是最后一步的判断
//		{
//			count = 0;//记录个数
//			sum = a[8];   //先将sum置为第最高位
//			for (int c = 8; c >= 1; --c)//因为循环内部存在一个c-1所以这里到1就可以了，不然会出现访问越界
//			{
//				sum = sum * 10 + a[c - 1];
//				if (sum % (10 - c) == 0)  
//					count++;
//			}
//			if (count == 8)  //如果是8代表符合规定
//			{
//				cout << i << endl;//打印
//			}
//		}
//	}
//}
//int main()
//{
//	time_t start, stop;//记录时间
//	time(&start);
//	test();
//	time(&stop);
//	printf("一般变量用时: %ld 秒\n", stop - start);
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#include<iostream>
//using namespace std;
//void test()
//{
//	int *a = new int[9];
//	int flag;
//	int i;
//	int num;
//	int sum;
//	int count;
//	for (i = 123456789; i <= 987654321; ++i)
//	{
//		num = i;
//		flag = 0;
//		for (int j = 0; j < 9; ++j)
//		{
//			a[j] = num % 10;
//			num = num / 10;
//		}
//		for (int k = 0; k < 9; ++k)
//		{
//			if (a[k] == 0)
//			{
//				flag = 1;
//				break;
//			}
//			for (int v = k + 1; v < 9; ++v)
//			{
//				if (a[k] == a[v])
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 1)
//				break;
//		}
//		if (flag == 0)
//		{
//			count = 0;
//			sum = a[8];
//			for (int c = 8; c >= 1; --c)
//			{
//				sum = sum * 10 + a[c - 1];
//				if (sum % (10 - c) == 0)
//					count++;
//			}
//			if (count == 8)
//			{
//				cout << i << endl;
//			}
//		}
//	}
//	
//}
//int main()
//{
//	test();
//	return 0;
//}
