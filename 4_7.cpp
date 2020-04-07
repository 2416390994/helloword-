#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	vector<int> vec1;
	vector<vector<int>> vec2;

	void find(TreeNode* root, int sum)
	{
		if (root == nullptr)
			return;
		vec1.push_back(root->val);
		if (!root->left && !root->right && sum == root->val)
			vec2.push_back(vec1);
		else
		{
			if (root->left)
				find(root->left, sum - root->val);
			if (root->right)
				find(root->right, sum - root->val);
		}
		vec1.pop_back();
	}

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		find(root, expectNumber);
		return vec2;
	}
};

bool VerifySquenceOfBST(vector<int> sequence) {
	size_t size = sequence.size();
	int number = sequence.back();
	for (int i = 0; i < size; ++i)
	{
		if (sequence[i] < number)
		{
			i++;
		}
		else if (sequence[i] >= number)
		{
			i++;
		}
		else
		{
			return false;
		}
	}
	return true;
}



int main()
{


	vector<int> vec{ 4, 8, 6, 12, 16, 14, 10 };
	VerifySquenceOfBST(vec);
	return 0;
}