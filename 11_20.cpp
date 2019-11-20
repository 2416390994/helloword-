//#include<iostream>
//using namespace std;
//void func(const int& a, const int&b)
//{
//	cout << a << endl;
//	cout << b << endl;
//}
//int main()
//{
//	/*int n[][3] = { 10, 20, 30, 40, 50, 60 };
//	int(*p)[3];
//	p = n;
//	cout << p << endl;
//	cout << p<< endl;
//	cout << p + 1 << endl;
//	cout << n << endl;
//	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2] << endl;*/
//
//	int i = 0;
//	func(++i,i++);
//	cout << i << endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace  std;
//int main()
//{
//	vector<string> vec;
//	string str;
//	while (getline(cin, str))
//	{
//		string s1;
//		string s2;
//		for (int i = 0; i < str.size(); ++i)
//		{
//			if (str[i] == '"')
//			{
//				++i;
//				while (str[i] != '"' && i< str.size())
//				{
//					s2 += str[i];
//					i++;
//				}
//
//			}
//			else
//			{
//				while (str[i] != ' ' && i< str.size())
//				{
//					s1 += str[i];
//					++i;
//				}
//				if (!s1.empty())
//					vec.push_back(s1);
//				if (!s2.empty())
//					vec.push_back(s2);
//				s1.clear();
//				s2.clear();
//			}
//		}
//		cout << vec.size() << endl;
//		for (int i = 0; i< vec.size(); ++i)
//		{
//			cout << vec[i] << endl;
//		}
//		str.clear();
//		vec.clear();
//	}
//	return 0;
//}
#include<iostream>
#include<math.h>
using namespace std;
bool test(int N)
{
	int flag = 0;
	for (int i = 2; i <= sqrt(N); ++i)
	{
		if (N % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return false;
	else
		return true;
}
int main()
{
	int N;
	int M;
	int count = 0;
	int flag = 0;
	while (cin >> N >> M)
	{
		int i = 2;
		while ((M != N) && i < N)
		{
			if (N%i == 0)
			{
				N = N + (N / i);
				++count;
				i = 2;
			}
			else
				++i;
			if (test(N) == true)
			{
				flag = 1;
				break;
			}
			if (N >= M)
				break;
		}
		if (flag == 0)
			cout << count << endl;
		else
			cout << -1 << endl;
		count = 0;
		flag = 0;
	}
	return 0;
}