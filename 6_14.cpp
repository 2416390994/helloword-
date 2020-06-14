#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int func(vector<int> vec)
{
	int length = vec.size();
	int* ret = new int[length];

	ret[0] = vec[0];
	for (int i = 1; i < length; ++i)
	{
		ret[i] = max((ret[i - 1] + ret[i]), ret[i]);
	}

	int retmax = ret[0];
	for (int i = 1; i < length; ++i)
	{
		retmax = max(retmax, ret[i]);
	}
	return retmax;
}

int func2(vector<int> vec)
{
	int length = vec.size();
	int max1 = vec[0];
	int max2 = vec[0];
	for (int i = 0; i < length; ++i)
	{
		max1 = max(vec[i - 1] + vec[i], vec[i]);
		max2 = max(max1, max2);
	}
	return max2;
}
















int main()
{



	return 0;
}