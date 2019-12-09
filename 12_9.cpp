#include<stdio.h>
//#include<iostream>
//#include<vector>
//using namespace std;
//int LastRemaining_Solution(int n, int m)
//{
//	if (n < 1)
//		return -1;
//	vector<int> vec;
//	vec.resize(n);
//	int size = 0;
//	int count = n;
//	for (int i = 0, j = 0;; ++j)
//	{
//		if (vec[j] != 1)
//		{
//			if (i == m - 1)
//			{
//				vec[j] = 1;
//				count--;
//				i = -1;
//			}
//			++i;
//			if (count == 1)
//			{
//				for (int k = 0; k < vec.size(); ++k)
//				{
//					if (vec[k] == 0)
//					{
//						return k;
//					}
//				}
//			}
//		}
//		if (j == n - 1)
//			j = -1;
//	}
//}
//vector<vector<int> > FindContinuousSequence(int sum) {
//	
//	vector<vector<int>> vec1;
//	if (sum <= 2)
//		return vec1;
//	int count = 0;
//	for (int i = 1; i <= (sum / 2) + 1; ++i)
//	{
//		int j = i;
//		vector<int> vec2;
//		while (count < sum && j <= (sum / 2) + 1)
//		{
//			vec2.push_back(j);
//			count += j;
//			j++;
//		}
//		if (count == sum)
//		{
//			vec1.push_back(vec2);
//		}
//		count = 0;
//	}
//	return vec1;
//}
void func()
{
	int a[10][10] = { 0 };
	for (int i = 0; i < 10; ++i)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int f1(int num, int x)
{
	if (num == 1)
		return 1;
	if (num == 2)
		return x;
	int count = 1;
	for (int i = 0; i < num; ++i)
	{
		count *= x;
	}
	return count;
}
int main()
{
	func();
	/*vector<vector<int>> vec;
	vec = FindContinuousSequence(3);
	for (int i = 0; i < vec.size(); ++i)
	{
	for (int j = 0; j < vec[i].size(); ++j)
	cout << vec[i][j];
	cout << endl;
	}*/
	//cout << LastRemaining_Solution(5, 3) << endl;
	return 0;
}