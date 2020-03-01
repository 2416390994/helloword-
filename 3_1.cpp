#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct Node
{
	int val;
	Node* next;
	Node(int _val)
		:val(_val)
		, next(nullptr)
	{}
};
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val)
		:val(_val)
		, left(nullptr)
		, right(nullptr)
	{}
};

int func3(TreeNode* tree)
{
	if (tree = nullptr)
		return 0;
	int left = func3(tree->left) + 1;
	int right = func3(tree->right) + 1;
	return left > right ? left : right;
}

void func4(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	stack<TreeNode*> sta;
	TreeNode* p;
	while (p || !sta.empty())
	{
		while (p)
		{
			cout << p->val << endl;
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

void func5(TreeNode* tree)
{
	stack<TreeNode*> sta;
	TreeNode* p1 = tree;
	TreeNode* r = nullptr;
	while (p1 || !sta.empty())
	{
		if (p1)
		{
			sta.push(p1);
			p1 = p1->left;
		}
		else
		{
			p1 = sta.top();
			if (p1->right || p1->right != r)
			{
				p1 = p1->right;
			}
			else
			{
				p1 = sta.top();
				sta.pop();
				r = p1;
				p1 = nullptr;
			}
		}
	}
}






int Fibonacci(int n)
{
	int f = 0, g = 1;
	while (--n)
	{
		g = g + f;
		cout << g << endl;
		f = g - f;
		cout << f << endl;
	}
	return f;
}
void func1()
{
	vector<int> vec;
	auto it = equal_range(vec.begin(), vec.end(), 10);
	int a = it.second - it.first;
}
Node* func2(Node* list)
{
	if (list == nullptr)
		return nullptr;
	Node* p1 = list;
	Node* p2 = list->next; 
	Node* p3 = nullptr;
	Node* p4 = nullptr;
	while (p2 != nullptr)
	{
		if(p2->val != p1->val)
		{
			if (p4 == nullptr)
				p4 = p1;
			p3 = p1;
			p2 = p2->next;
			p1 = p1->next;
			continue;
		}
		while (p2 != nullptr && p2->val == p1->val)
			p2 = p2->next;
		if (p3)
			p3->next = p2;
		else
		{
			p3 = p2;
			p4 = p2;
		}
		p1 = p2;
		if (p2 !=nullptr)
			p2 = p2->next;
		p3 = nullptr;
	}
	return p4;
}
void func5(TreeNode* tree)
{
	stack<TreeNode*> sta;
	TreeNode* p = tree;
	while (p || !sta.empty())
	{
		while(p)
		{
			sta.push(p);
			cout << p->val << endl;
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

void func6(vector<vector<int>> vec,int pos)
{
	int col = vec[0].size();
	int row = vec.size();
	int i = 0;
	int j = col - 1;
	while (i < row && j >= 0)
	{
		if (pos > vec[i][j])
		{
			++i;
		}
		else if (pos < vec[i][j])
		{
			--j;
		}
		else
			return;
	}
}
void func7(TreeNode* tree)
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
class POS
{
	TreeNode* p1 = nullptr;
	TreeNode* p2 = nullptr;

	TreeNode* func2(TreeNode* tree)
	{
		if (tree == nullptr)
			return;
		func2(tree->left);
		tree->left = p2;
		if (p2)
		{
			p2->right = tree;
		}
		else
		{
			p1 = tree;
		}
		p2 = tree;
		func2(tree->right);
	}
	TreeNode* func1(TreeNode* tree)
	{
		if (tree == nullptr)
			return nullptr;
		func2(tree);
		return p2;
	}
};



int main()
{
	Node* p1 = new Node(1);
	Node* p2 = new Node(2);
	Node* p3 = new Node(3);
	Node* p4 = new Node(4);
	Node* p5 = new Node(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	Node* pp = func2(p1);
	//int a = 10;
	//cout << (a & 1) << endl;
	//Fibonacci(10);
	return 0;
}