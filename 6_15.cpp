#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int func1(vector<vector<int>> vec)
{
	vector<vector<int>> MinVec(vec);
	int row = vec.size();
	for (int i = 1; i < row; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0)
			{
				MinVec[i][j] = MinVec[i - 1][j] + vec[i][j];
			}
			else if (j == i)
			{
				MinVec[i][j] = MinVec[i - 1][j - 1] + vec[i][j];
			}
			else
			{
				MinVec[i][j] = min(MinVec[i - 1][j], MinVec[i - 1][j - 1]) + vec[i][j];
			}
		}
	}
	int col = MinVec[row - 1].size();
	int ret = MinVec[row - 1][0];
	for (int i = 0; i < col; ++i)
	{
		ret = min(MinVec[row - 1][i], ret);
	}
	return ret;
}

int func2(vector<vector<int>> vec)
{
	vector<vector<int>> MinVec(vec);
	int row = vec.size();
	for (int i = row - 2; i < row; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			MinVec[i][j] = min(MinVec[i + 1][j], MinVec[i + 1][j + 1]) + vec[i][j];
		}
	}
	return MinVec[0][0];
}

//参数就是这个棋盘的长和宽
void  func3(int row,int col)
{
	vector<vector<int>> vec(row,vector<int>(col,1));   //这里的初始化很有意思
	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
		}
	}
	cout << vec[row - 1][col - 1] << endl;
}

void func4(vector<vector<int>>& vec)
{
	vector<vector<int>> Path(vec);
	int row = vec.size();
	int col = vec[0].size();
	for (int i = 0; i < row; ++i)
	{
		if (vec[i][0] != 1)
			Path[i][0] = 1;
		else
			break;
	}
	
	for (int j = 0; j < col; ++j)
	{
		if (vec[0][j] != 1)
			Path[0][j] = 1;
		else
			break;
	}

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (vec[i][j] == 1)
				continue;
			else if ((vec[i - 1][j] == 1) && (vec[i][j - 1] == 1))
			{
				Path[i][j] = 0;
			}
			else if ( (i - 1 > 0) && vec[i - 1][j] == 1)
			{
				Path[i][j] = Path[i][j - 1];
			}
			else if ((j - 1 > 0) && vec[i][j - 1] == 1)
			{
				Path[i][j] = Path[i - 1][j];
			}
			else
				Path[i][j] = Path[i - 1][j] + Path[i][j - 1];
		}
	}
	cout << Path[row - 1][col - 1] << endl;;
}

void func5(vector<vector<int>>& vec)
{
	int row = vec.size();
	int col = vec[0].size();
	vector<vector<int>> Path(vec);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == 0 && j == 0)
				Path[0][0] = vec[0][0];
			else if (i == 0)
				Path[0][j] = Path[0][j - 1] + vec[0][j];
			else if (j == 0)
				Path[i][0] = Path[i - 1][0] + vec[i][0];
			else
				Path[i][j] = min(Path[i - 1][j], Path[i][j - 1]) + vec[i][j];
		}
	}
	cout << Path[row - 1][col - 1];
}





int main()
{
	//vector<vector<int>> vec = { {1 , 0 } };
	//func4(vec);

	vector<vector<int>> vec = { { 1, 2, 3, 4 }, { 1, 1, 1, 1 }, { 3, 5, 4, 6 } };
	func5(vec);

	
	return 0;
}