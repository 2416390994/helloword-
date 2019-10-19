//class Solution
//{
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		// array是二维数组，这里没做判空操作        
//		int rows = array.size();
//		int cols = array[0].size();
//		int i = rows - 1, j = 0;//左下角元素坐标
//		while (i >= 0 && j<cols){
//			//使其不超出数组范围
//			if (target<array[i][j])
//				i--;
//			//查找的元素较少，往上找
//			else if (target>array[i][j])
//				j++;
//			//查找元素较大，往右找
//			else
//				return true;
//			//找到
//		}
//		return false;
//	}
//};
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
};
void PostordertreaversalNor(TreeNode* tree)
{
	stack<TreeNode*> sta;
	TreeNode* cur = tree;
	TreeNode* last = nullptr;
	TreeNode* top = nullptr;
	while (cur != nullptr || !sta.empty())
	{
		while (cur != nullptr)
		{
			//A前序遍历打印需要加在这里
			sta.push(cur);
			cur = cur->left;
		}
		top = sta.top();
		if (top->right == nullptr)
		{
			//B中序遍历打印需要加在这里和D
			sta.pop();
			last = top;
		}
		else if (top->right == last)//假如是要判断当前节点是从根节点，怎样走到这里的，在这里面可以加入判断然后跳出循环，此时栈中的阶段就是路径
		{
			//C后序遍历打印需要加在这里
			sta.pop();
			last = top;
		}
		//上面是为了方便理解写的版本，也可以直接合并
		/*
			if(top->right ==nullptr || top->right == last)
			{
				sta.pop();
				last = top;
			}
		*/
		else
		{
			//D中序遍历打印需要加在这里和B
			cur = top->right;
		}
	}
}
struct NODE
{
	TreeNode* next;
};
TreeNode* prv = nullptr;
void func(TreeNode* p)
{
	p->left = prv;
	if (prv != nullptr)
	{
		prv->right = p;
	}
	prv = p;
}
TreeNode* inorder(TreeNode* p)
{
	if (p == nullptr)
		return;
	NODE* pp;
	TreeNode * p1;
	TreeNode * p2;
	pp->next = inorder(
		p->left);

	_2(p->right);
}
