#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
		v2.push_back(i+2);
	}
	vector<int>v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(),v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), [](int val){cout << val<<" " ; });
}
void test02()
{
	vector<int>v;
	v.push_back(5);
	v.push_back(9);
	v.push_back(2);
	v.push_back(11);
	v.push_back(6);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
	cout << endl;
	sort(v.begin(), v.end(),greater<int>());      //使用内建函数调用大于排序规则
	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
}
void test03()
{
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 2);
	}
	random_shuffle(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
}
void test04()
{
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 2);
	}
	reverse(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
}
int main()
{
	test04();
	return 0;
}