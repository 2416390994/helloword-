#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
using namespace std;
struct TreeNode
{
	string title;                //文章标题
	vector<TreeNode*> link;   //因为不是二叉树，可能是多叉树，所以用了一个数组来存储，当前节点的子节点   
	vector<vector<string>> vec;   //一个二维字符串数组，用来存储该节点的文章具体内容 
	int i;                  //记录的是当前结点后面挂了几个子节点的个数
	TreeNode(string str)  //构造函数
	{
		title = str;
		link.resize(10, nullptr);
		i = 0;
	}
};
void LIST(TreeNode*& tree)  //链表的基本操作的函数
{
	TreeNode* p = new TreeNode("链表的基本操作");   //构造链表结点下面的结点
	p->vec = {
		{ "链表的初始化" },
		{ "struct Node" },
		{ "{" },
		{ "	Node* next;" },
		{ "	int val;" },
		{ "Node(int number)" },
		{ "{" },
		{ "	val = number;" },
		{ "}" },
		{ "};" },
		{ "struct _List" },
		{ "{" },
		{ "	Node* head;" },
		{ "};" },
		{ "void Init(List& list)" },
		{ "{" },
		{ "	assert(!list)" },
		{ "	list.head  = nullptr" },
		{ "}" },
	};
	TreeNode* cur = new TreeNode("链表的插入");
	cur->vec = {
		{ "//头插" },
		{ "void push(List& list,int number)" },
		{ "{" },
		{ "	Node* p = new Node(number);" },
		{ "	if(list.head == nullptr)" },
		{ "	{" },
		{ "		list.head = p;" },
		{ "	}" },
		{ "	else" },
		{ "	{" },
		{ "		Node* cur = list.head;" },
		{ "		list.head = p;" },
		{ "		p->next = cur;" },
		{ "	}" },
		{ "}" },
		{ "//尾插" },
		{ "void SListPushBash(List& list, int number)" },
		{ "{" },
		{ "	Node *node = new Node(number);" },
		{ "	if (list->first == NULL)" },
		{ "	{" },
		{ "		list->first = node;" },
		{ "		return;" },
		{ "	}" },
		{ "	Node *cur = list->first;" },
		{ "	while(cur->next != NULL)" },
		{ "	{" },
		{ "		cur = cur->next;" },
		{ "	}//只要cur->next为空那么一定是最后一个结点" },
		{ "	cur->next = node;" },
		{ "}" },
		{ "//在指定位置后面做插入" },
		{ "void SListInsertAfter(List& list, Node *pos, int number)" },
		{ "{" },
		{ "	Node *node = new Node(number);" },
		{ "	node->value = v;" },
		{ "	node->next = pos->next;" },
		{ "	pos->next = node;" },
		{ "}" },
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("链表的删除");
	cur->vec = {
		{ "//头删" },
		{ "void toushan(SList *s)" },
		{ "{" },
		{ "	Node *p = s->first->next;" },
		{ "	free(s->first);" },
		{ "	s->first = p;" },
		{ "}" },
		{ "//尾删" },
		{ "void PopBack2(List& list, int number)" },
		{ "{" },
		{ "	if (list->first->next == NULL)" },
		{ "	{" },
		{ "		delete(list->first);" },
		{ "		list->first = NULL;" },
		{ "	}" },
		{ "	else" },
		{ "	{" },
		{ "		Node *p = list->first;" },
		{ "		while (p->next->next != NULL)" },
		{ "			p = p->next;" },
		{ "		delete(p->next);" },
		{ "		p->next = NULL;" },
		{ "	}" },
		{ "}" },
		{ "//指定位置做删除" },
		{ "void SListEraseAfter(List& list, Node *pos)" },
		{ "{" },
		{ "	Node *next = pos->next;" },
		{ "	pos->next = pos->next->next;" },
		{ "	delete(next);" },
		{ "}" },
		{ "//查找" },
		{ "Node *SListFind(List& list, int number)" },
		{ "{" },
		{ "	Node *p;" },
		{ "	for (p = list->first; p != NULL; p = p->next)" },
		{ "	{" },
		{ "		if (p->value = number)" },
		{ "		{" },
		{ "			return p;" },
		{ "		}" },
		{ "	}" },
		{ "	return NULL;" },
		{ "}" },
	};
	p->link[p->i++] = cur;
	tree->link[tree->i++] = p;   //将构造的链表知识点，连接到总的树的结点上

}
void TREE(TreeNode*& tree)  //树的基本操作的函数
{
	TreeNode* p = new TreeNode("二叉树的基本操作");
	p->vec = {
		{ "二叉树的结点初始化" },
		{ "typedef struct Node{" },
		{ "	int value;" },
		{ "	struct Node *left;" },
		{ "	struct Node *right;" },
		{ "}" },
		{ "void PreorderTraversal(Node *root)" },
		{ "	if (root == NULL){" },
		{ "		return;" },
		{ "	}" },
	};
	TreeNode* cur = new TreeNode("二叉树的三种遍历方式");
	cur->vec = {
		{ "前序遍历" },
		{ "void preorder(struct *root){" },
		{ "	if (root == NULL)" },
		{ "		return;" },
		{ "	printf(\"%d\", root->value); //根" },
		{ "	preorder(root->left); //左子树" },
		{ "	preorder（root->right); //右子树" },
		{ "}" },
		{ "中序遍历" },
		{ "void preorder(struct *root){" },
		{ "	if (root == NULL)" },
		{ "		return;" },
		{ "	preorder(root->left); //左子树" },
		{ "	printf(\"%d\", root->value); //根" },
		{ "	preorder（root->right); //右子树" },
		{ "}" },
		{ "后序遍历" },
		{ "void preorder(struct *root){" },
		{ "	if (root == NULL)" },
		{ "		return;" },
		{ "	preorder(root->left); //左子树" },
		{ "	preorder（root->right); //右子树" },
		{ "	printf(\"%d\", root->value); //根" },
		{ "}" },
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("前序遍历中序遍历还原二叉树");
	cur->vec = {
		{ "struct TreeNode* buildTree(int* preorder, int preordersize, int *inorder, int inordersize)" },
		{ "{" },
		{ "	if (preordersize == 0)" },
		{ "		return nullptr;" },
		{ "	int rootvalue = preorder[0];" },
		{ "	int rindex = -1;" },
		{ "	for (int i = 0; i < inordersize; ++i)" },
		{ "	{" },
		{ "		if (rootvalue == inorder[i])" },
		{ "		{" },
		{ "			rindex = i;" },
		{ "			break;" },
		{ "		}" },
		{ "	}" },
		{ "	TreeNode* root = new TreeNode(rootvalue);" },
		{ "	root->left = buildTree(preorder + 1, preordersize, inorder, inordersize);" },
		{ "	root->right = buildTree(preorder + 1 + rindex, preordersize - 1 - rindex, inorder + rindex + 1, inordersize - rindex - 1);" },
		{ "	return root;" },
		{ "}" },
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("二叉树的层序遍历");
	cur->vec = {
		{ "void func(TreeNode* tree)" },
		{ "{" },
		{ "	if (tree == nullptr)" },
		{ "		return;" },
		{ "	queue<TreeNode*> que;" },
		{ "	que.push(tree);" },
		{ "	while (!que.empty())" },
		{ "	{" },
		{ "		TreeNode* p = que.top();" },
		{ "		que.pop();" },
		{ "		cout << p->val<<" ";" },
		{ "		que.push(p->left);" },
		{ "		que.push(p->right);" },
		{ "	}" },
		{ "}" },
	};
	p->link[p->i++] = cur;
	tree->link[tree->i++] = p;
}


void DRAW(TreeNode*& tree)   //图的概念的函数
{
	TreeNode* p = new TreeNode("图的基本操作");
	p->vec = { 
		{ "无向图" },
		{ "若图中所有顶点Vi到Vj之间的边没有方向，则称这条边为无向图，任意两顶点之间的边用无序偶（Vi，Vj）来表示，" },
		{"无序偶就是表示Vi和Vj之间只有一 条边，且没有方向，（Vi，Vj）== （Vj，Vi）。"}
	};
	TreeNode* cur = new TreeNode("图的概念");
	cur->vec = {
		{ "有向图" },
		{ "若图中所有顶点Vi到Vj的边有方向，则称为有向图，任意两顶点Vi到Vj的边有方向，则称这条边为有向边，也称为弧，"},
		{"用有序偶< Vi, Vj > 表示，表示有一条边从Vi指向Vj，< Vi, Vj > ！ = < Vj, Vi >  ！！！ "}
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("无向完全图");
	cur->vec = {
		{"在无向图中，如果任意两个顶点之间都存在边，则称该图为无向完权图，含有n个顶点的无向完全图有n*(n-1)/2条边。"}
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("有向完全图");
	cur->vec = {
		{ "在有向图中，如果任意两个顶点都存在方向互为相反的两条弧，则称该图为无向完全图，含有n*(n-1)条边。" }
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("稀疏图和稠密图");
	cur->vec = {
		{ "两个是模糊的概念，是相对而言的，通常认为边或弧小于n*logn(n是顶点的个数）的图称之为稀疏图，反之为稠密图。" }
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("带权图");
	cur->vec = {
		{ "有些图的边或弧带有与它相关的值，我们称之为权，带权图称之为网。" }
	};
	p->link[p->i++] = cur;
	tree->link[tree->i++] = p;
}

class Tree    //主树的顶点
{
public:
	static void Add(TreeNode*& tree, TreeNode*& p)  //将结点p增加到树tree的结构中
	{
		tree->link[tree->i] = p;
	}

	static void print(TreeNode*& tree)  //遍历操作,这一步的主要最用就是把，存储到树只的所有的知识点打印出来
	{
		if (!tree->title.empty())
		{
			cout << "\t\t" << tree->title << endl;
			if (!tree->vec.empty())
			{
				for (int j = 0; j < tree->vec.size(); ++j)
				{
					for (int i = 0; i < tree->vec[j].size(); ++i)
						cout << "\t\t" << tree->vec[j][i];
					cout << endl;
				}
			}
			for (int i = 0; i < tree->i; ++i)   //利用了一个尾递归，将当前结点下面挂的所有节点遍历出来
			{
				print(tree->link[i]);
			}
		}
	}
};

vector<string>*& menu(TreeNode*& tree)   //菜单
{
	vector<string>* vec = new vector<string>;
	if (!tree->title.empty())
	{
		cout << "\t\t\t\t" << tree->title << endl;
		cout << "\t\t\t" << "------------------------------------" << endl;
		int j = 1;
		for (int i = 0; i < tree->i; ++i)
		{
			if (tree->link[i] != nullptr)
			{
				cout << "\t\t\t" << j << "." << tree->link[i]->title << endl;
				cout << "\t\t\t" << "------------------------------------" << endl;
				vec->push_back(tree->link[i]->title);
				j++;
			}
		}
		cout << "\t\t\t" << "0.退出" << endl;
		cout << "\t\t\t" << "------------------------------------" << endl;

	}
	return vec;
}
int 循环(TreeNode*& tree, vector<string>*& vec)   //tree就是树的总的结点，vec就是将总树结点下的，所有知识点的题目保存起来，只有有一级标题的下面才有内容，才需要遍历
{
	int a;
	cout << "\t\t\t\t" << "请输入你的选择" << endl;
	cout << "\t\t\t" << "请输入章节序号，对章节进行操作,退出输入0" << endl;
	cin >> a;
	system("cls");
	if (a == 0)
		return -1;
	if (a > vec->size() || a < 1)
		cout << "\t\t\t\t" << "输入错误，请重新输入" << endl;
	else
	{
		cout << "\t\t\t\t" << "请选择你所要进行的操作" << endl;
		int b;
		cout << "\t\t\t\t" << "1.删除该章节" << endl;
		cout << "\t\t\t\t" << "2.查看该章节" << endl;
		cin >> b;
		system("cls");
		if (b == 1)
		{
			int count = 1;
			for (int i = 0; i < tree->i; ++i)
			{
				if (tree->link[i] != nullptr)
				{
					if (count++ == a)
					{
						delete tree->link[i];
						tree->link[i] = nullptr;
					}
				}
			}

			int flag = 0;
			for (int i = 0; i < tree->i; ++i)
			{
				if (tree->link[i] != nullptr)
					flag = 1;
			}
			if (flag == 0)
				return -1;
		}
		else if (b == 2)
		{
			Tree::print(tree->link[a - 1]);
		}
		else
		{
			cout << "\t\t\t\t" << "输入非法,请重新输入" << endl;
		}
	}
}
void test()
{
	TreeNode* tree = new TreeNode("|数据结构知识点总结|");
	LIST(tree);
	TREE(tree);
	DRAW(tree);
	vector<string>* vec;
	vec = menu(tree);
	while (1)
	{
		int ret = 循环(tree, vec);
		menu(tree);
		if (ret == -1)
			break;
	}
}
int main()
{
	test();
	return 0;
}
