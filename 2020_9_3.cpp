//#include<iostream>
//#include<vector>
//using namespace std;
//void func()
//{
//	int count;
//	cin >> count;
//	int a, b;
//	cin >> a >> b;
//	vector<int> vec;
//	vec.resize(a + 1);
//	for (int i = 0; i < vec.size(); ++i)
//		vec[i] = 0;
//	for (int i = 0; i < b; ++i)
//	{
//		int l, r;
//		cin >> l >> r;
//		for (int j = l; j <= r; ++j)
//		{
//			vec[j]++;
//		}
//
//	}
//	for (int i = 1; i < vec.size(); ++i)
//	{
//		cout << vec[i] << " ";
//	}
//}
//
//
//
//int main()
//{
//	func();
//
//
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void func()
{
	int count;
	cin >> count;
	while (count--)
	{

		int n, m;
		cin >> n >> m;
		vector<int> vec1;
		vec1.resize(n);
		vector<int> vec2;
		vec2.resize(m);
		for (int i = 0; i < vec1.size(); ++i)
		{
			int num;
			cin >> num;
			vec1[i] = num;
		}
		for (int i = 0; i < vec2.size(); ++i)
		{
			int num;
			cin >> num;
			vec2[i] = num;
		}
		int s = 0;
		for (int i = 0; i < vec1.size(); ++i)
		{
			int flag = 0;
			int jiao = 0;
			int max = 1000000;
			for (int j = 0; j < vec2.size(); ++j)
			{
				if ((vec1[i] < vec2[j]) && (vec2[j] - vec1[i]) < max)
				{
					flag = 1;
					max = vec2[j] - vec1[i];
					jiao = j;
					s++;
					vec2[j] = 0;
				}
			}
			if (flag == 1)
				cout << jiao + 1 << " ";
			else
				cout << -1 << " ";
		}
		cout << endl;
	}
}


int main()
{
	func();


	return 0;
}