#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
//int pos[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
////grid:�ṩ�ľ���
////row:�����ж�����
////col:�����ж�����
////visited:��Ǿ���
////curx:���ڴ���ĵ�ĺ�����
////cury:���ڴ���ĵ��������
//void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited, int curx, int cury)
//{
//	//���
//	visited[curx][cury] = 1;
//	//������������
//	for (int i = 0; i < 4; ++i)
//	{
//		int nx = curx + pos[i][0];
//		int ny = cury + pos[i][1];
//
//		//�жϷ�Χ
//		if (nx >= col || nx < 0 || ny >= row || ny < 0)
//			continue;
//
//		//�ж��Ƿ���½�أ������Ѿ���ǹ�
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
//			//�ж��Ƿ�Ϊ½�ز����Ƿ���ʹ�,ֻ��û�з��ʹ��ſ�������
//			if (grid[i][j] == '1'&& visited[i][j] == 0)
//			{
//				number++;   //����ͨ����Ҫ++���������㵽���м���½�أ�ÿһ��++���Ὣÿһ����ͨ��½��ȫ�����
//				dfs(grid, row, col, visited, i, j);
//			}
//		}
//	}
//	return number;
//}


//����һ����ά������1��ʾ��˵�����ϰ��0��ʾ������
//����һ����ڵĵ�ͳ��ڵĵ㣬����ڽ����ܷ񵽴����
//���Է���true,�����Է���false

int pos[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
//һ���Թ�����һ����ʼλ�ã�һ������λ��
//�������
bool bfs(vector<vector<int>>& grid,int startx,int starty,int endx,int endy)
{
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> visited(row, vector<int>(col, 0));
	queue<pair<int, int>> q;
	
	//������
	q.push(make_pair(startx, starty));
	visited[startx][starty] = 1;

	while (!q.empty())
	{
		//�õ���ͷ
		pair<int, int> x = q.front();
		q.pop();

		//���ڣ��������������ǳ��ڵĻ���˵��������ߵ��˳���
		if (x.first == endx && x.second == endy)
			return true;

		//�������������ĸ���
		for (int i = 0; i < 4; ++i)
		{
			int nx = x.first + pos[i][0];
			int ny = x.second + pos[i][1];

			//��������ĺ����Խ��м��
			if (nx < 0 || nx >= row || ny < 0 || ny >= col)
				continue;

			//��ǰλ�ÿ���ͨ������û���߹������Դ����µĵ�
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