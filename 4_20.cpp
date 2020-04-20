//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
////void func(string s,int size,int from)
////{
////	if (from == size)
////		cout << s << endl;
////	for (int i = from; i < size; ++i)
////	{
////		if (i != from && s[i] == s[from])
////		{
////			continue;
////		}
////		swap(s[i], s[from]);
////		func(s, size, from + 1);
////	}
////}
//
//
////void func2(string s)
////{
////	for (int i = 1; i <= s.size(); ++i)
////	{
////		string w = "";
////		int count = 1;
////		for (int k = 0; k < s.size(); ++k)
////		{
////			w = s[k];
////			for (int j = 1; j < s.size(); ++j)
////			{
////				if (count == i)
////				{
////					cout << w << endl;
////				}
////				else
////				{
////					w += s[j];
////					count++;
////				}
////
////			}
////			count = 1;
////		}
////	}
////		for (int i = 2; i <= s.size(); ++i)
////		{
////			string w = "";
////			int count = 1;
////			for (int k = 0; k < s.size(); ++k)
////			{
////				w = s[k];
////				for (int j = 1; j <= s.size(); ++j)
////				{
////					if (count == i)
////					{
////						cout << w << endl;
////					}
////					else
////					{
////						w += s[j - 1];
////						count++;
////					}
////
////				}
////				count = 1;
////			}
////	}
////}
//
//void func2(string s)
//{
//	//¹éÄÉ³ö´ð°¸
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << endl;
//	}
//	
//	
//	for (int x = 2; x <= s.size(); ++x)
//	{
//		for (int i = 0; i < s.size(); ++i)
//		{
//			string w = "";
//			w += s[i];
//			int count = 1;
//			for (int j = i + 1; j < s.size(); ++j)
//			{
//				w += s[j];
//				count++;
//				if (count == x)
//				{
//					cout << w << endl;
//					count = 1;
//					w = s[i];
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	string s = "abcd";
//	func2(s);
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
void func()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<vector<int>> vec;
	vec.resize(a);
	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i].resize(b);
	}
	int x = 1;
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			vec[i][j] = x++;
		}
	}

	if (c > a || d > b)
		cout << 0 << endl;
	int count = 0;
	for (int i = c - 1; i < a; ++i)
	{
		for (int j = d - 1; j < b; ++j)
		{                              //13,14,15,18,19,20
			count += vec[i][j];
		}
	}
	cout << count << endl;
}
int main()
{

	cout << -INT_MAX -1 << endl;
	func();
	return 0;
}


















