#include<iostream>
using namespace std;
//void test()
//{
//	for (int i = 1; i <= 100; ++i)
//	{
//		int flag = 0;
//		for (int j = 2; j <= sqrt(i); ++j)
//		{
//			if (i%j == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//			cout << i << endl;
//	}
//}
//struct
//{
//	int a;
//	int b;
//}point = { 1, 2 };
//int test(int a, int b)
//{
//	return a + b;
//}
//typedef void(*pfunc)(int);
//typedef struct
//{
//	int a;
//	int* pa;
//}pa1;
//typedef struct
//{
//	int b;
//	pa1* p;
//}pa2;
#if 0
int test(int *a,int length,int b)
{
	int L = 0;
	int R = length - 1;
	int middle = 0;
	while (L <= R)
	{
		middle =( L + R )/ 2;
		if (a[middle]>b)
			R = middle - 1;
		else if (a[middle] < b)
			L = middle + 1;
		else
			return middle;
	}
	return -1;
}
int main()
{
	int a[] = { 2, 6, 8, 9, 12, 16, 18, 26, 28, 35, 40 };
	int length = sizeof(a) / sizeof(a[0]);
	int ret = test(a, length,40);
	if (ret != -1)
		cout << "�ҵ��ˣ��±���" << ret << endl;
	else
		cout << "û�ҵ�" << endl;
	/*int a = 5;
	pa1 b = { 1, &a };
	pa2 c = { 2, &b };
	cout << (*c.p->pa) << endl;*/
	//pfunc  max;
	//max(1);
	//int(*ptr)(int, int) = test;
	//
	////������Ҫ˵���ľ���testǰ��Ӳ���&����һ��
	//printf("%d", (*ptr)(1, 2));
	////(ptr)ǰ��Ӳ���*Ҳ��һ��������(***********ptr)Ҳ��û������ptr(1,2)Ҳû����
	return  0;
}
//������ǣ����һ��������Ǻ���ʵ���������е�ʱ��Ž��пռ�ķ���ģ�����int(*ptr)(int, int) = test����test��û�пռ䣬
//��������������ʲô������
//ÿ������������һ�ŷ��ű�Ȼ����ű������¼�ź��������ַ���ں������е�ʱ�򣬾ͻ���ʱ�İ����ַ������ʱ������ʵ��ַ��������
//����˵����ָ����һ����ָ�룬����˵&��* ���Ǽٵģ��Ӳ��Ӷ�����
#endif
#if 0
#include<stdio.h>
#include<assert.h>
using namespace std;
typedef struct SeqList
{
	int * _array;
	int _size;
	int _capacity;
}SeqLsit;
//����
void bigcapacity(SeqList* seqlist)
{
	if (seqlist->_size == seqlist->_capacity)
	{
		int* p;
		int newcapacity = seqlist->_capacity * 2;
		p = new int[newcapacity];
		for (int i = 0; i < seqlist->_size; ++i)
		{
			p[i] = seqlist->_array[i];
		}
		free(seqlist->_array);
		seqlist->_array = p;
		seqlist->_capacity = newcapacity;
	}
}
//��ʼ��
void SeqListInit(SeqList *seqlist,int capacity)
{
	assert(seqlist);
	seqlist->_array = new int[capacity];
	seqlist->_capacity = capacity;
	seqlist->_size = 0;
}
//β��
void _push_back(SeqList* seqlist,int number)
{
	assert(seqlist);
	bigcapacity(seqlist);
	seqlist->_array[seqlist->_size] = number;
	seqlist->_size++;
}
//βɾ
void _pop_back(SeqList* seqlist)
{
	assert(seqlist);
	assert(seqlist->_array);
	assert(seqlist->_size > 0);
	seqlist->_size--;
}
//ͷ��
void front(SeqList* seqlist,int number)
{
	assert(seqlist);
	assert(seqlist->_array);
	bigcapacity(seqlist);
	for (int i = seqlist->_size; i > 0; --i)
	{
		seqlist->_array[i] = seqlist->_array[i - 1];
	}
	seqlist->_array[0] = number;
	seqlist->_size++;
}
//ͷɾ
void _pop_Front(SeqList* seqlist)
{
	assert(seqlist);
	assert(seqlist->_array);
	assert(seqlist->_size > 0);
	for (int i = 1; i < seqlist->_size; ++i)
	{
		seqlist->_array[i - 1] = seqlist->_array[i];
	}
	seqlist->_size--;
}
///�м����
void insert(SeqList* seqlist,int pos,int number)
{
	assert(seqlist);
	assert(seqlist->_array);
	assert(pos >= 0 && pos <= seqlist->_size);
	bigcapacity(seqlist);
	for (int i = seqlist->_size; i > pos; --i)
	{
		seqlist->_array[i] = seqlist->_array[i - 1];
	}
	seqlist->_array[pos] = number;
	seqlist->_size++;
}
//ɾ��pos���ڵ�λ��
void SeqListErase(SeqList *seqlist,int pos)
{
	assert(seqlist);
	assert(seqlist->_array);
	assert(seqlist->_size > 0);
	assert(pos >= 0 && pos < seqlist->_size);
	for (int i = pos; i < seqlist->_size - 1; ++i)
	{
		seqlist->_array[i] = seqlist->_array[i + 1];
	}
	seqlist->_size--;
}
void bubblesort(int *a,int length)
{
	int flag;  //����һ����ʶλ�����ж��Ƿ���ð�ݵĹ����з����˽���
	for (int i = 0; i < length - 1; ++i)
	{
		flag = 0;  //ð�ݹ����е�ÿһ�˶�Ҫ��������
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (a[j]>a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 1;   //���ĳ��ð�ݹ����з�����������ѱ�־λ��Ϊ1
			}
		}
		if (flag == 0)   //ÿһ��ð������жϱ�־λ�Ƿ����仯
			return;
	}
}
//ɾ��һ���������ظ���Ԫ�أ�Ҫ��ʱ�临�Ӷ�Ϊ0(n),�ռ临�Ӷ�Ϊ0(1)
void pop_equal_number(int *a, int length,int number)
{
	int index = 0;
	for (int i = 0; i < length; ++i)
	{
		if (a[i] != number)
		{
			a[index] = a[i];
			index++;
		}
	}
}
int main()
{
	/*int a[] = { 2, 0, 6, 4, 5, 1, 3, 9, 7, 8 };
	int length = sizeof(a) / sizeof(a[0]);
	bubblesort(a,length);
	for (auto e : a)
		cout << e << " ";
	cout << endl;*/
	int a[] = { 2, 2, 5, 9, 8, 6, 4, 2, 3, 5, 6, 1, 4, 5, 2, 6, 8 };
	int length = sizeof(a) / sizeof(a[0]);
	pop_equal_number(a, length, 2);
	for (auto e : a)
		cout << e << " ";
	cout << endl;


	/*SeqList p;
	SeqListInit(&p,100);
	_push_back(&p, 10);
	_push_back(&p, 11);
	_push_back(&p, 12);
	_push_back(&p, 13);
	_push_back(&p, 14);
	_pop_back(&p);
	front(&p, 5);
	_pop_Front(&p);
	insert(&p, 0, 100);
	SeqListErase(&p, 2);
	for (int i = 0; i < p._size; ++i)
	{
		cout << p._array[i] << "  ";
	}
	cout << endl;*/
	return 0;
}
#endif
#if 0
#include<iostream>
#include<assert.h>
using namespace std;
typedef struct Node
{
	int  value;
	struct Node* next;
}Node;
typedef struct List  //Ϊ�˱������ָ��ĳ��֣��Ž�ͷ����������
{
	Node* first;
}List;
//��ʼ��1
void ListInit(List* head)
{
	assert(head);
	head->first = nullptr;
}

//��ʼ��2
//void ListInit2(Node** p)
//{
//	*p = nullptr;
//}
//{
//	Node * p;
//	ListInit2(&p);
//}
//ͷ��
void Listpush_Front(List* head,int number)
{
	assert(head);
	Node* p = new Node;
	p->value = number;
	p->next = head->first;
	head->first = p;
}
//���粻��װͷָ��Ļ�����Ҫʹ�ö���ָ��
//void Listpush_Front(Node** head, int number)
//{
//	assert(head);
//	Node* p = new Node;
//	p->value = number;
//	p->next = *head;
//	*head = p;
//}
//ͷɾ
void ListPopFront(List* list)
{
	assert(list);
	assert(list->first);
	Node* p;
	p = list->first;
	list->first = list->first->next;
	delete p;
}
//β��
void Pushback(List* list,int number)
{
	assert(list);
	if (list->first == nullptr)   //��������û�н��
	{
		Listpush_Front(list, number);
		return;
	}
	Node* p = new Node;  //�����Ѿ���һ�������
	p->value = number;
	p->next = nullptr;
	Node* cur = list->first;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = p;
}
//βɾ
void pop_back(List* list)
{
	assert(list);
	assert(list->first);
	//���ֻ��һ���ڵ���Ҫ���⴦��
	if (list->first->next == nullptr)
	{
		pop_back(list);
		return;
	}
	Node* cur = list->first;
	while (cur->next->next != nullptr)
		cur = cur->next;
	delete cur->next;
	cur->next = nullptr;
}
//����
void deleteall(List* list)
{
	assert(list);
	assert(list->first);
	Node* cur = list->first;
	while (cur != nullptr)
	{
		list->first = list->first->next;
		delete cur;
		cur = list->first;
	}
	list->first = nullptr;
}
int main()
{
	List list;
	ListInit(&list);
	Pushback(&list, 11);
	Pushback(&list, 12);
	Pushback(&list, 13);
	Pushback(&list, 14);
	Pushback(&list, 15);
	Listpush_Front(&list, 10);
	Listpush_Front(&list, 9);
	Listpush_Front(&list, 8);
	pop_back(&list);
	pop_back(&list);
	pop_back(&list);
	ListPopFront(&list);
	ListPopFront(&list);
	ListPopFront(&list);
	deleteall(&list);
	Node* p = list.first;
	while (p != nullptr)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
	/*Node* p;
	ListInit2(&p);
	Listpush_Front(&p, 1);
	Listpush_Front(&p, 2);
	Listpush_Front(&p, 3);
	Listpush_Front(&p, 4);
	Listpush_Front(&p, 5);
	for (int i = 0; i < 5; ++i)
	{
		cout << p->value << endl;
		p = p->next;
	}*/
	return 0;
}
#endif
//#include<iostream>
//using namespace std;
//typedef struct BTNode
//{
//	int value;
//	struct BTNode* left;
//	struct BTNode* right;
//};
////�@���index�ɵ����@���������Ǹ�����������������������@����������⣬������Ϊջ֡��ԭ��
////�������ڵ�ص�ʱ���²��index������Ӱ���ϲ��index�Ӷ����´� ���������ǣ� &
//
//void CreatTree()
//{
//
//}
//int main()
//{
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
#include<stack>
#include<queue>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{
		cout << "������������" << endl;
	}
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
private:
	Node* _root;
protected:
	Node* _CreateTree(T* a, size_t n, const T invalid, size_t index)  //�@���index�ɵ����@���������Ǹ�����������������������@����������⣬������Ϊջ֡��ԭ���������ڵ�ص�ʱ���²��index������Ӱ���ϲ��index�Ӷ����´� ���������ǣ� &
	{
		//index = 0;  //ע�⣺�@�ﲻ�ܸ��±�һ����ֵ���ݹ���������
		Node* root = NULL;
		if (index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, n, invalid, ++index);    //���ֵ����⣺  ��һ��ʼд����index++�����ǳ���������ѭ����ע�ⴴ�����µ�ջ֡�ͻ�����µ�index
			root->_right = _CreateTree(a, n, invalid, ++index);
		}
		return root;
	}
	void _PrevOrder(Node* root)    //ǰ�����
	{
		if (root == NULL)       //��������
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root)    //�������
	{
		if (root == NULL)       //��������
			return;
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}
	void _PostOrder(Node* root)   //�������
	{
		if (root == NULL)        //��������
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}
	void _LevelOrder(Node* root)     // �������  ʹ�÷ǵݹ�  ����queue���Ƚ��ȳ�ԭ��                                             [*]
	{
		queue<Node*> q;
		if (root)                       //��������
			q.push(root);
		else
			return;
		while (!q.empty())
		{
			Node* cur = q.front();
			cout << cur->_data << " ";
			if (cur->_left)
				q.push(cur->_left);
			if (cur->_right)
				q.push(cur->_right);
			q.pop();    //�@��ʵ������ͨ��pop���������ߵģ�����������ڵݹ������
		}
		cout << endl;
	}
	size_t _Size(Node* root)         //�������
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)//  ���@���ݹ��еķ�������
			return 1;
		return _Size(root->_left) + _Size(root->_right) + 1;                                         //�@��ǵ�+1   ��Ϊ�и����

	}
	size_t _LeafSize(Node* root)     //��Ҷ�ӽ�����
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL&&root->_right == NULL)
			return 1;
		return _LeafSize(root->_left) + _LeafSize(root->_right);


	}
	size_t _GetKLevel(Node* root, size_t k)    //���K�������
	{
		if (root == NULL)
			return 0;
		if (k == 1)
			return 1;
		if (k > 1)
			return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);      //β�ݹ�
		else
		{
			cout << "'k' is wrong" << " ";
			return 0;
		}

	}
	size_t _Depth(Node* root)          //������������
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)
			return 1;
		size_t leftdepth = _Depth(root->_left);        //�����߽��бȽ�
		size_t rightdepth = _Depth(root->_right);
		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;               //��Ҫ����+1 �����
	}
	Node* _Find(Node* root, const T& t) //����                                                                                     [*]
	{
		/*if (root == NULL)
		return NULL;
		Node* tmp = _Find(root->_left, t);
		if (root->_data == t)
		{
		return root;
		}
		_Find(root->_right, t);*/
		if (root == NULL)
			return NULL;
		if (root->_data == t)
			return root;
		Node* tmp = _Find(root->_left, t);
		if (tmp)
			return tmp;
		return _Find(root->_right, t);
	}
	Node* _Copy(Node* root)      //����     [*]
	{
		if (root == NULL)
			return NULL;
		Node* copyroot = new Node(root->_data);
		copyroot->_left = _Copy(root->_left);
		copyroot->_right = _Copy(root->_right);
		return copyroot;
	}
	void Destory(Node* root)
	{
		if (root == NULL)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;              //�ͷŵ�ǰ���
		root = NULL;
	}
public:
	BinaryTree()              //�޲ι��캯��
		: _root(NULL)
	{
	}
	BinaryTree(T* a, size_t n, const T& invalid)  //���εĹ��캯��               //ע�⣺�޲εĵݹ��ǲ���д�ڹ��еĳ�Ա���������
	{
		size_t index = 0;     //ע���@��Ϊʲô���ǰ�index�����ó�������ʼ��0
		_root = _CreateTree(a, n, invalid, index);
	}
	BinaryTree(const BinaryTree<T>& t)                     //��������
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)             //��ֵ���������
	{
		if (_root)
			Destory(_root);
		_root = _Copy(t._root);
		return *this;
	}
	void PrevOrder()                                         //ǰ�����
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()                                            //�������
	{
		_InOrder(_root);
		cout << endl;
	}
	void  PostOrder()                                        //�������
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()                                         //�������        (�@���ò����ݹ飬���Կ��Բ����@��д)
	{
		_LevelOrder(_root);
	}
	size_t Size()                                            //������
	{
		return _Size(_root);
	}
	size_t LeafSize()                                         //Ҷ�ӽ�����
	{
		return _LeafSize(_root);
	}
	size_t GetKLevel(size_t k)                                 //K����
	{
		return _GetKLevel(_root, k);
	}
	size_t Depth()                                            //�������
	{
		return _Depth(_root);
	}
	Node* Find(const T& d)                                    //����
	{
		return _Find(_root, d);
	}
	~BinaryTree()                                             //����
	{
		Destory(_root);
		_root = NULL;
		cout << "����" << endl;
	}
};
void test()               //���������������� ���� ��������������������
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	t1.PrevOrder();
	t1.InOrder();
	t1.PostOrder();
	t1.LevelOrder();
	cout << t1.Size() << endl;
	cout << t1.LeafSize() << endl;
	cout << t1.GetKLevel(3) << endl;
	cout << t1.Find(3) << endl;
	BinaryTree<int> t2(t1);
	t2.PrevOrder();
	t2.InOrder();
	t2.PostOrder();
	t2.LevelOrder();
	cout << t2.Size() << endl;
	cout << t2.LeafSize() << endl;
	cout << t2.GetKLevel(3) << endl;
	cout << t2.Find(3) << endl;
	BinaryTree<int> t3;
	t3 = t1;
	t3.PrevOrder();
	t3.InOrder();
	t3.PostOrder();
	t3.LevelOrder();
}
int main()
{
	test();
	return 0;
}
