//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void func()
//{
//	string s;
//	getline(cin, s);
//	int flag1 = 0;
//	int flag2 = 0;
//	int flag3 = 0;
//	int flag4 = 0;
//	int count = 0;
//	string a;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (s[i] != ' ')
//		{
//			count++;
//			if ('a' <= s[i] && s[i] <= 'z')
//				flag1 = 1;
//			else if ('A' <= s[i] && s[i] <= 'Z')
//				flag2 = 1;
//			else if ('0' <= s[i] && s[i] <= '9')
//				flag3 = 1;
//			else
//				flag4 = 1;
//		}
//		else
//		{
//			if ((flag1 == flag2 == flag3 == flag4 == 1) && count >= 8 && count <= 120)
//				cout << 0 << endl;
//			else
//			{
//				if (count < 8 || count > 120)
//					cout << 1 << endl;
//				else
//					cout << 2 << endl;
//			}
//			flag1 = flag2 = flag3 = flag4 = 0;
//			count = 0;
//		}
//	}
//	if ((flag1 == flag2 == flag3 == flag4 == 1) && count >= 8 && count <= 120)
//		cout << 0 << endl;
//	else
//	{
//		if (count < 8 || count > 120)
//			cout << 1 << endl;
//		else
//			cout << 2 << endl;
//	}
//}
//int main()
//{
//
//	func();
//	return 0;
//}
//
//
//
//void func2(string s, vector<vector<char>>& vec, int i, int j)
//{
//	for (int i = i, i <)
//
//}
//
//
//bool func(vector<vector<char>>& vec)
//{
//	string s;
//	cin >> s;
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		for (int j = 0; j < vec[i].size(); ++j)
//		{
//			if (vec[i][j] == s[i])
//			{
//				func2(s, vec, i, j);
//			}
//
//		}
//
//	}
//
//}














#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool func2(string s, vector<vector<char>>& vec, int w, int c)
{

	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int flag4 = 0;
	int x = 0;
	for (int i = w ; i >= 0 && x <= s.size(); --i)
	{
		flag1 = 2;
		if (s[x++] != vec[i][c])
		{
			flag1 = 1;
		}

	}

	x = 0;
	for (int i = w; i < vec.size() && x <= s.size(); ++i)
	{
		flag2 = 2;
		if (s[x++] != vec[i][c])
		{
			flag2 = 1;
		}
	}

	x = 0;
	for (int j = c; j >= 0 && x <= s.size(); --j)
	{
		flag3 = 2;
		if (s[x++] != vec[w][j])
		{
			flag3 = 1;
		}
	}

	x = 0;
	for (int j = c; j < vec[0].size() && x <= s.size(); ++j)
	{
		flag4 = 2;
		if (s[x++] != vec[w][j])
		{
			flag4 = 1;
		}
	}
	if (flag1 != 1 || flag2 != 1 || flag3 != 1|| flag4 != 1)
		return true;
	return false;
}


void func(vector<vector<char>>& vec)
{
	string s;
	cin >> s;
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			if (vec[i][j] == s[0])
			{
				if (func2(s, vec, i, j) == true)
				{
					cout << "true" << endl;
					return;
				}
			}

		}

	}
	cout << "false" << endl;
}

int main()
{
	vector<vector<char>> vec = {
		{ 'A', 'B', 'C', 'E' },
		{ 'S', 'F', 'C', 'S' },
		{ 'A', 'D', 'E', 'E' }
	};
	func(vec);
	return 0;

}


