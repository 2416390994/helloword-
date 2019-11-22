#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMinimum(int n, vector<int> left, vector<int> right) {
	vector<int> left_ = left;
	vector<int> right_ = right;
	right_ = right;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (left[i] == 0)
			count2 += right[i];
		if (right[i] == 0)
			count1 += left[i];
	}
	count1 = count1 + 1;
	count2 = count2 + 1;
	int min1 = -1;
	int min2 = -1;
	for (int i = 0; i < n; ++i)
	{
		if (left[i] != 0 && right[i] != 0)
		{
			if (min1 == -1)
			{
				min1 = i;
			}
			if (right[i] < right[min1])
				min1 = i;
		}
		if (left[i] != 0 && right[i] != 0)
		{
			if (min2 == -1)
			{
				min2 = i;
			}
			if (left[i] < left[min2])
				min2 = i;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (i != min1)
			count1 += right_[i];
		if (i != min2)
			count2 += left_[i];
	}
	count1 += 1;
	count2 += 1;
	return (count1 > count2 ? count2 : count1);
}
int main()
{
	cout << findMinimum(4, { 0, 7, 1, 6 }, { 1, 5, 0, 6 }) << endl;
	/*int c;
	int count = 0;
	while (cin >> c)
	{
		for (int i = 0; i < 31;++i)
		{
			if ((c & 1) == 1)
			{
				++count;
			}
			c = c >> 1;
		}
		if (c < 0)
			count += 1;
		cout << count << endl;
		count = 0;
	}
	return 0;*/
}