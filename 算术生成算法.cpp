#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
using namespace std;
void test01()
{
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 2);
	}
	fill(v2.begin(), v2.end(), 0);        //������������˼����begin()��end()�����������ֱ��ĳ�1000
	for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
}
int main()
{
	test01();
	return 0;
}