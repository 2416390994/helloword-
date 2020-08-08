#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//void func()
//{
//	int size;
//	cin >> size;
//	int a;
//	vector<int> vec;
//	vec.resize(size);
//	for (int i = 0; i < size; ++i)
//	{
//		cin >> a;
//		vec.push_back(a);
//	}
//
//	int count = 0;
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		if (vec[i] >= 2)
//		{
//			count += (vec[i] / 2);
//		}
//	}
//	cout << count << endl;
//}
//
//int main()
//{
//	func();
//	return 0;
//}
//bool func2(string str,int l,int r)
//{
//	while (l < r)
//	{
//		if (str[l] == str[r])
//		{
//			l++;
//			r--;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//
//void func1()
//{
//	string str;
//	cin >> str;
//	int size = str.size() - 1;
//	int i;
//	for (i = 0; i < size; ++i)
//	{
//	    bool ret = func2(str, i, size);
//		if (ret == true)
//		{
//			break;
//		}
//	}
//	while (i--)
//	{
//		str.push_back(str[i]);
//	}
//	cout << str << endl;
//}
//
//


//bool func2(long long num)
//{
//	while (num)
//	{
//		if ((num % 10) == 5)
//		{
//			return false;
//		}
//		num /= 10;
//	}
//	return true;
//}
//
//
//void func1()
//{
//	int size;
//	cin >> size;
//	vector<long long> vec;
//	vec.resize(size);
//	long long num;
//	long long count = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		cin >> num;
//		vec[i] = num;
//		count += vec[i];
//	}
//	if (func2(count) == true)
//	{
//		cout << count << endl;
//		return;
//	}
//	else
//	{
//		sort(vec.begin(), vec.end());
//		int j = 0;
//		for (j = 0; j < vec.size(); ++j)
//		{
//			if (func2(count - vec[j]) == true)
//			{
//				cout << count - vec[j] << endl;
//				return;
//			}
//		}
//		cout << 0 << endl;
//		return;
//	}
//}

//void func()
//{
//	int a, b, c, d, e;
//	cin >> a >> b >> c >> d >> e;
//	double count = 0;
//	count = count + (1 * a);
//	count = count + (2 * b);
//	count = count + (3 * c);
//	count = count + (4 * d);
//	count = count + (5 * e);
//
//	double sum = count / (a + b + c + d + e);
//	string s = to_string(sum);
//	double v = 0;
//	int i ;
//	for (i = 0; i < s.size(); ++i)
//	{
//		if (s[i] != '.')
//		{
//			v *= 10;
//			v += (s[i] - '0');
//		}
//		else
//		{
//			break;
//		}
//	}
//	double w = (double)(s[i + 1] - '0') / 10;
//	
//
//	printf("%.1f", v + w);
//}
//

void func()
{
	int count;
	cin >> count;
	int x = 0, y = 0;
	int a, b;
	for (int i = 0; i < count; ++i)
	{
		
		cin >> a >> b;
		if (a >= b)
		{
			x += a;
			y += (a - b);
		}
		else
		{
			x += ((b / a) * a);
		}
	}
	cout << x << " " << y << endl;
}




int main()
{
	//func();
	cout << (5 / 3) * 3 << endl;
	return 0;
}