#include<iostream>
#include<string>
using namespace std;
//int func2(int m, int n)
//{
//	if (m < n)
//		swap(m, n);
//	while (n)
//	{
//		int temp = m %n;
//		m = n;
//		n = temp;
//	}
//	return m;
//}
//
//
//void func()
//{
//	string str;
//	getline(cin, str);
//	int a;
//	int b;
//	int c;
//	int d;
//	char s;
//	a = str[0] - '0';
//	b = str[2] - '0';
//	c = str[6] - '0';
//	d = str[8] - '0';
//	s = str[4];
//
//	int b_1 = b;
//	int d_1 = d;
//	if (b > d)
//	{
//		while (b_1 != d_1)
//		{
//			d_1 += d;
//			if (d_1 > b_1)
//			{
//				b_1 += b;
//			}
//		}
//	}
//	else
//	{
//		while (b_1 != d_1)
//		{
//			b_1 += b;
//			if (b_1 > d_1)
//			{
//				d_1 += d;
//			}
//		}
//	}
//	int x = b_1 / b;
//	int y = d_1 / d;
//	a = (a * x);
//	c = (c * y);
//	int e, f;
//	if (s == '+')
//	{
//		e = a + c;
//		f = b_1;
//	}
//	else if (s == '-')
//	{
//		e = a - c;
//		f = b_1;
//	}
//	else if (s == '*')
//	{
//		e = a * c;
//		f = b_1 * b_1;
//	}
//	else
//	{
//		e = a * d_1;
//		f = b_1 * c;
//	}
//	if (e == 0)
//	{
//		cout << 0 << endl;
//		return;
//	}
//
//	if (f == 1)
//	{
//		cout << e << endl;
//		return;
//	}
//
//	if (e == f)
//	{
//		cout << 1 << endl;
//	}
//	else
//	{
//		int ret = func2(e, f);
//		if (ret > 0)
//		{
//			e /= ret;
//			f /= ret;
//		}
//		cout << e << "/" << f << endl;
//	}
//}

#include<iostream>
#include<vector>
using namespace std;
void func()
{
	int row, col;
	cin >> row >> col;
	vector<vector<int>> vec;
	vec.resize(row);
	for (int i = 0; i < row; ++i)
	{
		vec[i].resize(col);
		for (int j = 0; j < col; ++j)
		{
			int c;
			cin >> c;
			vec[i][j] = c;
		}
	}
	vector<int> vec2;
	vec2.resize(col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (vec[i][j] == 1)
			{
				vec2[j] = 1;
			}
		}
	}

	for (int i = 0; i < col; ++i)
	{
		if (vec2[i] != 1)
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	func();
	return 0;
}


