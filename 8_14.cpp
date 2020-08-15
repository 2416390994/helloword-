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
//    //最后需要注意的是，最大值不一定是在数组最后的，
//	//因为f数组的每一个位置的数字代表的，是将当前值作为子序列最后一个值的话，最长子序列的长度
//	//所以需要遍历整个数组，找到真正的最大的值
//	for (int i = 1; i <= n; i++)
//		ans = max(ans, f[i]);
//	printf("%d\n", f[n]);
//	return 0;
//}
