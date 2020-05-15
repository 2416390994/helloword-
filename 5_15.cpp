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
			size = 0;
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


				while (pParent != pHead && RED == pParent->_color)
				{
					Node* grandFather = pParent->_parent;
					if (pParent == grandFather->_left)  //p�ڵ����游�ڵ�������������
					{
						//�������۵��������
						Node* uncle = grandFather->_right;
						if (uncle && RED = uncle->_color)
						{
							//���1 :�����������Ϊ��ɫ
							pParent->_color = BLACK;
							uncle->_color = BLACK;
							grandFather->_color = RED;

							//��Ϊ�游��˫�ף�������Ҫ�������ϵ���
							pCur = grandFather;
							pParent = pCur->_parent;
						}
						else
						{
							//������������
							//�ȴ��������
							if (pCur == pParent->_right)
							{
								//����pParentΪ���Ķ�������������
								RotateLeft(pParent);
								swap(pParent, pCur);
							}
							//����˫�׺��游����ɫ
							grandFather->_color = RED;
							pParent->_color = BLACK;
							RotateRight(grandFather);

						}
					}
					else   //���Һ��ӵ��������
					{
						Node* uncle = grandFather->_left;
						if (uncle && RED == uncle->_color)
						{
							//���һ�ķ����
							pParent->_color = BLACK;
							pCur->_color = BLACK;
							grandFather->_color = RED;

							pCur = grandFather;
							pParent = pCur->_parent;

						}
						else
						{
							//�������������ķ����
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





				//����pHead������ָ����
				pRoot->_color = BLACK;
				pHead->_left = LeftMost();
				pHead->_right = RightMost();
				size++;
				return true;
			}
		}



	private:
		void RotateLeft(Node* pParent)  //��ѡ
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
				//pParent���Ǹ��ڵ�
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

		void Rotateright(Node* pParent)  //�ҵ���
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
				//pParent���Ǹ��ڵ�
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