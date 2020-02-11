#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int num)
		:left(nullptr)
		, right(nullptr)
		, val(num)
	{}
};
TreeNode* p = nullptr;
void func2(TreeNode* head)
{
	head->left = p;
	if (p != nullptr)
	{
		p->right = head;
	}
	p = head;
}
TreeNode* func1(TreeNode* head)
{
	if (head == nullptr)
		return nullptr;
	func1(head->left);
	func2(head);
	func1(head->right);
}

struct TreeNode* buildTree(int* preorder, int preordersize, int *inorder, int inordersize)
{
	if (preordersize == 0)
		return nullptr;
	int rootvalue = preorder[0];
	int rindex = -1;
	for (int i = 0; i < inordersize; ++i)
	{
		if (rootvalue == inorder[i])
		{
			rindex = i;
			break;
		}
	}
	TreeNode* root = new TreeNode(rootvalue);
	root->left = buildTree(preorder + 1, preordersize, inorder, inordersize);
	root->right = buildTree(preorder + 1 + rindex, preordersize - 1 - rindex, inorder + rindex + 1, inordersize - rindex - 1);
	return root;
}

class Solution {
public:
	TreeNode* helper(const vector<int>& preorder, int pre_index, int end_1, const vector<int>& inorder, int ino_index, int end_2)
	{
		if (pre_index > end_1)
			return nullptr;
		if (pre_index == end_1)
			return new TreeNode(preorder[pre_index]);
		TreeNode* root = new TreeNode(preorder[pre_index]);
		int m = 0;
		while (ino_index + m <= end_2)
		{
			if (inorder[ino_index + m] == preorder[pre_index])
				break;
			m++;
		}
		root->left = helper(preorder, pre_index + 1, pre_index + m, inorder, ino_index, ino_index + m - 1);
		root->right = helper(preorder, pre_index + m + 1, end_1, inorder, ino_index + m + 1, end_2);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return helper(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
	}
};


TreeNode* helper(vector<int>& preorder, int pre_index, int end_1, vector<int>& inorder, int ino_index, int end_2)
{
	if (pre_index > end_1)
		return nullptr;
	if (pre_index == end_1)
		return new TreeNode(preorder[pre_index]);
	TreeNode* root = new TreeNode(preorder[pre_index]);
	int m = 0;
	while (ino_index + m <= end_2)
	{
		if (preorder[pre_index] == inorder[ino_index + m])
			break;
		m++;
	}
	root->left = helper(preorder, pre_index + 1, pre_index + m, inorder, ino_index, ino_index + m - 1);
	root->right = helper(preorder, pre_index + m + 1, end_1, inorder, ino_index + m + 1, end_2);
	return root;
}
TreeNode* buildeTree(vector<int>& preorder, vector<int>& inorder)
{
	return helper(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
}










int main()
{
	TreeNode* A = new TreeNode(1);
	TreeNode* B = new TreeNode(2);
	TreeNode* C = new TreeNode(3);
	TreeNode* D = new TreeNode(4);
	TreeNode* E = new TreeNode(5);
	vector<int> a = { 1, 2, 4, 3, 5 };
	vector<int> b = { 4, 2, 1, 3, 5 };
	Solution s;
	TreeNode* p = buildeTree(a, b);
	cout << p->val << endl;
	cout << p->left->val << endl;
	cout << p->right->val << endl;


	A->left = B;
	A->right = C;
	B->left = D;
	C->right = E;
	return 0;
}