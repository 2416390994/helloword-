#include<iostream>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
};
struct ret
{
	TreeNode* aa;
	int used;
};
ret test(char* s, int size)
{
	if (size == 0)
	{
		ret res;
		res.used = 0;
		res.aa = nullptr;
		return res;
	}
	char rootvalue = s[0];
	if (rootvalue =='#')
	{
		ret res;
		res.aa = nullptr;
		res.used = 1;
		return res;
	}
	TreeNode* root = new TreeNode;
	ret left = test(s + 1, size - 1);
	ret left = test(s + 1, size - 1);
}

int main()
{
	char* s = "anc#";
	int size = strlen(s);
	test(s,size);
	return 0;
}