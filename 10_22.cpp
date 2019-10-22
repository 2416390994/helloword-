#include<iostream>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	char val;
	TreeNode(char x)
		:val(x)
		, left(nullptr)
		, right(nullptr)
	{}
};
struct node
{
	TreeNode* ret;
	int used;
};
node _1(char* s,int size)
{
	if (size == 0)
	{
		node res;
		res.used = 0;
		res.ret = nullptr;
		return res;
	}
	char a = s[0];
	if (a == '#')
	{
		node res;
		res.used = 1;
		res.ret = nullptr;
		return res;
	}
	TreeNode* root = new TreeNode(a);
	node left_rest = _1(s + 1, size - 1);
	node right_rest = _1(s + 1+left_rest.used, size - 1-left_rest.used);
	root->left = left_rest.ret;
	root->right = right_rest.ret;
	node res;
	res.ret = root;
	res.used = left_rest.used + right_rest.used + 1;
	return res;
}
void _2(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	cout << tree->val << "->";
	_2(tree->left);
	_2(tree->right);
}
int main()
{
	char* s = "abdf###e##c##";
	int size = strlen(s);
	node res = _1(s, size);
	_2(res.ret);
	return 0;
}

//TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//	int vinlen = vin.size();
//	if (vinlen == 0)
//		return NULL;
//	vector<int> pre_left, pre_right, vin_left, vin_right;
//	//创建根节点，根节点肯定是前序遍历的第一个数
//	TreeNode* head = new TreeNode(pre[0]);
//	//找到中序遍历根节点所在位置,存放于变量gen中
//	int gen = 0;
//	for (int i = 0; i<vinlen; i++){
//		if (vin[i] == pre[0]){
//			gen = i;
//			break;
//		}
//	}
//	//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
//	// 左子树
//	for (int i = 0; i < gen; i++){
//		vin_left.push_back(vin[i]);
//		pre_left.push_back(pre[i + 1]);//先序第一个为根节点
//	}
//	// 右子树
//	for (int i = gen + 1; i < vinlen; i++){
//		vin_right.push_back(vin[i]);
//		pre_right.push_back(pre[i]);
//	}
//	//递归，执行上述步骤，区分子树的左、右子子树，直到叶节点
//	head->left = reConstructBinaryTree(pre_left, vin_left);
//	head->right = reConstructBinaryTree(pre_right, vin_right);
//	return head;
//}
//
//TreeNode* helper(const vector<int>& preorder, int b1, int e1, const vector<int>& inorder, int b2, int e2) {  // 结尾包含e1,e2
//	// M L R    b1, e1
//	// L M R    b2, e2
//	if (b1 > e1) return nullptr;
//	if (b1 == e1) return new TreeNode(preorder[b1]);
//	TreeNode* root = new TreeNode(preorder[b1]);
//	int m = 0; // size of left
//	while (b2 + m <= e2) {
//		if (inorder[b2 + m] == preorder[b1]) break;
//		m++;
//	}
//	root->left = helper(preorder, b1 + 1, b1 + m, inorder, b2, b2 + m - 1);
//	root->right = helper(preorder, b1 + m + 1, e1, inorder, b2 + m + 1, e2);
//	return root;
//}
//root->left = _1(preorder, pre_index + 1, pre_index + m, inorder, ino_index, ino_index + m);
//TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//	if (preorder.empty()) return nullptr;
//	return helper(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
//}

//struct TreeNode* buildTree(int* preorder, int preordersize, int *inorder, int inordersize)
//{
//	if (preordersize == 0)
//		return nullptr;
//	int rootvalue = preorder[0];
//	int rindex = -1;
//	for (int i = 0; i < inordersize; ++i)
//	{
//		if (rootvalue == inorder[i])
//		{
//			rindex = i;
//			break;
//		}
//	}
//	TreeNode* root = new TreeNode(rootvalue);
//	root->left = buildTree(preorder + 1, preordersize, inorder, inordersize);
//	root->right = buildTree(preorder + 1 + rindex, preordersize - 1 - rindex, inorder + rindex + 1, inordersize - rindex - 1);
//	return root;
//}
