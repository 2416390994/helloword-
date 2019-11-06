//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string i;
//	string s;
//	vector<long long> vec;
//	long long res = 0;
//	long long a = 0;
//	long long count = 0;
//	getline(cin, i);
//	getline(cin, s);
//	long long  b = atoi(i.c_str());
//	for (long long i = 0; i < s.size(); ++i)
//	{
//		if (s[i] != ' ')
//		{
//			a = a * 10 + s[i] - '0';
//		}
//		else
//		{
//			vec.push_back(a);
//			a = 0;
//		}
//	}
//	cout << vec.size() << endl;
//	sort(vec.begin(), vec.end());
//	for (int i = vec.size() - 2; count < b; ++count, i = i - 2)
//	{
//		res += vec[i];
//	}
//	cout << res << endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin,s1);
//	getline(cin,s2);
//	char a[300];
//	for (int i = 0; i < s2.size(); ++i)
//	{
//		if (s2[i] != ' ')
//		{
//			if (a[s2[i]] != 1)
//			{
//				a[s2[i]] = 1;
//			}
//		}
//	}
//	string s3;
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		if (a[s1[i]] != 1)
//			s3 += s1[i];
//	}
//	cout << s3 << endl;
//	return 0;
//}
//
