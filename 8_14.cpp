#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
//const int maxn = 103;
//int a[maxn], f[maxn];
//
//int main()
//{
//	int n;
//	int ans = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &a[i]);
//		f[i] = 1;
//	}
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j < i; j++)
//			if (a[j] < a[i])
//				f[i] = max(f[i], f[j] + 1);
//
//
//
//    //�����Ҫע����ǣ����ֵ��һ�������������ģ�
//	//��Ϊf�����ÿһ��λ�õ����ִ���ģ��ǽ���ǰֵ��Ϊ���������һ��ֵ�Ļ���������еĳ���
//	//������Ҫ�����������飬�ҵ�����������ֵ
//	for (int i = 1; i <= n; i++)
//		ans = max(ans, f[i]);
//	printf("%d\n", f[n]);
//	return 0;
//}
