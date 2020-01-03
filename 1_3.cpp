#include<iostream>
#include<string>
#include<vector>
using namespace std;
//int Add(int num1, int num2)
//{
//	string str1;
//	str1.insert(str1.begin(),num1,'a');
//	string str2;
//	str2.insert(str2.begin(), num2, 'a');
//	str1.append(str2.begin(), str2.end());
//	return (int)str1.size();
//}
bool isNumeric(char* string)
{
	bool zhengfuhao = false, fuhao_E = false, xiaoshudian = false;
	for (int i = 0; i < strlen(string); ++i)
	{
		if (string[i] == 'E' || string[i] == 'e') //关于E/e符号的处理
		{
			if (i == strlen(string) - 1) //如果E/e后面不再有数字，直接返回错误
			{
				return false;
			}
			if (fuhao_E)  //如果是第二次出现E/e直接返回错误
			{
				return false;
			}
			fuhao_E = true;
		}
		//+-号的问题
		else if (string[i] == '+' || string[i] == '-')
		{
			//第二次出现正负号，前面必须跟e/E否则报错
			if (zhengfuhao && string[i - 1] != 'e' && string[i - 1] != 'E')
			{
				return false;
			}
			//假如+-号不是在第一个字符出现，但是第一次出现+-号那么他的前面一定要是e/E
			else if (!zhengfuhao && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E')
			{
				return false;
			}
			zhengfuhao = true;
		}
		else if (string[i] == '.')
		{
			if (fuhao_E || xiaoshudian)  //E/e后面不能出现小数点，所以当E已经存在的时候再出现小数点，或者小数点已经存在的时候再出现小数点返回错误
			{
				return false;
			}
			xiaoshudian = true;
		}
		else if (string[i] < '0' || string[i] > '9')
			return false;
	}
	return true;
}

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

bool flag = true;
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;
	TreeLinkNode* left = GetNext(pNode->left);
	if (flag == false)
		return left;
	if (left != nullptr)
	{
		flag = false;
	}

	TreeLinkNode* right = GetNext(pNode->right);
	return right;
}
int main()
{
	cout << isNumeric("12e") << endl;
	//cout << Add(10000000, 20000000) << endl;
	return 0;
}

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode* p = nullptr;
		if (pNode->right != nullptr)  //要是中序遍历的下一个结点肯定是，在右子树上
		{
			p = pNode->right;
			while (p->left)
			{
				p = p->left;
			}
			return p;
		}
		//到达这一步的话就说明，该节点的右子树为空
		//右子树为空的话，那么该结点中序遍历的下一个节点就一定在祖先节点
		//但是这个祖先节点是有要求的，就是该节点必须是祖先节点的左子树上面的结点
		p = pNode;
		while (p->next != nullptr && p->next->right == p)
		{
			p = p->next;
		}
		return p->next;
	}
};