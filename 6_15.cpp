#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool func1(string s,vector<string>& dict)
{
	int length = s.size();
	vector<bool> vec(length + 1, false);
	vec[0] = true;
	for (int i = 1; i <= length; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (vec[j] && find(dict.begin(), dict.end(),s.substr(j, i - j)) != dict.end())    
			{
				vec[i] = true;
				break;
			}
		}
	}
	return vec[length];
}

int main()
{
	vector<string> vec = {"code"};
	cout<<func1("leetcode", vec);
	return 0;
}