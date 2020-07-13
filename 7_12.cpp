#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

//转圈打印
void func1(vector<vector<int>> vec,int xx1,int yy1,int xx2,int yy2)
{
	int x1 = xx1;
	int y1 = yy1;
	int x2 = xx2;
	int y2 = yy2;
	
	if (x1 > x2)
	{
		return;
	}

	if (x1 == x2)
	{
		for (int i = y1; i <= y2; ++y1)
		{
			cout << vec[x1][y1];
		}
		return;
	}
	else
	{
		while (y1 != y2)
		{
			cout << vec[x1][y1] << " ";
			y1++;
		}
		y1 = yy1;
		while (x1 != x2)
		{
			cout << vec[x1][y2] << " ";
			x1++;
		}
		x1 = xx1;
		while (y1 != y2)
		{
			cout << vec[x2][y2] << " ";
			y2--;
		}
		y2 = yy2;
		while (x1 != x2)
		{
			cout << vec[x2][y1];
			x2--;
		}
		x2 = xx2;
	}
	func1(vec, ++x1, ++y1, --x2, --y2);
}
//合并两个有序链表
struct Node
{
	int val;
	Node* next;
};


Node* first = nullptr;
Node* func2(Node* l1,Node* l2)
{
	Node* cur = first;
	Node* p1 = l1;
	Node* p2 = l2;
	while (p1 && p2)
	{
		if (first == nullptr && p1->val <= p2->val)
		{
			first = p1;
			cur = p1;
			p1 = p1->next;
			continue;
		}
		else
		{
			first = p2;
			cur = p2;
			p2 = p2->next;
			continue;
		}
		if (p1->val <= p2->val)
		{
			cur->next = p1;
			cur = cur->next;
			p1 = p1->next;
		}
		else
		{
			cur->next = p2;
			cur = cur->next;
			p2 = p2->next;
		}
	}
	if (p1)
	{
		cur->next = p1;
	}
	if (p2)
	{
		cur->next = p2;
	}
}


//在有序矩阵中找一个数字
bool func3(vector<vector<int>> vec,int findval)
{
	//从右上往下找
	int x = 0;
	int y = vec[0].size() - 1;
	int x1 = vec.size() - 1;
	int begin = vec[x][y];

	while ((begin >= vec[0][0]) && (begin <= vec[x1][y]))
	{
		if (findval > begin)
		{
			begin = vec[x + 1][y];
		}
		else if (findval < begin)
		{
			begin = vec[x][y - 1];
		}
		else
		{
			return true;
		}
	}
	return false;
}

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
};

void func4(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	cout << tree->val;
	func4(tree->left);
	func4(tree->right);
}

void func6(TreeNode* tree)
{
	stack<TreeNode*> sta;
	TreeNode* p = tree;
	while (p || !sta.empty())
	{
		while (p)
		{
			cout << sta.top()->val << endl;
			sta.push(p);
			p = p->left;
		}
		if (!sta.empty())
		{
			p = sta.top();
			sta.pop();
			p = p->right;
		}
	}
}

void func7(TreeNode* tree)
{
	stack<TreeNode*> sta;
	TreeNode* p = tree;
	while (p || !sta.empty())
	{
		while (p)
		{
			sta.push(p);
			p = p->left;
		}
		if (!sta.empty())
		{
			cout << sta.top()->val << endl;
			p = sta.top();
			sta.pop();
			p = p->right;
		}
	}
}

void func8(TreeNode* tree)
{
	stack<TreeNode*> sta;
	TreeNode* p = tree;
	TreeNode* r = nullptr;
	while (p || !sta.empty())
	{
		if (p)
		{
			sta.push(p);
			p = p->left;
		}
		else
		{
			p = sta.top();
			if (p->right && p->right != r)
			{
				p = p->right;
			}
			else
			{
				p = sta.top();
				sta.pop();
				cout << p->val << endl;
				r = p;
				p = nullptr;
			}
		}
	}



}



int main()
{

	return 0;
}