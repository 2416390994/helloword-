#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define M 21
#define N 7
void func1()
{
	vector<int> Path(M, 0);
	vector<int> W = {0, 2, 5, 6, 3, 4, 1 };
	vector<int> V = {0, 7, 4, 2, 8, 6, 3 };
	for (int i = 1; i < N; ++i)
	{
		for (int j = M - 1; j >= 1; --j)
		{
			if (W[i] <= j)
				Path[j] = max(Path[j], Path[j - W[i]] + V[i]);
		}
	}
	cout << Path[M - 1] << endl;

}


bool func3(string s,int i,int j)
{
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		++i;
		--j;
	}
	return true;
}
void func2(string&& s)
{
	int length = s.size();
	vector<int> vec;
	for (int i = 0; i <= length ; ++i)
		vec.push_back(i - 1);

	for (int i = 1; i <= length; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (func3(s, j, i - 1))
				vec[i] = min(vec[i], vec[j] + 1);
		}
	}
	cout << vec[length] << endl;
}

int main()
{
	func2("labcbccbcded");
	return 0;
}