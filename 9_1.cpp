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
{   //�ж��Ƿ���Ա�λ����k�����������������	
	if (k&&a%k != 0)return;	//��9λҲ������������A��������	
	if (k == 9)	
	{		
		v.push_back(a);
		return;	
	}	
	//�ݹ����	
	for (int i = 1; i <= 9; i++)	
	{		
		if (!check[i])		
		{  //������ֵΪ1			
			check[i] = 1;			
			nineBitInteger(k + 1, a * 10 + i);			
			check[i] = 0;		
		}	
	}
}
void main()
{
	time_t start, stop;//��¼ʱ��
	time(&start);
	
	nineBitInteger(0, 0);	
	for (int i = 0; i < v.size();i++)	
	{		
		cout << v[i] << endl;
	}	
	time(&stop);
	printf("һ�������ʱ: %ld ��\n", stop - start);
	cout << endl;
}

//#include<iostream>
//#include<time.h>
//using namespace std;
//void test()
//{
//	int *a = new int[9];   //������һ���ڴ�ռ�9��λ��
//	int flag;   //��������Ƿ�ӵ�����һ���ж��ʸ�ı�־��0������1����û��
//	int i;
//	int num; 
//	int sum;
//	int count;
//	for (i = 123456789; i <= 987654321; ++i)
//	{
//		num = i;    //���ȶԵ�ǰѭ����i���б���
//		flag = 0;   //ÿ��ѭ����ʱ�򽫸����ı�־λ��Ϊ0
//		for (int j = 0; j < 9; ++j)   //���Ƚ�ѭ���������ְ�ʮ��������1��2��3��4��5��6��7��8��9��������ʽд������
//		{
//			a[j] = num % 10;
//			num = num / 10;
//		}
//		for (int k = 0; k < 9; ++k)   //Ȼ�����жϸ������Ƿ����ʸ������һ�����ж�
//		{
//			if (a[k] == 0)   //��ΪҪ����123456789��9�����֣���Ϊ������һ��һ���ӵģ�����Ҫ�ǳ���0��ֱ�ӽ���־λ��1��Ȼ��������ѭ��
//			{
//				flag = 1;
//				break;
//			}
//			for (int v = k + 1; v < 9; ++v)  //�������ж������Ƿ��ظ�
//			{
//				if (a[k] == a[v])
//				{
//					flag = 1;
//					break;   //���ʵ������Сѭ��
//				}
//			}
//			if (flag == 1)   //������������ѭ��
//			{
//				break;
//			}
//		}
//		if (flag == 0)//��������һ�����ж�
//		{
//			count = 0;//��¼����
//			sum = a[8];   //�Ƚ�sum��Ϊ�����λ
//			for (int c = 8; c >= 1; --c)//��Ϊѭ���ڲ�����һ��c-1�������ﵽ1�Ϳ����ˣ���Ȼ����ַ���Խ��
//			{
//				sum = sum * 10 + a[c - 1];
//				if (sum % (10 - c) == 0)  
//					count++;
//			}
//			if (count == 8)  //�����8������Ϲ涨
//			{
//				cout << i << endl;//��ӡ
//			}
//		}
//	}
//}
//int main()
//{
//	time_t start, stop;//��¼ʱ��
//	time(&start);
//	test();
//	time(&stop);
//	printf("һ�������ʱ: %ld ��\n", stop - start);
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
