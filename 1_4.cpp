#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (root == nullptr)
			return nullptr;
		que.push(root);
		while (!que.empty())
		{
			TreeNode* cur = que.front();
			string s1;
			string s2;
			s1 = ('0' + cur->val % 10);
			cur->val = cur->val / 10;
			s2 += s1;
			while (cur->val % 10 > 0)
			{
				s1 = ('0' + cur->val % 10);
				s2 += s1;
				cur->val = cur->val / 10;
			}
			reverse(s2.begin(),s2.end());
			str += s2;
			str += '!';
			if (cur->left)
				que.push(cur->left);
			else
				str += '#';
			if (cur->right)
				que.push(cur->right);
			else
				str += '#';
			que.pop();
		}
		return (char*)str.c_str();
	}
	TreeNode* Deserialize(char *str) {
		if (str == nullptr)
			return nullptr;

		for (int i = 0; i < strlen(str); ++i)
		{
			int c;
			if (str[i] != '!' && str[i] != '#')
			{
				c = str[i] - '0';
				while (i + 1 < strlen(str) && str[i + 1] != '!' && str[i + 1] != '#')
				{
					c = c * 10 + str[++i] - '0';
				}
				TreeNode* p = new TreeNode(c);
				vec.push_back(p);
			}
			else if (str[i] == '#')
				vec.push_back(nullptr);
		}
		for (int i = 0, j = 0; i < vec.size(); ++i)
		{
			if (vec[i])
			{
				if (vec[j + 1] == nullptr)
				{
					++j;
				}
				else if (j + 1 < vec.size())
				{
					vec[i]->left = vec[++j];
				}
				if (vec[j + 1] == nullptr)
				{
					++j;
				}
				else if (j + 1 < vec.size())
				{
					vec[i]->right = vec[++j];
				}
			}
		}
		return vec[0];
	}
	vector<TreeNode*> vec;
	vector<TreeNode*> vec2;
	queue<TreeNode*> que;
	string str;
};

int main()
{
	TreeNode* p1 = new TreeNode(8);
	TreeNode* p2 = new TreeNode(6);
	TreeNode* p3 = new TreeNode(10);
	TreeNode* p4 = new TreeNode(5);
	TreeNode* p5 = new TreeNode(7);
	TreeNode* p6 = new TreeNode(9);
	TreeNode* p7 = new TreeNode(11);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = p6;
	p3->right = p7;
	p4->left = nullptr;
	p4->right = nullptr;
	p5->left = nullptr;
	p5->right = nullptr;
	p6->left = nullptr;
	p6->right = nullptr;
	p7->left = nullptr;
	p7->right = nullptr;


	Solution A;
	A.Serialize(p1);
	cout << A.str << endl;
	char* p = (char*)A.str.c_str();
	TreeNode* s = A.Deserialize(p);

	for (auto e : A.vec2)
		cout << e << endl;

	queue<TreeNode*> que;
	que.push(s);
	while (!que.empty())
	{
		TreeNode* cur = que.front();
		cout << cur->val;
		if (cur == nullptr)
			cout << '*';
		if (cur->left)
			que.push(cur->left);
		if (cur->right)
			que.push(cur->right);
		que.pop();
	}
	return 0;
}