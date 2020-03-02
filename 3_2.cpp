#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;
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
//前序遍历
void func1(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	TreeNode* p = tree;
	stack<TreeNode*> sta;
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
//中序遍历
void func2(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	TreeNode* p = tree;
	stack<TreeNode*> sta;
	while (p || !sta.empty())
	{
		while (p)
		{
			sta.push(p);
			p = p->left;
		}
		if (!sta.empty())
		{
			p = sta.top();
			cout << p->val << endl;
			sta.pop();
			p = p->right;
		}
	}

}
//后序遍历
void func3(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	TreeNode* p = tree;
	TreeNode* r = nullptr;
	stack<TreeNode*> sta;
	while (p || !sta.empty())
	{
		if (p)
		{
			sta.push(p);
			p = p->left;
		}

		if (sta.empty())
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
//二叉搜索树转链表
class TREE
{
public:
	TreeNode* func4(TreeNode* tree)
	{
		if (tree == nullptr)
			return nullptr;
		func4(tree->left);
		tree->left = prv;
		if (prv)
		{
			prv->right = tree;
		}
		else
		{
			first = tree;
		}
		prv = tree;
		func4(tree->right);
		return first;
	}
private:
	TreeNode* first;
	TreeNode* prv;
};
//二叉树的公共祖先
TreeNode* func5(TreeNode* tree, TreeNode* p, TreeNode* q)
{
	if (tree == nullptr || q == tree || p == tree)
		return tree;
	TreeNode* left = func5(tree->left,p,q);
	TreeNode* right = func5(tree->right,p,q);
	if (left && !right)
		return left;
	else if (!left && right)
		return right;
	else if (!left && !right)
		return nullptr;
	return tree;
}

//二叉树的高度
int func6(TreeNode* tree)
{
	if (tree == nullptr)
		return 0;
	int left = func6(tree->left) + 1;
	int right = func6(tree->right) + 1;
	return left > right ? left : right;
}

//二叉树的岑序遍历
void func7(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	stack<TreeNode*> sta;
	sta.push(tree);
	while (!sta.empty())
	{
		cout << sta.top()->val << endl;
		TreeNode* p = sta.top();
		sta.pop();
		if (p->left)
		{
			sta.push(p->left);
		}
		if (p->right)
		{
			sta.push(p->right);
		}
	}
}

//二叉树的叶子结点的个数
int func8(TreeNode* tree)
{
	if (tree == nullptr)
		return 0;
	if (tree->left == nullptr && tree->right == nullptr)
		return 1;
	return func8(tree->left) + func8(tree->right);
}
//求一棵二叉树是否是对称二叉树
bool func10(TreeNode* p,TreeNode* q)
{
	if (p == nullptr || q == nullptr)
		return false;
	if (p == nullptr && q == nullptr)
		return true;
	return p->val == q->val && func10(p->left, q->right) && func10(p->right, q->left);
}

//判断两个二叉树是否相等

bool func11(TreeNode* p, TreeNode* q)
{
	if (p == nullptr || q == nullptr)
		return false;
	if (p == nullptr && q == nullptr)
		return true;
	return p->val == q->val && func10(p->left, q->left) && func10(p->right, q->right);
}

bool func9(TreeNode* tree)
{
	if (tree == nullptr)
		return true;
	return func10(tree->left, tree->right);
}


bool func13(TreeNode* p1,TreeNode* p2)
{
	if (p1 == nullptr && p2 == nullptr)
		return true;
	if (p1 == nullptr || p2 == nullptr)
		return false;
	return p1->val == p2->val && func13(p1->left, p2->left) && func13(p1->right, p2->right);

}

//判断p树是不是tree树的子树
bool func12(TreeNode* tree, TreeNode* p)
{
	
	if (tree->val == p->val && func13(tree, p))
	{
		return true;
	}
	bool left = func12(tree->left,p);
	if (left)
		return true;	
	bool right = func12(tree->right,p);
	return right;
}

//前序遍历和中序遍历还原二叉树
TreeNode* func14(vector<int>& vec1, int begin1, int end1, vector<int>& vec2, int begin2, int end2)
{
	if (begin1 > end1)
		return nullptr;
	if (begin1 == end1)
		return new TreeNode(vec1[begin1]);
	TreeNode* root = new TreeNode(vec1[begin1]);
	int m = 0;
	while (begin2 + m <= end2)
	{
		if (vec1[begin1] == vec2[begin2])
			break;
		m++;
	}
	root->left = func14(vec1, begin1 + 1, begin1 + m, vec2, begin2, begin2 + m - 1);
	root->right = func14(vec1, begin1 + m+ 1, end1, vec2, begin2 + m + 1, end2);
	return root;
}
TreeNode* func13(vector<int>& vec1,vector<int>& vec2)
{
	return 	func14(vec1, 0, vec1.size() - 1, vec2, 0, vec2.size() - 1);
}

//冒泡排序
void func15(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
}

//选择排序
void func16(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size - 1; ++i)
	{
		int max = i;
		for (int j = i; j < size; ++j)
		{
			if (vec[j] > vec[max])
				max = j;
		}
		swap(vec[i], vec[max]);
	}
}

//插入排序
void func17(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j > 0 && vec[j] > vec[j - 1]; --j)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
}

//希尔排序
void func18(vector<int>& vec)
{
	int size = vec.size();
	int ges = vec.size();
	while (ges > 1)
	{
		for (int i = ges; i < size; i += ges)
		{
			for (int j = i; j >0 && vec[j] > vec[j - ges]; j -= ges)
				swap(vec[j], vec[j - ges]);
		}
		ges >>= 1;
	}
}
//堆排序
void func19(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		int j = i;
		while (vec[j] > vec[(j - 1) / 2])
		{
			swap(vec[j], vec[(j - 1) / 2]);
			j = (j - 1) / 2;
		}
	}
	while (--size)
	{
		swap(vec[0], vec[size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int great = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
			great = vec[index] > vec[great] ? index : great;
			if (index == great)
				break;
			swap(vec[index], vec[great]);
			index = left;
			left = index * 2 + 1;
		}
	}
}

//归并排序
void func21(vector<int>& vec,int L,int M,int R)
{
	int* p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = vec[p1] > vec[p2] ? vec[p1++] : vec[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = vec[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = vec[p2++];
	}
	for (int i = 0; i < R - L + 1; ++i)
	{
		vec[L + i] = p[i];
	}
}

void func20(vector<int>& vec,int L,int R)
{
	if (L == R)
		return;
	int M = (R + L) / 2;
	func20(vec, L, M);
	func20(vec, M + 1, R);
	func21(vec, L, M, R);
}









int main()
{
	vector<int> vec{ 7, 8, 9, 4, 5, 6, 1, 2, 3, 0 };
	//func15(vec);
	//func16(vec);
	//func17(vec);
	//func18(vec);
	//func19(vec);
	func20(vec, 0, 9);

	for (auto e : vec)
		cout << e << endl;

	return 0;
}