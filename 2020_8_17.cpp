#include<iostream>
#include<vector>
using namespace std;
bool func2(vector<vector<int>>& vec, int i, int j, int k)
{
	for (int x = 0; x < k - 1; ++x)
	{
		if ((vec[i][x] + vec[j][x]) != (vec[i][x + 1] + vec[j][x + 1]))
		{
			return false;
		}
	}
	return true;
}

/*
2 11 21
19 10 1
20 11 1
6 15 24
18 27 36
*/

void func()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> vec;
	vec.resize(n);
	for (int i = 0; i < n; ++i)
	{
		vec[i].resize(k);
		int count = 0;
		for (int j = 0; j < k; ++j)
		{
			int c;
			cin >> c;
			vec[i][j] = c;
		}
	}

	int count = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i+ 1; j < n; ++j)
		{
			if (func2(vec, i, j, k))
			{
				count++;
			}

		}

	}

	cout << count << endl;
}

int main()
{
	func();
	return 0;
}


