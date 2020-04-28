//#include<iostream>
//#include<string>
//using namespace std;
//void func()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int j = s2.size() - 1;
//	int i = s1.size() - 1;
//	while (i >= 0 && j >= 0)
//	{
//		if (s2[j] == s1[i])
//		{
//			--i;
//			--j;
//		}
//		else
//		{
//			--i;
//		}
//	}
//	cout << i + 2 << endl;
//}
//
//
//int main()
//{
//	func();
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void func()
//{
//	vector<int> vec;
//	int bianhao;
//	int n;
//	cin >> bianhao >> n;
//	vec.resize(bianhao);
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		int b;
//		int c;
//		cin >> a >> b >> c;
//
//	}
//
//}
//int main()
//{
//	vector<int> vec;
//	//func();
//	vec.resize(10);
//	for (auto e : vec)
//		cout << e << endl;
//	return 0;
//}



#include<iostream>
#include<string>
#include<vector>
using namespace std;


void func()
{
	vector<int> vec;
	int bianhao;
	int n;
	cin >> bianhao >> n;
	vec.resize(bianhao + 1);
	int xiaohaofali = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		vec[a] = ++vec[a];
		vec[b] = ++vec[b];
		if ((vec[a] > 2) || (vec[b]) > 2)
			continue;
		else
		{
			xiaohaofali += c;
		}
	}
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i] == 0)
		{
			cout << 0 << endl;
			return;
		}
	}
	cout << xiaohaofali << endl;

}

int main()
{
	func();
	return 0;
}












