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

/*�����ʵ������������������Ӽ��ĸ���
*Ҫ��֤����������ʹ��ڻ����������һ������1
*�����������Ƚ������������У�Ȼ��ѭ����ȡ��������жϣ�
*	��1��Ϊ��������Ͻ����ж�
*	����ʹ��ڻ�������1λ�����жϣ�
*	ֱ������������ʱ������ѭ�����ٻ��˵���ǰλ(��ʱcount��+1)���滻��ǰλ�ĺ��룬�����ж������
*	������ͬ�ĺ��룬ֱ�����������ظ����*/
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

