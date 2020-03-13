#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

//struct TreeNode
//{
//	TreeNode* left;
//	TreeNode* right;
//	int val;
//};
//
////层序遍历
//void func1(TreeNode* tree)
//{
//	queue<TreeNode*> que;
//	que.push(tree);
//	while (!que.empty())
//	{
//		TreeNode* p = que.front();
//		que.pop();
//		if (p->left)
//			que.push(p->left);
//		if (p->right)
//			que.push(p->right);
//	}
//}
////二叉搜索树转化成有序链表
//TreeNode* first = nullptr;
//
//void func(TreeNode* tree)
//{
//	if (tree == nullptr)
//		return;
//	func(tree->left);
//	if (first == nullptr)
//		first = tree;
//	else
//	{
//		tree->left = first;
//		first = tree;
//	}
//
//	func(tree->right);
//}
//
//struct Node
//{
//	Node* left;
//	Node* right;
//	int val;
//	Node(int _val)
//		:val(_val)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//};
//
//class Solution {
//public:
//	Node* first = nullptr;
//	Node* begin = nullptr;
//	void func(Node* root)
//	{
//		if (root == nullptr)
//			return;
//		func(root->left);
//		if (first == nullptr)
//		{
//			begin = root;
//			first = root;
//		}
//		else
//		{
//			root->left = first;
//			first->right = root;
//			first = root;
//		}
//		func(root->right);
//	}
//
//	Node* treeToDoublyList(Node* root) {
//		if (root == nullptr)
//			return nullptr;
//		func(root);
//		return begin;
//	}
//};
//
//int main()
//{
//	Node* n1 = new Node(1);
//	Node* n2 = new Node(2);
//	Node* n3 = new Node(3);
//	Node* n4 = new Node(4);
//	Node* n5 = new Node(5);
//	
//	n4->left = n2;
//	n2->left = n1;
//	n1->left = nullptr;
//	n1->right = nullptr;
//	n2->right = n3;
//	n3->left = nullptr;
//	n3->right = nullptr;
//	n4->right = n5;
//
//	n5->left = nullptr;
//	n5->right = nullptr;
//
//	Solution s;
//	s.treeToDoublyList(n4);
//	Node* cur = s.begin;
//	while (cur)
//	{
//		cout << cur->val << endl;
//		cur = cur->right;
//	}
//	return 0;
//}

void func(vector<int>& vec)
{
	size_t size = vec.size();
	int sum;
	int count;
	for (int i = 0; i < size; ++i)
	{
		if (i == 0)
		{
			if (vec[0] > 0)
			{
				count = 0;
				sum = 0;
			}
			else
			{
				count = vec[0];
				sum = vec[0];
				continue;
			}
		}
		count += vec[i];
		if (count > sum)
			sum = count;
		if (count <= 0)
			count = 0;
	}
	cout << sum << endl;
}

int main()
{
	vector<int> vec{ 7, -4, -8, 5, -9, 2, 5, 9, 4, -11, -5, -6 };
	func(vec);

	return 0;
}
