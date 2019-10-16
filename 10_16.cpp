#if 0
#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(nullptr)
		, right(nullptr)
	{}
};
#endif
//判断子树
#if 0
bool _1(TreeNode* p1,TreeNode* p2)
{
	if (p1 == nullptr && p2 == nullptr)
		return true;
	if (p1 == nullptr || p2 == nullptr)
		return false;
	return  p1->val = p2->val && _1(p1->left, p2->left) && _1(p1->right, p2->right);
}
bool _2(TreeNode* Tree,TreeNode* Child)   
{
	if (Tree == nullptr)
		return false;
	if (Tree->val == Child->val && _1(Tree, Child))
		return true;
	bool left = _2(Tree->left, Child);
	if (left == true)
		return true;
	bool right = _2(Tree->left, Child);
	return right;
}
bool _3(TreeNode* tree,TreeNode* Child)  //总操作
{
	bool ret = _2(tree, Child);
	return ret;
}

//最大深度
int _4(TreeNode* tree)
{
	if (tree == nullptr)
		return 0;
	int left = _4(tree->left);
	int right = _4(tree->right);
	return (left > right ? left : right) + 1;
}

//前序遍历还原二叉树
void _5()
{

}

int main()
{
	return  0;
}
#endif
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class TreeNode
{
public:
	TreeNode* left;
	TreeNode* right;
	char c;
	TreeNode(char x)
		:c(x)
		, left(nullptr)
		, right(nullptr)
	{}
};
typedef struct ret
{
	TreeNode* root; //构建的树的根节点
	int used;  //构建过程中用掉的val个数
}ret;
ret CreateTree(char * s, int size)
{
	if (size == 0)
	{
		ret result;
		result.root = nullptr;
		result.used = 0;
		return result;
	}
	char rootVal = s[0];
	if (rootVal == '#')
	{
		ret result;
		result.root = nullptr;
		result.used = 1;
		return result;
	}
	//根
	TreeNode* tree = new TreeNode(s[0]);
	ret left_result = CreateTree(s + 1, size - 1);
	ret right_result = CreateTree(s + 1 + left_result.used, size - 1 - left_result.used);
	tree->left = left_result.root;
	tree->right = right_result.root;
	ret p;
	p.root = tree;
	p.used = 1 + left_result.used + right_result.used;
	return p;
}
int Length_Tree(TreeNode* tree)   //判断左右树的深度
{
	if (tree == nullptr)
		return 0;
	int left = Length_Tree(tree->left);
	int right = Length_Tree(tree->right);
	return (left >= right ? left : right) + 1;
}
void InorderTraversal(TreeNode* p)
{
	if (p == nullptr)
		return;
	cout << p->c << " " << endl;
	InorderTraversal(p->left);
	
	InorderTraversal(p->right);
}
void Test()
{
	//char *s = "1224##23##4";
	char *s = "1";
	//scanf("%s", s);
	int size = strlen(s);
	ret result = CreateTree(s, size);
	cout << Length_Tree(result.root) << endl;
}
int main()
{
	Test();
	return 0;
}

# if 0 
int _1(TreeNode * tree)
{
	if (tree == nullptr)
		return 0;
	if (tree->left == nullptr && tree->right == nullptr)
		return 1;
	return _1(tree->left) + _1(tree->right);
}
int _1(TreeNode * tree,int& c)
{
	if (tree->left == nullptr && tree->right == nullptr)
		c++;
	_1(tree->left);
	_1(tree->right);
	return c;
}
#endif
#if 0
TreeNode* Find(TreeNode* tree,char x)
{
	if (tree == nullptr)  //特殊情况
		return nullptr;
	if (tree->val == x)   //先找根，根相等则直接返回
		return tree;
	TreeNode* ret = Find(tree->left, x);  //去左子树找
	if (ret != nullptr)   //左子树找到的话就返回
	{
		return ret;
	}
	return Find(tree->right, x);  //不然的话就去右子树找，最后的情况找到没找到都返回的是右子树的返回值
}
#endif
#if 0
#include<queue>
#include<stack>
void _1(TreeNode* tree)
{
	queue<TreeNode*> que;
	if (tree == nullptr)
		return;
	que.push(tree);
	while (!que.empty())
	{
		cout << que.front()->val << endl;
		if (que.front()->left)
		{
			que.push(que.front()->left);
		}
		if (que.front()->right)
		{
			que.push(que.front()->right);
		}
		que.pop();
	}
}
void _1(TreeNode* tree)
{
	queue<TreeNode*> que;
	if (tree == nullptr)
		return;
	que.push(tree);
	while (!que.empty())
	{
		cout << que.front()->val << endl;
		if (que.front()->left)
		{
			que.push(que.front()->left);
		}
		if (que.front()->right)
		{
			que.push(que.front()->right);
		}
		que.pop();
	}
}
#endif
#if 0
#include<stack>

//二叉树的前序遍历，用栈实现
void Preorder(TreeNode* tree)
{
	TreeNode* cur = tree;   //用来遍历整个链表
	TreeNode* last = nullptr;  //记录的是上一个被三次访问结束的结点  
	TreeNode* top = tree;     //用来记录栈的顶端元素
	stack<TreeNode*> sta;
	while (cur != nullptr || sta.empty() != true)
	{
		while (cur != nullptr)
		{
			sta.push(cur);
			//cout<<cur->val<<endl;
			cur = cur->left;
		}
		top = sta.top();
		if (cur->right != nullptr&&top->right != last)   
		{
			//cout<<top->val<<endl;
			cur = top->right;
		}
		else
		{
			last = top;
			sta.pop();
		}
	}
}
#endif