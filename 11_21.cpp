//#include<iostream>
//using namespace std;
//bool RunYear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		return true;
//	else
//		return false;
//}
//int Runmonth(int year, int month)
//{
//	int _month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2)
//	{
//		if (RunYear(year) != false)
//			return _month[2] + 1;
//		else
//			return _month[2];
//	}
//	else
//		return _month[month];
//}
//int iConverDateToDay(int  year, int month, int day)
//{
//	int maxday = 0;
//	for (int i = 1; i < month; ++i)
//	{
//		maxday += Runmonth(year, i);
//	}
//	maxday += day;
//	return maxday;
//}
//int main()
//{
//	int year; int month; int day;
//	while (cin >> year, cin >> month, cin >> day)
//	{
//		if (year > 0 && 1 <= month && month <= 12 && 1 <= day && day <= 31)
//			cout << iConverDateToDay(year, month, day) << endl;
//		else
//			cout << -1 << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;

/*这道题实际上是求符合条件的子集的个数
*要保证正整数号码和大于积，则必须有一个数是1
*所以我们首先将数组升序排列，然后循环读取号码进行判断：
*	以1作为入口向后组合进行判断
*	如果和大于积，向后加1位继续判断，
*	直到不满足条件时，跳出循环，再回退到当前位(此时count已+1)，替换当前位的号码，重新判断新组合
*	对于相同的号码，直接跳过避免重复组合*/
int GetLuckyBag(int x[], int n, int pos, int sum, int mul)
{
	int count = 0;
	for (int i = pos; i < n; ++i)
	{
		sum += x[i];
		mul *= x[i];
		if (sum>mul)
			count += 1 + GetLuckyBag(x, n, i + 1, sum, mul);
		else if (1 == x[i])
			count += GetLuckyBag(x, n, i + 1, sum, mul);
		else
			break;
		sum -= x[i];
		mul /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])
			++i;
	}
	return count;
}

int main()
{
	int n;
	int x[1000] = { 0 };
	while (cin >> n)
	{
		x[1000] = { 0 };
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		sort(x, x + n);
		cout << GetLuckyBag(x, n, 0, 0, 1) << endl;
	}
	return 0;
}

