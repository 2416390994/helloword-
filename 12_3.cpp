//布隆过滤器和一致性哈希
//布隆过滤器就是爬虫项目，和黑名单项目的常见结构
//查询某一个结构是否存在于某一个集合之中
#include<iostream>
#include<vector>
using namespace std;
void jiandui(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		int j = i;
		while (vec[j] > vec[(j - 1) / 2])
		{
			swap(vec[j], vec[(j - 1) / 2]);
			j = (j - 1)/2;
		}
	}
}
void paixu(vector<int>& vec)
{
	int size = vec.size();
	while (size > 0)
	{
		swap(vec[0], vec[--size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int large = (left + 1) < size && vec[left + 1] > vec[left] ? left + 1 : left;
			large = vec[large] > vec[index] ? large : index;
			if (large == index)
				break;
			swap(vec[index], vec[large]);
			index = large;
			left = index * 2 + 1;
		}
	}
}
void test(vector<int>& vec)
{
	jiandui(vec);
	paixu(vec);
}
int main()
{
	vector<int> vec = { 10, 5, 6, 1, 4, 9, 7, 8, 3, 0 ,2};
	test(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	return 0;
}