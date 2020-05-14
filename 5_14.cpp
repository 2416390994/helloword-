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
					
					
					if (RED == pParent->_color)
					{

					}





					//更新pHead的左右指针域
					pHead->_left = LeftMost();
					pHead->_right = RightMost();
					
					return true;
				}



			}

			

	private:
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
	};
};



int main()
{


	return 0;
}