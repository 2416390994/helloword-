//class Solution
//{
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		// array�Ƕ�ά���飬����û���пղ���        
//		int rows = array.size();
//		int cols = array[0].size();
//		int i = rows - 1, j = 0;//���½�Ԫ������
//		while (i >= 0 && j<cols){
//			//ʹ�䲻�������鷶Χ
//			if (target<array[i][j])
//				i--;
//			//���ҵ�Ԫ�ؽ��٣�������
//			else if (target>array[i][j])
//				j++;
//			//����Ԫ�ؽϴ�������
//			else
//				return true;
//			//�ҵ�
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
			//Aǰ�������ӡ��Ҫ��������
			sta.push(cur);
			cur = cur->left;
		}
		top = sta.top();
		if (top->right == nullptr)
		{
			//B���������ӡ��Ҫ���������D
			sta.pop();
			last = top;
		}
		else if (top->right == last)//������Ҫ�жϵ�ǰ�ڵ��ǴӸ��ڵ㣬�����ߵ�����ģ�����������Լ����ж�Ȼ������ѭ������ʱջ�еĽ׶ξ���·��
		{
			//C���������ӡ��Ҫ��������
			sta.pop();
			last = top;
		}
		//������Ϊ�˷������д�İ汾��Ҳ����ֱ�Ӻϲ�
		/*
			if(top->right ==nullptr || top->right == last)
			{
				sta.pop();
				last = top;
			}
		*/
		else
		{
			//D���������ӡ��Ҫ���������B
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
