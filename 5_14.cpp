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



	//���������е�ֵ��Ψһ��
	template<class T>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
		public:
			RBTree()  //����ͷ�ڵ�
			{
				pHead = new Node;
				pHead->_left = pHead;
				pHead->_right = pHead;
				pHead->_parent = nullptr;
			}
			
			bool insert(const T& data)
			{
				Node*& pRoot = getRoot();
				if (nullptr == pRoot) //��������ֻ��һ��ͷ�ڵ�
				{
					pRoot = new Node(val, BLACK);
					pHead->_left = pRoot;
					pHead->_right = pRoot;
					pHead->_parent = pHead;
					return true;
				}
				//�ǿ�
				//���ն����������Ĺ��ɲ����½ڵ�
				
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
						//val��Ӧ����Ѿ�����
						return false;
					}

					//�����½ڵ�
					pCur = new Node(val);
					if (val < pParent->_val)
						pParent->_left = pCur;
					else
						pParent->_right = pCur;

					pCur->_parent = pParent;

					//�������Ƿ�Υ�������������
					//ֻ��Ҫ���һ��������
					//�½ڵ��Ĭ��ɫ�Ǻ�ɫ������½ڵ��˫�׽ڵ�Ҳ�Ǻ�ɫ���ض���Υ������3
					
					
					if (RED == pParent->_color)
					{

					}





					//����pHead������ָ����
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