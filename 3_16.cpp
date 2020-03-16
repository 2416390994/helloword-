#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//字符串去空格
void func(string& s)
{
	int front = 0;
	int end = 0;
	while (front < s.size() && s[front] != ' ')
	{
		front++;
	}
	end = front;
	while (end < s.size() && s[end] == ' ')
	{
		end++;
	}
	s[front] = s[end];
	front++;
	end++;
	while (end < s.size())
	{
		if (s[end] == ' ')
		{
			end++;
		}
		else
		{
			s[front] = s[end];
			front++;
			end++;
		}
	}
	s = s.substr(0,front);
}
struct Node
{
	int val;
	Node* next;
};

//链表判断是否带环
bool panduanlianbiaoshifoudaihuan(Node* list,Node* s)
{
	Node* p1 = list;
	Node* p2 = list;
	while (p2 && p2->next)
	{
		p2 = p2->next;
		p1 = p1->next;
		if (p2->next)
			p2 = p2->next;

		if (p2 == p1)
		{
			s = p1;
			return true;
		}
	}
	return false;
}

Node* panduanhuanderukoudizhi(Node* list)
{
	if (list == nullptr)
		return nullptr;
	Node* w = nullptr;
	bool ret = panduanlianbiaoshifoudaihuan(list,w);
	if (ret)
	{
		Node* p = list;
		while (p != w)
		{
			p = p->next;
			w = w->next;
		}
		return p;
	}
	else
		return nullptr;
}

//单链表的反转
Node* danlianbaiodefanzhuan(Node* list)
{
	if (list == nullptr || list->next == nullptr)
		return list;
	Node* p = danlianbaiodefanzhuan(list->next);
	list->next->next = list;
	list->next = nullptr;
	return p;
}
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};


//二叉搜索树转换为双向链表
TreeNode* first = nullptr;
TreeNode* prv = nullptr;
TreeNode* zhuanhuanweishuangxianglianbiao(TreeNode* list)
{	
	if (list == nullptr)
		return nullptr;
	if (first == nullptr)
	{
		list->left = first;
		first = list;
	}
	else
	{
		list->left = prv;
		prv->right = list;
	}
	prv = list;
}
TreeNode* erchasousuoshuzhuanhuanweishuangxianglianbiao(TreeNode* list)
{
	if (list == nullptr)
		return nullptr;
	erchasousuoshuzhuanhuanweishuangxianglianbiao(list->left);
	zhuanhuanweishuangxianglianbiao(list);
	erchasousuoshuzhuanhuanweishuangxianglianbiao(list->right);
}


//知道孩子结点如何求双亲

TreeNode* zhidaohaizijiedianqiushuangqin(TreeNode* tree, TreeNode* p)
{
	if (tree == nullptr || p == nullptr || p == tree)
		return nullptr;
	if (tree->left == p || tree->right == p)
		return tree;
	TreeNode* p1 = zhidaohaizijiedianqiushuangqin(tree->left, p);
	if (p1)
		return p1;
	TreeNode* p2 = zhidaohaizijiedianqiushuangqin(tree->right, p);
	return p2;
}

void helanguoqi(vector<int>& vec)
{
	int L = 0;
	int less = L - 1;
	int R = vec.size();
	while (L < R)
	{
		if (vec[L] < 2)
		{
			swap(vec[++less], vec[L++]);
		}
		if (vec[L] >= 2)
		{
			swap(vec[--R], vec[L]);
		}
	}
}

//层序遍历

void cengxubianli(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	queue<TreeNode*> que;
	que.push(tree);
	TreeNode* p;
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (p->left)
			que.push(p->left);
		if (p->right)
			que.push(p->right);
		cout << p->val << endl;
	}
}

//非递归前序遍历

void qianxubianli(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	stack<TreeNode*> sta;
	TreeNode* p = tree;
	while (p || !sta.empty())
	{
		while (p)
		{
			sta.push(p);
			cout << p->val << endl;
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


//非递归中序遍历

void zhongxubianli(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	stack<TreeNode*> sta;
	TreeNode* p = tree;
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


void feidiguihouxubianli(TreeNode* tree)
{
	stack<TreeNode*> sta;
	TreeNode* p = tree;
	TreeNode* r = nullptr;
	while (p || !sta.empty())
	{
		if (p)
		{
			sta.push(p);
			p = p->left;
		}
		else
		{
			p = sta.top();
			if (p->right && p->right != r)
			{
				p = p->right;
			}
			else
			{
				sta.pop();
				cout << p << endl;
				r = p;
				p = nullptr;
			}
		}

	}
}

class xunhuanduilie
{
public:
	xunhuanduilie(int num)
		:_que(new int[num])
		,_size(0)
		, _count(num)
		, _front(0)
		, _back(0)
	{}

	void pop()
	{
		if (_size == 0)
		{
			cout << "已空无法弹出" << endl;
			return;
		}
		_size--;
		_front = (_front + 1) % _count;

	}
	int front()
	{
		if (_size == 0)
			return -1;
		return _que[_front];
	}
	int back()
	{
	
	}


	void push(int val)
	{
		if (_size == _count)
		{
			cout << "队列已满" << endl;
			return;
		}
		_que[_back] = val;
		_size++;
		_back = (_back + 1) % _count;
	}

	int capacity()
	{
		return  _count;
	}


private:
	int*  _que;
	int _size;
	int _count;
	int _front;
	int _back;
};

//判断两个二叉树是否相等
bool panduanlianggeerchashushifouxiangdeng(TreeNode* p1,TreeNode* p2)
{
	if (p1 == nullptr && p2 == nullptr)
		return true;
	if (p1 == nullptr || p2 == nullptr)
		return false;
	return p1->val == p2->val && panduanlianggeerchashushifouxiangdeng(p1->left, p2->left) && panduanlianggeerchashushifouxiangdeng(p1->right, p2->right);
}

//字符串的全排列

void zifuchuandequanpailie(string s,int begin,int end)
{
	if (begin == end)
	{
		cout << s << endl;
		return;
	}
	for (int i = begin; i < s.size(); ++i)
	{
		swap(s[i], s[begin]);
		zifuchuandequanpailie(s, begin + 1, end);
		swap(s[i], s[begin]);
	}
}

//对称二叉树

bool panduanlianggeerchashushifouduicheng(TreeNode* p1,TreeNode* p2)
{
	if (p1 == nullptr && p2 == nullptr)
		return true;
	if (p1 == nullptr || p2 == nullptr)
		return false;

	return p1->val == p2->val && panduanlianggeerchashushifouduicheng(p1->left, p2->right) && panduanlianggeerchashushifouduicheng(p1->right, p2->left);
}


int erchashudeyezijiedian(TreeNode* tree)
{
	if (tree == nullptr)
		return 0;
	if (tree->left == nullptr && tree->right == nullptr)
		return 1;
	return erchashudeyezijiedian(tree->left) + erchashudeyezijiedian(tree->right);
}

//

void panduandiannaoshidaduanhaishixiaoduan()
{
	int a = 1;
	char* b = (char*)&a;
	cout << (int)*(b + 1) << endl;
}







int main()
{
	//string s = "hello wo rld";
	//func(s);
	//cout << s << endl;
	/*vector<int> vec{ 1, 2, 1, 2, 1, 2, 2, 2, 1, 1, 2 };
	helanguoqi(vec);*/
	panduandiannaoshidaduanhaishixiaoduan();

	/*for (auto e : vec)
		cout << e << endl;*/
	
	return 0;
}