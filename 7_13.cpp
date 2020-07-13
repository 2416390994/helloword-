#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
};
//�������
void func(TreeNode* tree)
{
	queue<TreeNode*> que;
	if (tree)
	{
		que.push(tree);
	}
	while (!que.empty())
	{
		TreeNode* p = que.front();
		cout << p->val << endl;
		que.pop();
		if (p->left)
			que.push(p->left);
		if (p->right)
			que.push(p->right);
	}
}
//�����������Ҷ�ӽڵ� �ĸ���
int func2(TreeNode* tree)
{
	if (tree)
	{
		return 0;
	}
	if (tree->left == nullptr && tree->right == nullptr)
		return 1;
	int left = func2(tree->left);
	int right = func2(tree->right);
	return left + right;
}

//�������ĸ߶�
int func3(TreeNode* tree)
{
	if (tree == nullptr)
		return 0;
	int left = func3(tree->left);
	int right = func3(tree->right);
	return (left > right ? left : right) + 1;

}

//��������k��ڵ�ĸ���

int func5(TreeNode* tree,int k)
{
	if (tree == nullptr)
		return 0;
	if (k = 1)
		return 1;
	return func5(tree->left, k - 1) + func5(tree->right, k - 1);
}

//�ڶ�����������ĳ���ڵ�
TreeNode* func6(TreeNode* tree,int findval)
{
	if (tree == nullptr)
		return nullptr;
	if (tree->val == findval)
		return tree;
	TreeNode* p1 = func6(tree->left, findval);
	if (p1 != nullptr)
		return p1;
	TreeNode* p2 = func6(tree->right, findval);
	if (p2 != nullptr)
		return p2;
	else
	{
		return nullptr;
	}
}

//4zk5wq




















int main()
{

	return 0;
}