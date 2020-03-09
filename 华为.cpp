#include<iostream>
#include<string>
#include<math.h>
using namespace std;
bool func(int num)
{
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int s;
	while (cin >> s)
	{
		if (s == 0)
		{
			cout << "end" << endl;
			break;
		}
		int count = 0;
		for (int i = 2; i <= (s + 1) / 2; ++i)
		{
			int a = i;
			int b = s - i;
			if (func(a) && func(b) == 1)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

//int main()
//{
//	double a;
//	char b;
//	double c;
//	cin >> a;
//	cin >> b;
//	cin >> c;
//
//
//	if (b == '+')
//	{
//		double s = a + c;
//		int p = s * 10;
//		if ((p % 10) > 0)
//			cout << s << endl;
//		else
//			cout << (int)s << endl;
//	}
//	else if (b == '-')
//	{
//		double s = a - c;
//		int p = s * 10;
//		if ((p % 10) > 0)
//			cout << s << endl;
//		else
//			cout << (int)s << endl;
//	}
//	else if (b == '*')
//	{
//		double s = a * c;
//		int p = s * 10;
//		if ((p % 10) > 0)
//			cout << s << endl;
//		else
//			cout << (int)s << endl;
//	}
//	else
//	{
//
//		double s = a / c;
//		int p = s * 10;
//		if ((p % 10) > 0)
//			cout << s << endl;
//		else
//			cout << (int)s << endl;
//	}
//	return 0;
//}