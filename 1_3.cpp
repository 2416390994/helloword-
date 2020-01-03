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
		if (string[i] == 'E' || string[i] == 'e') //����E/e���ŵĴ���
		{
			if (i == strlen(string) - 1) //���E/e���治�������֣�ֱ�ӷ��ش���
			{
				return false;
			}
			if (fuhao_E)  //����ǵڶ��γ���E/eֱ�ӷ��ش���
			{
				return false;
			}
			fuhao_E = true;
		}
		//+-�ŵ�����
		else if (string[i] == '+' || string[i] == '-')
		{
			//�ڶ��γ��������ţ�ǰ������e/E���򱨴�
			if (zhengfuhao && string[i - 1] != 'e' && string[i - 1] != 'E')
			{
				return false;
			}
			//����+-�Ų����ڵ�һ���ַ����֣����ǵ�һ�γ���+-����ô����ǰ��һ��Ҫ��e/E
			else if (!zhengfuhao && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E')
			{
				return false;
			}
			zhengfuhao = true;
		}
		else if (string[i] == '.')
		{
			if (fuhao_E || xiaoshudian)  //E/e���治�ܳ���С���㣬���Ե�E�Ѿ����ڵ�ʱ���ٳ���С���㣬����С�����Ѿ����ڵ�ʱ���ٳ���С���㷵�ش���
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
		if (pNode->right != nullptr)  //Ҫ�������������һ�����϶��ǣ�����������
		{
			p = pNode->right;
			while (p->left)
			{
				p = p->left;
			}
			return p;
		}
		//������һ���Ļ���˵�����ýڵ��������Ϊ��
		//������Ϊ�յĻ�����ô�ý�������������һ���ڵ��һ�������Ƚڵ�
		//����������Ƚڵ�����Ҫ��ģ����Ǹýڵ���������Ƚڵ������������Ľ��
		p = pNode;
		while (p->next != nullptr && p->next->right == p)
		{
			p = p->next;
		}
		return p->next;
	}
};