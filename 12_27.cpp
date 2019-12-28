#include<iostream>
using namespace std;
//template<class	T>
//T* prev == nullptr;
//template<class	T>
////ƽ�������ת˫������
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
		pCur->_pParent = pParent; //ȷ��˫��
		//ÿ�β����½ڵ�֮��˫�׽���ƽ������һ���ᷢ���ı�

		//����˫�׵�ƽ������
		while ()
		{
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
			//����AVL����ƽ�����ӱ����ֻ�����ֿ���0�� -1 �� 1
			//�����½ڵ�֮ǰ
			//0 ----��pParent ��Ҷ�ӽڵ�  ======������Ľڵ��п��ܲ��������� || ������,���Բ����˫�׽ڵ��п��ܻ���+-1
			//1 ----��pParentֻ���Һ���   ======������Ľڵ�ֻ�ܲ���������-��0
			//-1 ----��pParentֻ������  ======������Ľڵ�ֻ�ܲ���������-��0
			//˵�������˼���ǣ������������£�ֻ��Ӱ�쵽��˫�׵�ƽ�����ӣ���û��Ӱ��˫�������ϵĽ���ƽ������
			if (pParent->_bf == 0)  //Ҷ�ӽڵ�ֱ�ӷ��ؾͿ�����
				return;
			else if (pParent->_bf == -1 || pParent->_bf == 1)  //���־����ڻ�Ӱ�쵽�������˫�׽�㣬�����ϵģ����н������
			{
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else
			{
				//parent��ƽ������ == 2 ||  -2
				//˵����ʱ�Ѿ�Υ����AVL�������� -- ��ʱ���Ѿ���ƽ���ˣ���ʱ��Ҫ����pParentΪ������������ת
				//��ת�ַ�Ϊ����
				//����
				//�ҵ���
				//����˫������ѡ�ҵ���
				//����˫������ѡ�ҵ���
			}
		}
	}
	//Ϊ�˱���ͽ��ṹ�е�pParent����������������pParent_1,�����洫�������ڵ�1
	void RotateRight(Node* pParent_1)
	{
		Node* pSubL = pParent_1->_pLeft;  //������2
		Node* pSubLR = pSubL->_pRight;  //������3
		pParent->_pLeft = pSubLR;
		//������п���Ҫ��Ϊ�˱���������������֧
		if (pSubLR)
			pSubLR->_pParent = pParent_1;
		pSubL->_pRight = pParent_1;
		//���ž��Ǵ�������ڵ��е�pParent_1���
		//����pParent_1���ǲ�֪���ǲ��Ǹ��ڵ�,��Ϊ���Ǿֲ���������pParent����һ������㣬�������ǲ��ܱ�֤�����û�������Ľ����
		//��������Ҫ���������
		//�����pParent_1�������Ļ���Ҳ����˵pParent�����滹����
		//Ϊ�˷�ֹ��ʧpParent_1��˫�׽�㣬���������Ƚ�pParent��˫�ױ�������
		Node* pPParent = pParent_1->_pParent;
		pParent_1->_pParent = pSubL;
		pSubL->_pParent = pPParent;


		//�����Ǹ���ƽ������



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
//			Node* pCur = root;  //�������ҽ��
//			Node* pParent = nullptr;  //������¼��ǰ���ڲ��ҽ���˫�׽��
//			while (pCur)
//			{
//				pParent = pCur;
//				if (pCur->value > val)
//					pCur = pCur->left;
//				else if (pCur->value < val)
//					pCur = pCur->right;
//				else
//					return false;  //Ĭ���ǲ��ܲ����ظ���Ԫ��
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
//		//����������������������val
//		Node* pCur = root;
//		Node* pParent = nullptr;
//		while (pCur)
//		{
//			
//			if (pCur->value == val)
//				break;
//			else if (pCur->value > val)
//			{
//				pParent = pCur;     //��һ��ֻ����ôд��֮ǰ�Ұ�pParent = pCur�������棬���ǵ��Ǵ��ˣ�������߼����������������Ļ����Ի�ͼ
//				pCur = pCur->left;
//			}
//			else
//			{
//				pParent = pCur;
//				pCur = pCur->right;
//			}
//		}
//		//������val
//		if (pCur == nullptr)
//			return false;
//		//1.��ɾ����������Ϊ��
//		//2.��ɾ�������Һ���Ϊ��
//		//3.��ɾ���������Һ��Ӷ���Ϊ��
//		//4.��ɾ���������Һ��Ӷ�Ϊ��
//		if (pCur->left == nullptr && pCur->right == nullptr)  //���Һ��Ӷ�Ϊ��
//		{
//			if (pParent->left == pCur)
//				pParent->left = nullptr;
//			else
//				pParent->right = nullptr;
//			delete pCur;
//
//		}
//		else if (pCur->left == nullptr)  //��ɾ���Ľ��������Ϊ�յ����
//		{
//			if (pCur->value == val)  //�պø��ڵ����Ҫɾ���Ľ��
//			{                        
//				root = pCur->right;   //��Ϊû��������������ͷָ�룬ֱ��ָ����ڵ���Һ��ӾͿ���
//			}
//			else  //ɾ���Ľ�㲻��ͷ���
//			{
//				//�ж�ɾ�������˫�׽������ӻ����Һ���
//				if (pParent->left == pCur)
//					pParent->left = pCur->right;  //�����ɾ�������˫�׽������ӣ��Ǿ���ɾ���ڵ��˫�׽�������ָ��ɾ�������Һ���
//				else
//					pParent->right = pCur->right; //��֮�෴
//			}
//			delete pCur;
//		}
//		else if (pCur->right == nullptr)    //��ɾ�������Һ���Ϊ��
//		{
//			if (pCur->value == val)  
//			{
//				root = pCur->left;   
//			}
//			else  //ɾ���Ľ�㲻��ͷ���
//			{
//				//�ж�ɾ�������˫�׽������ӻ����Һ���
//				if (pParent->left == pCur)
//					pParent->left = pCur->left;  //�����ɾ�������˫�׽������ӣ��Ǿ���ɾ���ڵ��˫�׽�������ָ��ɾ�������Һ���
//				else
//					pParent->right = pCur->left; //��֮�෴
//			}
//			delete pCur;
//		}
//		else  //��ɾ���������ҽڵ㶼��Ϊ�յ�ʱ��
//		{
//			if (pCur->left != nullptr && pCur->right != nullptr)
//			{
//				//ȥ�Ҵ�ɾ�������Һ����е���Сֵ�����������е����ֵ����ʵ��һ�����������Ǿ�ʹ���Һ����е���Сֵ
//				Node* p = pCur->right;
//				pParent = pCur;  //���˫�׽�㣬����ı����Ҫ��Ϊ�˷�ֹû�н�������whileѭ�������
//				while (p->left)
//				{
//					pParent = p; //���˫�׽��
//					p = p->left;
//				}
//				pCur->value = p->value;//�滻
//				//��������������Ƚ�������Ҫ�ó�������
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
//	void _destory(Node*& tree) //Ϊ�����ڲ��ı��ⲿ��ָ�룬����ʹ�õľ���ָ�������
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
//	printf("������һ������\n");
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


