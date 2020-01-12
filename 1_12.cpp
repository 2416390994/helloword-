#include<iostream>
using namespace std;
template<class T>  //���ṹ
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
	: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
	, _data(data), _bf(0)
	{}
	AVLTreeNode<T>* _pLeft; // �ýڵ������
	AVLTreeNode<T>* _pRight; // �ýڵ���Һ���
	AVLTreeNode<T>* _pParent; // �ýڵ��˫��
	T _data;
	int _bf; // �ýڵ��ƽ������
};

//������Ĳ�������У��ж�һ������ƽ�����ӣ�����Ĭ����ʹ�������� - ������
//��˵һ��Ĭ����������-������
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
		//AVL���п����ǿ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//�ǿ�
		//�Ȱ��ն����������ķ�ʽ���в���
		//����Ҫ˵�ľ��ǣ������λ�þ����ǣ�Ҷ�ӽڵ� || ֻ�����ӵĽ�� || ֻ���Һ��ӵĽ��
		//���Բ����ڼ������ӣ������Һ��ӵĽ����в���
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;   //������������˫�׽��
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;  //�������˼���Ǽ���Ҫ�����ֵ�����Ѵ�����ô��ֱ�ӷ��أ�Ĭ�����в��ֵ���ǲ�һ����
		}
		//�����½��
		pCur = new Node(data);  //�ȴ������
		if (data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		pCur->_pParent = pParent; //��������½ڵ��˫�׽��ָ��pParent
		
		
		//ÿ�β����½ڵ�֮��˫�׽���ƽ������һ���ᷢ���ı�

		//����˫�׵�ƽ������
		while (pParent)   //ѭ����������˫�ײ�Ϊ��
		{
			if (pCur == pParent->_pLeft)  //���������������˫�׵�ƽ������--����Ϊ��Ĭ��ƽ�����ӵ��㷨����������ȥ������
				pParent->_bf--;
			else
				pParent->_bf++;

			//����AVL����ƽ�����ӱ����ֻ�����ֿ���0�� -1 �� 1
			//�����½ڵ�֮ǰ
			//0 ----��pParent ��Ҷ�ӽڵ�  ======������Ľڵ��п��ܲ��������� || ������,���Բ����˫�׽ڵ��п��ܻ���+-1
			//1 ----��pParentֻ���Һ���   ======������Ľڵ�ֻ�ܲ���������-��0
			//-1 ----��pParentֻ������  ======������Ľڵ�ֻ�ܲ���������-��0
			//˵�������˼���ǣ������������£�ֻ��Ӱ�쵽��˫�׵�ƽ�����ӣ���û��Ӱ��˫�������ϵĽ���ƽ������
			if (pParent->_bf == 0)  //Ҳ����˵���ٽ����������++||--֮��ʹ�ò���Ԫ�صĽ�㣬��ƽ�����ӱ����0��Ҳ������������˵������������������Ϊû��Ӱ�쵽�����ϵ�������㣬���Կ���ֱ�ӷ�����
				return true;
			else if (pParent->_bf == -1 || pParent->_bf == 1)  //���־����ڻ�Ӱ�쵽�������˫�׽�㣬�����ϵģ����н������
			{
				//�������pCur��λ��
				pCur = pParent;   //��ʱ����Ҫ��ͣ�Ľ���whileѭ�����иտ�ʼ��++||--�ĸ��²���
				pParent = pCur->_pParent;
			}
			else
			{
				//parent��ƽ������ == 2 ||  -2
				//˵����ʱ�Ѿ�Υ����AVL�������� -- ��ʱ���Ѿ���ƽ���ˣ���ʱ��Ҫ����pParentΪ������������ת
				//��ת�ַ�Ϊ����
				//����
				//�ҵ���
				//�˴�����ʹ�ø��ݲ�ƽ�����ƽ�����������㣬����ƽ��������+2������Ϊ�������������������������������������������������ҵ���
				//��Ȼֻ�жϲ�ƽ������ԶԶ�����ģ���Ϊ��������˫����������˫�������Ի�Ҫ�жϲ�ƽ�������������
				
				//����˫������ѡ�ҵ���
				//����˫������ѡ�ҵ���
				if (pParent->_bf == 2)
				{
					//pParent����������
					//pCur��ƽ��������+1
					//��Ϊ����֮��ֻ���ڲ������һ��·���Ͻ����޸ģ�����pCur����pParent�ĺ��ӽ�㣬����֪�������Һ��ӣ���Ϊû��Ҫ֪��
					if (pCur->_bf == 1)
					{
						//����
						RotateLeft(pParent);
					}
					else
					{
						//pCur��ƽ��������-1
						//����˫��
						RotateRL(pParent);
					}
				}
				else
				{
					//pParent����������
					//pParent->_bf == -2
					if (pCur->_bf == -1)
					{
						//�ҵ���
						RotateRight(pParent);
					}
					else
					{
						//����˫��
						RotateLR(pParent);
					}
				}
				break;   //��ת��ɾͲ���Ҫ�ٴν���while���ˣ�����ֱ���˳���Ϊ������ڵ㵼�²�ƽ��ǰ����תƽ������û�б仯,������û��Ӱ��
			}
		}
		return true;
	}
	//Ϊ�˱���ͽ��ṹ�е�pParent����������������pParent_1,�����洫�������ڵ�1
	void RotateRight(Node* pParent_1)  //������1
	{
		Node* pSubL = pParent_1->_pLeft;  //������2
		Node* pSubLR = pSubL->_pRight;  //������3
		pParent_1->_pLeft = pSubLR;
		//������п���Ҫ��Ϊ�˱���������������֧
		if (pSubLR)  //���������3��Ϊ�յĻ�����������ڵ�3��˫��ָ����ָ��������1
			pSubLR->_pParent = pParent_1;
		pSubL->_pRight = pParent_1;
		//���ž��Ǵ�������ڵ��е�pParent_1���
		//����pParent_1���ǲ�֪���ǲ��Ǹ��ڵ�,��Ϊ���Ǿֲ���������pParent����һ������㣬�������ǲ��ܱ�֤�����û�������Ľ����
		//��������Ҫ���������
		//�����pParent_1�������Ļ���Ҳ����˵pParent�����滹����
		//Ϊ�˷�ֹ��ʧpParent_1��˫�׽�㣬���������Ƚ�pParent��˫�ױ�������
		Node* pPParent = pParent_1->_pParent;   //������1��˫�׽���п����ǿ�
		pParent_1->_pParent = pSubL;  //��������˫��
		pSubL->_pParent = pPParent;


		if (pPParent == nullptr)  //˵��������1û��˫�ף�
		{
			_pRoot = pSubL;  //û��˫�׵Ļ�����ֱ�Ӹ������еĸ��ڵ�Ϊ������2
		}
		else //˵��������1��˫��
		{
			if (pPParent->_pLeft == pParent_1)  //��ʱ��Ȼ����������ڵ�1��˫�ף���������ڵ�1ԭ����˫�ף����ǽ�������1����Ϊ�Լ��ĺ���
				//����˵���������ڵ�1��֮ǰ˫�׵����ӵĻ�������Ҫ��������������ָ������ڵ�2����֮�������Һ���ָ������ڵ�2
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}

		//�����Ǹ���ƽ������
		//ѡװ�������֮������ڵ�1��������2��ƽ�����Ӷ����0
		//������1��˫�׽��ƽ�����Ӳ���
		pParent_1->_bf = pSubL->_bf = 0;
	}


	//����
	void RotateLeft(Node* pParent_1)   //������1
	{
		Node* pSubR = pParent_1->_pRight;  //������2
		Node* pSubRL = pSubR->_pLeft;   //������3
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

	//�ҵ�������
	void RotateRL(Node* pParent)
	{
		//����˫����ʱ���֣��в��ֽ���ƽ��������Ҫ���£�Ҳ��һЩ�ض������
		//����Ͳ���ͼ�����ˣ�ֱ�Ӹ�������
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		RotateRight(pParent->_pRight);
		RotateLeft(pParent);


		//�������
		//bf ==1 || -1 || 0,0��������ڲ��Ѿ��������
		if (bf == 1)
			pParent->_bf = -1;
		else if (bf == -1)
			pSubR->_bf = 1;
	}
	//�����ҵ���
	void RotateLR(Node* pParent)
	{
		Node* pSubR = pParent->_pLeft;
		Node* pSubRL = pSubR->_pRight;
		int bf = pSubRL->_bf;

		RotateLeft(pParent->_pLeft);
		RotateRight(pParent);

		//�������
		//bf ==1 || -1 || 0,0��������ڲ��Ѿ��������
		if (bf == 1)
			pSubRL->_bf = -1;
		else if (bf == -1)
			pParent->_bf = 1;


	}

	void InOreder()   //�������
	{
		_InOrder(_pRoot);
	}
	bool Tree_Hight()  //�ж�������ǲ���AVL��
	{
		return _Tree_Hight(_pRoot);
	}
private:
	void _InOrder(Node* pRoot)  //�������
	{
		if (pRoot == nullptr)
			return;
		_InOrder(pRoot->_pLeft);
		cout << pRoot->_data << endl;
		_InOrder(pRoot->_pRight);
	}

	bool _Tree_Hight(Node* pRoot)  //�ж��ǲ���AVL��
	{
		if (pRoot == nullptr)
			return true;
		int Left_Hight = Hight(pRoot->_pLeft);
		int Right_Hight = Hight(pRoot->_pRight);
		int bf = Right_Hight - Left_Hight;  //�Լ��������ƽ������
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
