//#include<iostream>
//#include<string>
////#defind _CRT_SECURE_NO_WARNINGS
//using namespace std;
//#if 0
//int test1(int a)
//{
//	if (a == 1 || a == 2)
//		return 1;
//	return test1(a - 1) + test1(a - 2);
//}
//int test2(int b)
//{
//	int sum = 0;
//	if (b == 0)
//		return 0;
//	sum = test1(b) + test2(b - 1);
//	return sum;
//}
//#endif
//#if 0
//int test1(int a)
//{
//	if (a == 1)
//		return 1;
//	return a * test1(a - 1);
//}
//int test2(int b)
//{
//	int sun = 0;
//	if (b == 0)
//		return 0;
//	cout << test1(b) << endl;
//	sun = test1(b) + test2(b - 1);
//	return sun;
//}
//int main()
//{
//	int ret1 = test1(7);
//	int ret2 = test2(7);
//	cout << ret1 << endl;
//	cout << ret2 << endl;
//	return 0;
//}
//#endif
//
////class Solution {
////public:
////	void replaceSpace(char *str, int length) {
////		int count = 0;
////		for (int i = 0; i<length; i++){
////			if (str[i] == ' ')
////				count++;
////		}
////		for (int i = length-1; i >= 0; i--){
////			if (str[i] != ' '){
////				str[i + 2 * count] = str[i];
////			}
////			else{
////				count--;
////				str[i + 2 * count] = '%';
////				str[i + 2 * count + 1] = '2';
////				str[i + 2 * count + 2] = '0';
////			}
////		}
////		cout << str;
////	}
////};
//class Solution {
//public:
//	void replaceSpace(char *str, int length)
//	{
//		string s(str);
//		int i = 0;
//		while ((i = s.find(' ', i))>-1)
//		{
//			s.erase(i, 1);
//			cout << s;
//			s.insert(i, "%20");
//		}
//		auto ret = s.c_str();
//		strcpy(str, ret);
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	char ss[100] = "hello world let go" ;
//	s.replaceSpace(ss, 18);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//class Solution
//{
//public:
//	void replaceSpace(char *str, int length)
//	{
//		string s(str);
//		int i = 0;
//		while ((i = s.find(' '))>-1)
//		{
//			s.erase(i, 1);   //
//			s.insert(i, "%20");
//		}
//		auto ret = s.c_str();
//		cout << typeid(ret).name() << endl;
//		strcpy(str, ret);
//		cout << str << endl;
//	}
//};
//class Solution {
//public:
//	int Fibonacci(int n) {
//		if (n == 2)
//			return 1;
//		if (n == 1)
//			return 0;
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//};
//int func(int a)
//{
//	if (a == 1)
//		return 0;
//	if (a == 2)
//		return 1;
//	int f1 = 0, f2 = 1,f3 = 0;
//	int c = a - 1;
//	while (c--)
//	{
//		f3 = f1 + f2;
//		f1 = f2;
//		f2 = f3;
//	}
//	return f3;
//}
//
//	int Fibonacci(int n)
//	{
//		int f = 0, g = 1;
//		while (n--)
//		{
//			g += f;
//			f = g - f;
//		}
//		return f;
//	}

//int main()
//{
//	//int ret = func(0);
//	int ret2 = Fibonacci(3);
//	//cout << ret << endl;
//	cout << ret2 << endl;
//	return 0;
//}
#include<vector>

int StrToInt(string str) {
	int len = str.size();
	vector<int> vec;
	for (int i = 1; i < len; ++i)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			vec.push_back(str[i] - '0');
		else
			return 0;
	}
	int sum = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		sum = (sum * 10) + vec[i];
	}
	cout << sum << endl;
	if (str[0] == '+')
		return sum;
	else if (str[0] == '-')
		return -sum;
	else if ((str[0] - '0') >= 0 && (str[0] - '0') <= 9)
	{
		int w = str[0] - '0';
		for (int i = 0; i < vec.size(); ++i)
		{
			w = w * 10;
		}
		return w + sum;
	}
	else
		return 0;
}
int main()
{
	int ret = StrToInt("123");
	cout << ret << endl;
	
		return 0;
}