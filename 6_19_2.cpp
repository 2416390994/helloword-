#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int func2(string&& s1,string&& s2)
{
	int length1 = s1.size();
	int length2 = s2.size();
	vector<vector<int>> vec(length1 + 1, vector<int>(length2, 0));
	for (int i = 0; i <= length1; ++i)
		vec[i][0] = i;
	for (int j = 0; j <= length2; ++j)
		vec[0][j] = j;

	for (int i = 1; i <= length1; ++i)
	{
		for (int j = 1; j <= length2; ++j)
		{
			//插入和删除中的最小值
			vec[i][j] = min(vec[i - 1][j], vec[i][j - 1]) + 1;

			//替换和插入删除后的最小值

			if (s1[i - 1] == s2[j - 1])
				vec[i][j] = min(vec[i - 1][j - 1], vec[i][j]);
			else
				vec[i][j] = min(vec[i - 1][j - 1] + 1, vec[i][j]);
		}
	}
	return vec[length1][length2];
}	



int main()
{

	return 0;
}


