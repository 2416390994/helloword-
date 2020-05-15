#include<iostream>
#include<vector>
using namespace std;
namespace mytree
{
	enum color{ RED, BLACK };
	template<class T>
	struct RBTreeNode
	{
		RBTreeNode(const T& val = T(), color color = RED)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _val(val)
		, _color(color)
		{

		}


		RBTreeNode* _left;
		RBTreeNode* _right;
		RBTreeNode* _parent;
		T _val;
		color _color;
	};



	//假设红黑树中的值是唯一的
	template<class T>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		RBTree()  //创建头节点
		{
			pHead = new Node;
			pHead->_left = pHead;
			pHead->_right = pHead;
			pHead->_parent = nullptr;
			size = 0;
		}

		bool insert(const T& data)
		{
			Node*& pRoot = getRoot();
			if (nullptr == pRoot) //假如现在只有一个头节点
			{
				pRoot = new Node(val, BLACK);
				pHead->_left = pRoot;
				pHead->_right = pRoot;
				pHead->_parent = pHead;
				return true;
			}
			//非空
			//按照二叉搜索树的规律插入新节点

			Node* pCur = pRoot;
			Node* pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (val < pCur->_val)
				{
					pCur = pCur->_left;
				}
				else if (val > pCur->_val)
				{
					pCur = pCur->_right;
				}
				else
				{
					//val对应结点已经存在
					return false;
				}

				//插入新节点
				pCur = new Node(val);
				if (val < pParent->_val)
					pParent->_left = pCur;
				else
					pParent->_right = pCur;

				pCur->_parent = pParent;

				//检测插入是否违反红黑树的性质
				//只需要检测一下性质三
				//新节点的默颜色是红色，如果新节点的双亲节点也是红色，必定会违反性质3


				while (pParent != pHead && RED == pParent->_color)
				{
					Node* grandFather = pParent->_parent;
					if (pParent == grandFather->_left)  //p节点是祖父节点的左孩子三种情况
					{
						//上面讨论的三种情况
						Node* uncle = grandFather->_right;
						if (uncle && RED = uncle->_color)
						{
							//情况1 :叔叔结点存在且为红色
							pParent->_color = BLACK;
							uncle->_color = BLACK;
							grandFather->_color = RED;

							//因为祖父有双亲，所以需要继续向上调整
							pCur = grandFather;
							pParent = pCur->_parent;
						}
						else
						{
							//情况二和情况三
							//先处理情况三
							if (pCur == pParent->_right)
							{
								//对以pParent为根的二叉树进行左单旋
								RotateLeft(pParent);
								swap(pParent, pCur);
							}
							//交换双亲和祖父的颜色
							grandFather->_color = RED;
							pParent->_color = BLACK;
							RotateRight(grandFather);

						}
					}
					else   //是右孩子的三种情况
					{
						Node* uncle = grandFather->_left;
						if (uncle && RED == uncle->_color)
						{
							//情况一的反情况
							pParent->_color = BLACK;
							pCur->_color = BLACK;
							grandFather->_color = RED;

							pCur = grandFather;
							pParent = pCur->_parent;

						}
						else
						{
							//情况二和情况三的反情况
							if (pCur == pParent->_left)
							{
								RotateRight(pParent);
								swap(pCur, pParent);
							}

							pParent->_color = BLACK;
							grandFather->_color = RED;
							RotateLeft(grandFather);
						}
					}

				}





				//更新pHead的左右指针域
				pRoot->_color = BLACK;
				pHead->_left = LeftMost();
				pHead->_right = RightMost();
				size++;
				return true;
			}
		}



	private:
		void RotateLeft(Node* pParent)  //左单选
		{
			Node* pSubR = pParent->_right;
			Node* pSubRL = pSubR->_left;
			pParent->_right = pSubRL;
			if (pSubRL)
				pSubRL->_parent = pParent;
			pSubR->_left = pParent;
			Node* pPParent = pParent->_parent;
			pParent->_parent = pSubR;
			pSubR->_parent = pPParent;
			if (pPParent == pHead)
			{
				//pParent就是根节点
				pHead->_parent = pSubR;
			}
			else
			{
				if (pParent == pPParent->_left)
					pPParent->_left = pSubR;
				else
					pPParent->_right = pSubR;
			}
		}

		void Rotateright(Node* pParent)  //右单旋
		{
			Node* pSubL = pParent->_left;
			Node* pSubLR = pSubL->_right;
			pParent->_left = pSubLR;
			if (pSubLR)
				pSubLR->_parent = pParent;

			pSubR->_right = pParent;
			Node* pPParent = pParent->_parent;
			pSubL->_parent = pPParent;
			pParent->_parent = pSubL;
			if (pPParent == pHead)
			{
				//pParent就是根节点
				pHead->_parent = pSubL;
			}
			else
			{
				if (pParent == pPParent->_left)
					pPParent->_right = pSubL;
				else
					pPParent->_left = pSubL;
			}
		}



		Node* LeftMost()
		{
			Node* pRoot = getRoot();
			if (nullptr == pRoot)
				return pHead;
			Node*  pCur = pRoot;
			while (pCur->_left)
				pCur = pCur->_left;
			return pCur;
		}

		Node* RightMost()
		{
			Node* pRoot = getRoot();
			if (nullptr == pRoot)
				return pHead;
			Node*  pCur = pRoot;
			while (pCur->_right)
				pCur = pCur->_right;
			return pCur;
		}

		Node*& gerRoot()
		{
			return pHead->_parent;
		}
		Node* pHead;
		size_t size;
	};
};



int main()
{


	return 0;
}