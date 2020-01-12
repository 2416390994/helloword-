#include<iostream>
using namespace std;
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
//再说一次默认是右子树-左子树
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
		//首先要说的就是，插入的位置绝对是，叶子节点 || 只有左孩子的结点 || 只有右孩子的结点
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
				return false;  //这里的意思就是假如要插入的值树中已存在那么就直接返回，默认树中插得值都是不一样的
		}
		//插入新结点
		pCur = new Node(data);  //先创建结点
		if (data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		pCur->_pParent = pParent; //最后再让新节点的双亲结点指向pParent
		
		
		//每次插入新节点之后，双亲结点的平衡因子一定会发生改变

		//更新双亲的平衡因子
		while (pParent)   //循环条件就是双亲不为空
		{
			if (pCur == pParent->_pLeft)  //如果是左子树，则双亲的平衡因子--。因为我默认平衡因子的算法是右子树减去左子树
				pParent->_bf--;
			else
				pParent->_bf++;

			//由于AVL树的平衡因子本身就只有三种可能0， -1 ， 1
			//插入新节点之前
			//0 ----》pParent 是叶子节点  ======》插入的节点有可能插入左子树 || 右子树,所以插入后双亲节点有可能会变成+-1
			//1 ----》pParent只有右孩子   ======》插入的节点只能插入左子树-》0
			//-1 ----》pParent只有左孩子  ======》插入的节点只能插入右子树-》0
			//说这个的意思就是，最后两种情况下，只是影响到了双亲的平衡因子，并没有影响双亲再向上的结点的平衡因子
			if (pParent->_bf == 0)  //也就是说，再进行完上面的++||--之后，使得插入元素的结点，的平衡因子变成了0，也就是上面我所说到的最后两种情况，因为没有影响到再向上的其他结点，所以可以直接返回了
				return true;
			else if (pParent->_bf == -1 || pParent->_bf == 1)  //这种就属于会影响到插入结点的双亲结点，再向上的，所有结点的情况
			{
				//这里调整pCur的位置
				pCur = pParent;   //此时就需要不停的进入while循环进行刚开始的++||--的更新操作
				pParent = pCur->_pParent;
			}
			else
			{
				//parent的平衡因子 == 2 ||  -2
				//说明此时已经违反了AVL树的性质 -- 此时树已经不平衡了，此时就要对以pParent为根的树进行旋转
				//旋转又分为四种
				//左单旋
				//右单旋
				//此处可以使用根据不平衡结点的平衡因子来计算，假如平衡因子是+2，有因为我们是拿右子树减的左子树所以这里就是左单旋，否则就是右单旋
				//当然只判断不平衡结点是远远不够的，因为还有左右双旋，和右左双旋，所以还要判断不平衡结点的左右子树
				
				//左右双旋：左单选右单旋
				//右左双旋：左单选右单旋
				if (pParent->_bf == 2)
				{
					//pParent的右子树高
					//pCur的平衡因子是+1
					//因为插入之后只会在插入结点的一条路径上进行修改，所以pCur就是pParent的孩子结点，不必知道是左右孩子，因为没必要知道
					if (pCur->_bf == 1)
					{
						//左单旋
						RotateLeft(pParent);
					}
					else
					{
						//pCur的平衡因子是-1
						//右左双旋
						RotateRL(pParent);
					}
				}
				else
				{
					//pParent的左子树高
					//pParent->_bf == -2
					if (pCur->_bf == -1)
					{
						//右单旋
						RotateRight(pParent);
					}
					else
					{
						//左右双旋
						RotateLR(pParent);
					}
				}
				break;   //旋转完成就不需要再次进入while中了，可以直接退出因为，插入节点导致不平衡前和旋转平衡后层数没有变化,对上面没有影响
			}
		}
		return true;
	}
	//为了避免和结点结构中的pParent混淆，这里我是用pParent_1,来代替传入的特殊节点1
	void RotateRight(Node* pParent_1)  //特殊结点1
	{
		Node* pSubL = pParent_1->_pLeft;  //特殊结点2
		Node* pSubLR = pSubL->_pRight;  //特殊结点3
		pParent_1->_pLeft = pSubLR;
		//这里的判空主要是为了避免第三种情况，左单支
		if (pSubLR)  //如果特殊结点3不为空的话，就让特殊节点3的双亲指针域指向特殊结点1
			pSubLR->_pParent = pParent_1;
		pSubL->_pRight = pParent_1;
		//接着就是处理特殊节点中的pParent_1结点
		//由于pParent_1我们不知道是不是根节点,因为我们局部画出来的pParent就是一个根结点，但是我们不能保证上面就没有其他的结点了
		//所以这里要分情况讨论
		//如果是pParent_1是子树的话，也就是说pParent的上面还有树
		//为了防止丢失pParent_1的双亲结点，这里我们先将pParent的双亲保存起来
		Node* pPParent = pParent_1->_pParent;   //特殊结点1的双亲结点有可能是空
		pParent_1->_pParent = pSubL;  //重新设置双亲
		pSubL->_pParent = pPParent;


		if (pPParent == nullptr)  //说明特殊结点1没有双亲，
		{
			_pRoot = pSubL;  //没有双亲的话，就直接更新类中的根节点为特殊结点2
		}
		else //说明特殊结点1有双亲
		{
			if (pPParent->_pLeft == pParent_1)  //此时虽然更新了特殊节点1的双亲，但是特殊节点1原来的双亲，还是将特殊结点1，视为自己的孩子
				//所以说如果，特殊节点1是之前双亲的左孩子的话，就需要让他的左孩子现在指向特殊节点2，反之就是让右孩子指向特殊节点2
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}

		//接着是更新平衡因子
		//选装更新完毕之后，特殊节点1和特殊结点2的平衡因子都变成0
		//特殊结点1的双亲结点平衡因子不变
		pParent_1->_bf = pSubL->_bf = 0;
	}


	//左单旋
	void RotateLeft(Node* pParent_1)   //特殊结点1
	{
		Node* pSubR = pParent_1->_pRight;  //特殊结点2
		Node* pSubRL = pSubR->_pLeft;   //特殊结点3
		pParent_1->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent_1;
		pSubR->_pLeft = pParent_1;
		Node* pPParent = pParent_1->_pParent;
		pSubR->_pParent = pPParent;
		pParent_1->_pParent = pSubR;
		if (pPParent == nullptr)
		{
			_pRoot = pSubR;
		}
		else
		{
			if (pParent_1 == pPParent->_pLeft)
			{
				pPParent->_pLeft = pSubR;
			}
			else
			{
				pPParent->_pRight = pSubR;
			}
		}

		pParent_1->_bf = pSubR->_bf = 0;
	}

	//右单旋左单旋
	void RotateRL(Node* pParent)
	{
		//右左双旋的时候发现，有部分结点的平衡因子需要更新，也是一些特定的情况
		//这里就不画图分析了，直接给出代码
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		RotateRight(pParent->_pRight);
		RotateLeft(pParent);


		//三种情况
		//bf ==1 || -1 || 0,0的情况在内部已经处理过了
		if (bf == 1)
			pParent->_bf = -1;
		else if (bf == -1)
			pSubR->_bf = 1;
	}
	//左单旋右单旋
	void RotateLR(Node* pParent)
	{
		Node* pSubR = pParent->_pLeft;
		Node* pSubRL = pSubR->_pRight;
		int bf = pSubRL->_bf;

		RotateLeft(pParent->_pLeft);
		RotateRight(pParent);

		//三种情况
		//bf ==1 || -1 || 0,0的情况在内部已经处理过了
		if (bf == 1)
			pSubRL->_bf = -1;
		else if (bf == -1)
			pParent->_bf = 1;


	}

	void InOreder()   //中序遍历
	{
		_InOrder(_pRoot);
	}
	bool Tree_Hight()  //判断这棵树是不是AVL树
	{
		return _Tree_Hight(_pRoot);
	}
private:
	void _InOrder(Node* pRoot)  //中序遍历
	{
		if (pRoot == nullptr)
			return;
		_InOrder(pRoot->_pLeft);
		cout << pRoot->_data << endl;
		_InOrder(pRoot->_pRight);
	}

	bool _Tree_Hight(Node* pRoot)  //判断是不是AVL树
	{
		if (pRoot == nullptr)
			return true;
		int Left_Hight = Hight(pRoot->_pLeft);
		int Right_Hight = Hight(pRoot->_pRight);
		int bf = Right_Hight - Left_Hight;  //自己算出来的平衡因子
		if (abs(bf) > 1 || bf != pRoot->_bf)
			return false;
		return _Tree_Hight(pRoot->_pLeft) && _Tree_Hight(pRoot->_pRight);
	}

	int  Hight(Node* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		int L = Hight(pRoot->_pLeft);
		int R = Hight(pRoot->_pRight);
		return L > R ? L + 1 : R + 1;
	}

	Node* _pRoot;
};


void test()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);
	t.InOreder();
	cout << t.Tree_Hight() << endl;
}
int main()
{
	test();
	return 0;
}
