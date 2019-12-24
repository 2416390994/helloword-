#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
using namespace std;
struct TreeNode
{
	string title;
	vector<TreeNode*> link;
	vector<vector<string>> vec;
	int i;
	TreeNode(string str)
	{
		title = str;
		link.resize(10, nullptr);
		i = 0;
	}
};
void LIST(TreeNode*& tree)
{
	TreeNode* p = new TreeNode("链表的基本操作");
	p->vec = {
		{ "链表的初始化" },
		{"struct Node" },
		{"{" },
		{"	Node* next;" },
		{"	int val;" },
		{"Node(int number)"},
		{"{"},
		{ "	val = number;" },
		{"}"},
		{"};" },
		{"struct _List" },
		{"{" },
		{"	Node* head;" },
		{"};" },
		{"void Init(List& list)"},
		{"{"},
		{"	assert(!list)"},
		{"	list.head  = nullptr"},
		{"}"},
	};
	TreeNode* cur = new TreeNode("链表的插入");
	cur->vec = {
		{ "//头插" },
		{"void push(List& list,int number)"},
		{"{"},
		{"	Node* p = new Node(number);"},
		{"	if(list.head == nullptr)"},
		{"	{"},
		{"		list.head = p;"},
		{"	}"},
		{"	else"},
		{"	{"},
		{ "		Node* cur = list.head;" },
		{"		list.head = p;"},                      
		{"		p->next = cur;"},                          
		{"	}"},                                  
		{"}"},
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
		{"	node->value = v;"},
		{"	node->next = pos->next;"},
		{"	pos->next = node;"},
		{ "}" },
	};
	p->link[p->i++] = cur;
	cur = new TreeNode("链表的删除");
	cur->vec = {
		{"//头删"},
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
	tree->link[tree->i++]  = p;

}
void TREE(TreeNode*& tree)
{
	TreeNode* p = new TreeNode("二叉树的基本操作");
	p->vec = {
		{"二叉树的结点初始化"},
		{ "typedef struct Node{" },
		{ "	int value;" },
		{ "	struct Node *left;" },
		{ "	struct Node *right;" },
		{ "}" },
		{ "void PreorderTraversal(Node *root)" },
		{"	if (root == NULL){"},
		{ "		return;" },                    
		{ "	}" },
	};
	TreeNode* cur = new TreeNode("二叉树的三种遍历方式");
	cur->vec = {
		{"前序遍历"},
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
class Tree
{
public:
	static void Add(TreeNode*& tree, TreeNode*& p)  //将结点p增加到树tree的结构中
	{
		tree->link[tree->i] = p;
	}

	static void print(TreeNode*& tree)  //遍历操作
	{
		if (!tree->title.empty())
		{
			cout <<"\t\t\t\t"<< tree->title << endl;
			if (!tree->vec.empty())
			{
				for (int j = 0; j < tree->vec.size(); ++j)
				{
					for (int i = 0; i < tree->vec[j].size(); ++i)
						cout <<"\t\t\t\t"<< tree->vec[j][i];
					cout << endl;
				}
			}
			for (int i = 0; i < tree->i; ++i)
			{
				print(tree->link[i]);
			}
		}
	}
};
vector<string>*& menu(TreeNode*& tree)
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
			}
		}
		cout << "\t\t\t" << "0.退出" <<endl;
		cout << "\t\t\t" << "------------------------------------" << endl;

	}
	return vec;
}
int 循环(TreeNode*& tree,vector<string>*& vec)
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
				if (tree->link[i] != nullptr && count++ == a)
				{
					delete tree->link[i];
					tree->link[i] = nullptr;
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









