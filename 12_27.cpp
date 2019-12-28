#include<iostream>
using namespace std;
//template<class	T>
//T* prev == nullptr;
//template<class	T>
////平衡二叉树转双向链表
//void func(T* tree)
//{
//	if (tree == nullptr)
//		return;
//	func(tree->left);
//	tree->left = prev;
//	if (prev)
//		prev->right = tree;
//	prev = tree;
//	func(tree->right);
//}


#if 1
template<class T>  //结点结构
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
	: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
	, _data(data), _bf(0)
	{}
	AVLTreeNode<T>* _pLeft; // 该节点的左孩子
	AVLTreeNode<T>* _pRight; // 该节点的右孩子
	AVLTreeNode<T>* _pParent; // 该节点的双亲
	T _data;
	int _bf; // 该节点的平衡因子
};

//在下面的插入操作中，判断一个结点的平衡因子，我们默认是使用右子树 - 左子树
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	bool Insert(const T& data)
	{
		//AVL树有可能是空树
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//非空
		//先按照二叉搜索树的方式进行插入
		//首先要说的就是，插入的位置觉对是，叶子节点 || 只有左孩子的结点 || 只有右孩子的结点
		//绝对不会在既有左孩子，又有右孩子的结点进行插入
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;   //保存待插入结点的双亲结点
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;  //这里的意思就是假如要插入的值树中已存在那么久直接返回，默认树中插得值都是不一样的
		}
		//插入新结点
		pCur = new Node(data);  //先创建结点
		if (data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		pCur->_pParent = pParent; //确定双亲
		//每次插入新节点之后，双亲结点的平衡因子一定会发生改变

		//更新双亲的平衡因子
		while ()
		{
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
			//由于AVL树的平衡因子本身就只有三种可能0， -1 ， 1
			//插入新节点之前
			//0 ----》pParent 是叶子节点  ======》插入的节点有可能插入左子树 || 右子树,所以插入后双亲节点有可能会变成+-1
			//1 ----》pParent只有右孩子   ======》插入的节点只能插入左子树-》0
			//-1 ----》pParent只有左孩子  ======》插入的节点只能插入右子树-》0
			//说这个的意思就是，最后两种情况下，只是影响到了双亲的平衡因子，并没有影响双亲再向上的结点的平衡因子
			if (pParent->_bf == 0)  //叶子节点直接返回就可以了
				return;
			else if (pParent->_bf == -1 || pParent->_bf == 1)  //这种就属于会影响到插入结点的双亲结点，再向上的，所有结点的情况
			{
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else
			{
				//parent的平衡因子 == 2 ||  -2
				//说明此时已经违反了AVL树的性质 -- 此时树已经不平衡了，此时就要对以pParent为根的树进行旋转
				//旋转又分为四种
				//左单旋
				//右单旋
				//左右双旋：左单选右单旋
				//右左双旋：左单选右单旋
			}
		}
	}
	//为了避免和结点结构中的pParent混淆，这里我是用pParent_1,来代替传入的特殊节点1
	void RotateRight(Node* pParent_1)
	{
		Node* pSubL = pParent_1->_pLeft;  //特殊结点2
		Node* pSubLR = pSubL->_pRight;  //特殊结点3
		pParent->_pLeft = pSubLR;
		//这里的判空主要是为了避免第三种情况，左单支
		if (pSubLR)
			pSubLR->_pParent = pParent_1;
		pSubL->_pRight = pParent_1;
		//接着就是处理特殊节点中的pParent_1结点
		//由于pParent_1我们不知道是不是根节点,因为我们局部画出来的pParent就是一个根结点，但是我们不能保证上面就没有其他的结点了
		//所以这里要分情况讨论
		//如果是pParent_1是子树的话，也就是说pParent的上面还有树
		//为了防止丢失pParent_1的双亲结点，这里我们先将pParent的双亲保存起来
		Node* pPParent = pParent_1->_pParent;
		pParent_1->_pParent = pSubL;
		pSubL->_pParent = pPParent;


		//接着是更新平衡因子



	}
private:
	Node* _pRoot;
};
int main()
{
	
	return 0;
}

/*
	Node* GetParent(Node* pRoot,Node* pNode)
	{
		if(pRoot == nullptr || pNode == nullptr)
			return nullptr;
		if(pRoot->left == pNode || pRoot->right == pNode)
			return pRoot;
		Node* pRet = GetParent(pRoot->left,pNode);
		if(pRet)
			return pRet;
		Node* pRet = GetParent(pRoot->right,pNode);
		return pRet;
	}

*/
#endif
//template<class T>
//struct BSTNode
//{
//	BSTNode(T _value = T())
//	:left(nullptr), right(nullptr)
//	, value(_value)
//	{}
//
//	BSTNode<T>* left;
//	BSTNode<T>* right;
//	T value;
//};
//template<class T>
//class BSTree
//{
//	typedef BSTNode<T> Node;
//public:
//	BSTree()
//		:root(nullptr)
//	{}
//	~BSTree()
//	{
//		_destory(root);
//	}
//	BSTree(const BSTree& tree)
//	{
//		this->root = _copy(tree.root);
//	}
//	Node* _copy(Node* _root)
//	{
//		if (_root == nullptr)
//			return nullptr;
//		Node* temp = new Node(_root->value);
//		temp->left  = _copy(_root->left);
//		temp->right = _copy(_root->right);
//		return temp;
//	}
//	BSTree& operator=(const BSTree& tree)
//	{
//		if (this != &tree)
//		{
//			_destory(this->root);
//			this->root =  _copy(tree.root);
//		}
//		return *this;
//	}
//	bool Insert(const T& val)
//	{
//		if (root == nullptr)
//		{
//			root = new Node(val);
//			return true;
//		}
//		else
//		{
//			Node* pCur = root;  //用来查找结点
//			Node* pParent = nullptr;  //用来记录当前正在查找结点的双亲结点
//			while (pCur)
//			{
//				pParent = pCur;
//				if (pCur->value > val)
//					pCur = pCur->left;
//				else if (pCur->value < val)
//					pCur = pCur->right;
//				else
//					return false;  //默认是不能插入重复的元素
//			}
//			pCur = new Node(val);
//			if (pParent->value > val)
//				pParent->left = pCur;
//			else
//				pParent->right = pCur;
//		}
//		return true;
//	}
//	Node* Find(const T& val)
//	{
//		if (root == nullptr)
//			return nullptr;
//		Node* pCur = root;
//		while (pCur)
//		{
//			if (pCur->value > val)
//				pCur = pCur->left;
//			else if (pCur->value < val)
//				pCur = pCur->right;
//			else
//				return pCur;
//		}
//		return nullptr;
//	}
//	bool Erase(const T& val)
//	{
//		if (root == nullptr)
//			return false;
//		//遍历整个二叉搜索树，找val
//		Node* pCur = root;
//		Node* pParent = nullptr;
//		while (pCur)
//		{
//			
//			if (pCur->value == val)
//				break;
//			else if (pCur->value > val)
//			{
//				pParent = pCur;     //这一快只能这么写，之前我把pParent = pCur放在外面，但是但是错了，这里的逻辑就是这样，不理解的话可以画图
//				pCur = pCur->left;
//			}
//			else
//			{
//				pParent = pCur;
//				pCur = pCur->right;
//			}
//		}
//		//不存在val
//		if (pCur == nullptr)
//			return false;
//		//1.待删除结点的左孩子为空
//		//2.待删除结点的右孩子为空
//		//3.待删除结点的左右孩子都不为空
//		//4.待删除结点的左右孩子都为空
//		if (pCur->left == nullptr && pCur->right == nullptr)  //左右孩子都为空
//		{
//			if (pParent->left == pCur)
//				pParent->left = nullptr;
//			else
//				pParent->right = nullptr;
//			delete pCur;
//
//		}
//		else if (pCur->left == nullptr)  //待删除的结点是左孩子为空的情况
//		{
//			if (pCur->value == val)  //刚好根节点就是要删除的结点
//			{                        
//				root = pCur->right;   //因为没有左孩子所以树的头指针，直接指向根节点的右孩子就可以
//			}
//			else  //删除的结点不是头结点
//			{
//				//判断删除结点是双亲结点的左孩子还是右孩子
//				if (pParent->left == pCur)
//					pParent->left = pCur->right;  //如果是删除结点是双亲结点的左孩子，那就让删除节点的双亲结点的左孩子指向删除结点的右孩子
//				else
//					pParent->right = pCur->right; //反之相反
//			}
//			delete pCur;
//		}
//		else if (pCur->right == nullptr)    //待删除结点的右孩子为空
//		{
//			if (pCur->value == val)  
//			{
//				root = pCur->left;   
//			}
//			else  //删除的结点不是头结点
//			{
//				//判断删除结点是双亲结点的左孩子还是右孩子
//				if (pParent->left == pCur)
//					pParent->left = pCur->left;  //如果是删除结点是双亲结点的左孩子，那就让删除节点的双亲结点的左孩子指向删除结点的右孩子
//				else
//					pParent->right = pCur->left; //反之相反
//			}
//			delete pCur;
//		}
//		else  //待删除结点的左右节点都不为空的时候
//		{
//			if (pCur->left != nullptr && pCur->right != nullptr)
//			{
//				//去找待删除结点的右孩子中的最小值，或者左孩子中的最大值，其实都一样，这里我们就使用右孩子中的最小值
//				Node* p = pCur->right;
//				pParent = pCur;  //标记双亲结点，这里的标记主要是为了防止没有进入下面while循环的情况
//				while (p->left)
//				{
//					pParent = p; //标记双亲结点
//					p = p->left;
//				}
//				pCur->value = p->value;//替换
//				//下面这两种情况比较特殊需要拿出来讨论
//				if (p == pParent->left)
//				{
//					pParent->left = p->right;
//				}
//				else
//				{
//					pParent->right = p->right;
//				}
//				delete p;
//			}
//			return true;
//		}
//		return false;
//	}
//	void Inorder()
//	{
//		_Inorder(this->root);
//	}
//private:
//	void _Inorder(Node* tree)
//	{
//		if (tree == nullptr)
//			return;
//		_Inorder(tree->left);
//		cout << tree->value << " ";
//		_Inorder(tree->right);
//	}
//	void _destory(Node*& tree) //为了在内部改变外部的指针，这里使用的就是指针的引用
//	{
//		if (tree)
//		{
//			_destory(tree->left);
//			_destory(tree->right);
//			delete tree;
//			tree = nullptr;
//		}
//	}
//private:
//	Node* root;
//};
//int main()
//{
//
//	BSTree<int> BST;
//	BST.Insert(1);
//	BST.Insert(3);
//	BST.Insert(7);
//	BST.Insert(5);
//	BST.Insert(4);
//	BST.Insert(6);
//	BST.Insert(2);
//	BST.Inorder();
//	BST.Erase(1);
//	cout << endl;
//	BST.Inorder();
//	cout << endl;
//	BST.Erase(2);
//	BST.Inorder();
//	cout << endl;
//	BST.Erase(5);
//	BST.Inorder();
//	cout << endl;
//	BST.Erase(4);
//	BST.Inorder();
//	cout << endl;
//	cout << BST.Find(7)<< endl;
//	BSTree<int> BST2;
//	BST2 = BST;
//	BST2.Inorder();
//	BSTree<int> BST3(BST2);
//	BST3.Inorder();
//
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//int main()
//{
//	int a[200] = {0};
//	int num;
//	int j = 0;
//	int count = 0;
//	printf("请输入一个数字\n");
//	scanf("%d", &num);
//	for (int i = 1; i <= num; ++i)
//	{
//		if (num % i == 0)
//			a[j++] = i;
//	}
//	for (int i = 1; i < 200 && a[i] != 0; ++i)
//	{
//		int flag = 0;
//		for (int k = 2; k <= sqrt((float)a[i]); ++k)
//		{
//			if (a[i] % k == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//			count += a[i];
//	}
//	printf("%d\n", count);
//	return 0;
//}


