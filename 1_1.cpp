#include<iostream>
#include<vector>
using namespace std;
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//class Solution {
//public:
//	vector<int>& pand(TreeNode* tree, vector<int>& vec1)
//	{
//		vec1.push_back(tree->val);
//		if (expectNumber == 0)
//		if (tree->left == nullptr && tree->right == nullptr)
//			return vec1;
//		else if (expectNumber < 0)
//		{
//			vec1.clear();
//			return vec1;
//		}
//		else
//		{
//			pand(tree->left,vec1);
//			pand(tree->right,vec1);
//		}
//	}
//	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
//		vector<int> vec1;
//		vec1.push_back(root->val);
//		pand(root->left, vec1);
//	}
//};
//
//
//class Solution {
//public:
//	vector<vector<int>> res;
//	vector<int> path;
//	void find(TreeNode* root, int sum)
//	{
//		if (root == NULL)return;
//		path.push_back(root->val);
//		if (!root->left && !root->right && sum == root->val)
//			res.push_back(path);
//		else
//		{
//			if (root->left)
//				find(root->left, sum - root->val);
//			if (root->right)
//				find(root->right, sum - root->val);
//		}
//		path.pop_back();
//	}
//	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
//		find(root, expectNumber);
//		return res;
//	}
//};

int main()
{
	vector<vector<int>> vec1;
	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	vec2.push_back(4);
	vec1.push_back(vec2);
	vec2.clear();
	cout << vec1[0][0] << endl;
	return 0;
}