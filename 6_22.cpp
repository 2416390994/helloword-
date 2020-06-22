#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
//int pos[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
////grid:提供的矩阵
////row:矩阵有多少行
////col:矩阵有多少列
////visited:标记矩阵
////curx:正在处理的点的横坐标
////cury:正在处理的点的纵坐标
//void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited, int curx, int cury)
//{
//	//标记
//	visited[curx][cury] = 1;
//	//搜索上下左右
//	for (int i = 0; i < 4; ++i)
//	{
//		int nx = curx + pos[i][0];
//		int ny = cury + pos[i][1];
//
//		//判断范围
//		if (nx >= col || nx < 0 || ny >= row || ny < 0)
//			continue;
//
//		//判断是否是陆地，或者已经标记过
//		if (grid[nx][ny] == '1' && visited[nx][ny] == 0)
//			dfs(grid, row, col, visited, nx, ny);
//	}
//}
//
//int func(vector<vector<int>>& grid)
//{
//	if (grid.empty())
//		return 0;
//	int row = grid.size();
//	int col = grid[0].size();
//
//	vector<vector<int>> visited(row, vector<int>(col, 0));
//
//	int number = 0;
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			//判断是否为陆地并且是否访问过,只有没有访问过才可以运行
//			if (grid[i][j] == '1'&& visited[i][j] == 0)
//			{
//				number++;   //我们通过需要++操作来计算到底有几块陆地，每一次++都会将每一块连通的陆地全部标记
//				dfs(grid, row, col, visited, i, j);
//			}
//		}
//	}
//	return number;
//}


//给你一个二维矩阵，用1表示则说明是障碍物，0表示可以走
//给你一个入口的点和出口的点，从入口进入能否到达出口
//可以返回true,不可以返回false

int pos[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
//一个迷宫矩阵，一个起始位置，一个出口位置
//广度优先
bool bfs(vector<vector<int>>& grid,int startx,int starty,int endx,int endy)
{
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> visited(row, vector<int>(col, 0));
	queue<pair<int, int>> q;
	
	//存放起点
	q.push(make_pair(startx, starty));
	visited[startx][starty] = 1;

	while (!q.empty())
	{
		//拿到队头
		pair<int, int> x = q.front();
		q.pop();

		//出口，如果现在这个点是出口的话就说明从入口走到了出口
		if (x.first == endx && x.second == endy)
			return true;

		//遍历上下左右四个点
		for (int i = 0; i < 4; ++i)
		{
			int nx = x.first + pos[i][0];
			int ny = x.second + pos[i][1];

			//对两个点的合理性进行检测
			if (nx < 0 || nx >= row || ny < 0 || ny >= col)
				continue;

			//当前位置可以通过并且没有走过，可以存入新的点
			if (grid[nx][ny] == 0 && visited[nx][ny] == 0)
				q.push(make_pair(nx, ny));
		}
	}
	return false;
}
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

void func(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	vector<vector<int>> vec1;
	queue<TreeNode*> que;
	que.push(tree);
	int count1 = 1;
	int count2 = 0;
	while (!que.empty())
	{
		vector<int> vec2;
		while (count1 > 0)
		{
			TreeNode* cur = que.front();
			que.pop();
			vec2.push_back(cur->val);
			count1--;
			cout << cur->val << endl;
			if (cur->left)
			{
				que.push(cur->left);
				count2++;
			}
			if (cur->right)
			{
				que.push(cur->right);
				count2++;
			}
		}
		vec1.push_back(vec2);
		count2 = count1;
		count2 = 0;
	}

}



int main()
{


	return 0;
}