#include<iostream>
#include<vector>
#include<string>
using namespace std;
int func(string&& S, string&& T)
{
	int row = S.size();
	int col = T.size();
	if (row == 0)
		return 0;
	if (col == 0)
		return 1;
	vector<vector<int>> Path(row + 1, vector<int>(col + 1, 0));
	for (int i = 0; i <= row; ++i)
	{
		Path[i][0] = 0;
	}

	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
		{
			if (S[i - 1] == T[j - 1])   //因为字符串的索引是从0开始的
			{
				Path[i][j] = Path[i - 1][j - 1] + Path[i - 1][j];
			}
			else
			{
				Path[i][j] = Path[i - 1][j];
			}
		}
	}
	return Path[row][col];
}


int main()
{

	return 0;
}