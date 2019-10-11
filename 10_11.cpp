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
		cout << "找到了，下标是" << ret << endl;
	else
		cout << "没找到" << endl;
	/*int a = 5;
	pa1 b = { 1, &a };
	pa2 c = { 2, &b };
	cout << (*c.p->pa) << endl;*/
	//pfunc  max;
	//max(1);
	//int(*ptr)(int, int) = test;
	//
	////这里所要说明的就是test前面加不加&，都一样
	//printf("%d", (*ptr)(1, 2));
	////(ptr)前面加不加*也都一样，甚至(***********ptr)也都没有问题ptr(1,2)也没问题
	return  0;
}
//但是又牵扯出一个问题就是函数实际是在运行的时候才进行空间的分配的，但是int(*ptr)(int, int) = test这里test还没有空间，
//那这里分配的又是什么东西？
//每个函数背后都有一张符号表，然后符号表里面记录着函数的虚地址，在函数运行的时候，就会临时的把虚地址个运行时函数的实地址关联起来
//所以说函数指针是一个假指针，所以说&，* 都是假的，加不加都可以
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
//扩容
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
//初始化
void SeqListInit(SeqList *seqlist,int capacity)
{
	assert(seqlist);
	seqlist->_array = new int[capacity];
	seqlist->_capacity = capacity;
	seqlist->_size = 0;
}
//尾插
void _push_back(SeqList* seqlist,int number)
{
	assert(seqlist);
	bigcapacity(seqlist);
	seqlist->_array[seqlist->_size] = number;
	seqlist->_size++;
}
//尾删
void _pop_back(SeqList* seqlist)
{
	assert(seqlist);
	assert(seqlist->_array);
	assert(seqlist->_size > 0);
	seqlist->_size--;
}
//头插
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
//头删
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
///中间插入
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
//删除pos所在的位置
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
	int flag;  //设置一个标识位，来判断是否在冒泡的过程中发生了交换
	for (int i = 0; i < length - 1; ++i)
	{
		flag = 0;  //冒泡过程中的每一趟都要进行置零
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (a[j]>a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 1;   //如果某趟冒泡过程中发生交换，则把标志位设为1
			}
		}
		if (flag == 0)   //每一趟冒泡完毕判断标志位是否发生变化
			return;
	}
}
//删除一个数组中重复的元素，要求时间复杂度为0(n),空间复杂度为0(1)
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
typedef struct List  //为了避免二级指针的出现，才将头结点包了起来
{
	Node* first;
}List;
//初始化1
void ListInit(List* head)
{
	assert(head);
	head->first = nullptr;
}

//初始化2
//void ListInit2(Node** p)
//{
//	*p = nullptr;
//}
//{
//	Node * p;
//	ListInit2(&p);
//}
//头插
void Listpush_Front(List* head,int number)
{
	assert(head);
	Node* p = new Node;
	p->value = number;
	p->next = head->first;
	head->first = p;
}
//假如不封装头指针的话就需要使用二级指针
//void Listpush_Front(Node** head, int number)
//{
//	assert(head);
//	Node* p = new Node;
//	p->value = number;
//	p->next = *head;
//	*head = p;
//}
//头删
void ListPopFront(List* list)
{
	assert(list);
	assert(list->first);
	Node* p;
	p = list->first;
	list->first = list->first->next;
	delete p;
}
//尾插
void Pushback(List* list,int number)
{
	assert(list);
	if (list->first == nullptr)   //链表本来就没有结点
	{
		Listpush_Front(list, number);
		return;
	}
	Node* p = new Node;  //最少已经有一个结点了
	p->value = number;
	p->next = nullptr;
	Node* cur = list->first;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = p;
}
//尾删
void pop_back(List* list)
{
	assert(list);
	assert(list->first);
	//如果只有一个节点需要特殊处理
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
//销毁
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
////這里的index由调用這个函数的那个函数里面给传进来；但是這里出现了问题，还是因为栈帧的原因，
////在往根节点回的时候，下层的index并不会影响上层的index从而导致错 误解决方案是： &
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
		cout << "构造二叉树结点" << endl;
	}
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
private:
	Node* _root;
protected:
	Node* _CreateTree(T* a, size_t n, const T invalid, size_t index)  //這里的index由调用這个函数的那个函数里面给传进来；但是這里出现了问题，还是因为栈帧的原因，在往根节点回的时候，下层的index并不会影响上层的index从而导致错 误解决方案是： &
	{
		//index = 0;  //注意：這里不能给下标一个初值，递归会出现问题
		Node* root = NULL;
		if (index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, n, invalid, ++index);    //出现的问题：  我一开始写的是index++，但是出现了无限循环，注意创建的新的栈帧就会产生新的index
			root->_right = _CreateTree(a, n, invalid, ++index);
		}
		return root;
	}
	void _PrevOrder(Node* root)    //前序遍历
	{
		if (root == NULL)       //返回条件
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root)    //中序遍历
	{
		if (root == NULL)       //返回条件
			return;
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}
	void _PostOrder(Node* root)   //后序遍历
	{
		if (root == NULL)        //返回条件
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}
	void _LevelOrder(Node* root)     // 层序遍历  使用非递归  利用queue的先进先出原则                                             [*]
	{
		queue<Node*> q;
		if (root)                       //根结点入队
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
			q.pop();    //這里实际上是通过pop让树往下走的，完成了类似于递归的作用
		}
		cout << endl;
	}
	size_t _Size(Node* root)         //求结点个数
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)//  在這个递归中的返回条件
			return 1;
		return _Size(root->_left) + _Size(root->_right) + 1;                                         //這里记得+1   因为有根结点

	}
	size_t _LeafSize(Node* root)     //求叶子结点个数
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL&&root->_right == NULL)
			return 1;
		return _LeafSize(root->_left) + _LeafSize(root->_right);


	}
	size_t _GetKLevel(Node* root, size_t k)    //求第K层结点个数
	{
		if (root == NULL)
			return 0;
		if (k == 1)
			return 1;
		if (k > 1)
			return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);      //尾递归
		else
		{
			cout << "'k' is wrong" << " ";
			return 0;
		}

	}
	size_t _Depth(Node* root)          //求二叉树的深度
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL && root->_right == NULL)
			return 1;
		size_t leftdepth = _Depth(root->_left);        //分两边进行比较
		size_t rightdepth = _Depth(root->_right);
		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;               //不要忘记+1 根结点
	}
	Node* _Find(Node* root, const T& t) //查找                                                                                     [*]
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
	Node* _Copy(Node* root)      //拷贝     [*]
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
		delete root;              //释放当前结点
		root = NULL;
	}
public:
	BinaryTree()              //无参构造函数
		: _root(NULL)
	{
	}
	BinaryTree(T* a, size_t n, const T& invalid)  //带参的构造函数               //注意：无参的递归是不能写在公有的成员函数里面的
	{
		size_t index = 0;     //注意這里为什么我们把index单独拿出来给初始化0
		_root = _CreateTree(a, n, invalid, index);
	}
	BinaryTree(const BinaryTree<T>& t)                     //拷贝构造
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)             //赋值运算符重载
	{
		if (_root)
			Destory(_root);
		_root = _Copy(t._root);
		return *this;
	}
	void PrevOrder()                                         //前序遍历
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()                                            //中序遍历
	{
		_InOrder(_root);
		cout << endl;
	}
	void  PostOrder()                                        //后序遍历
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()                                         //层序遍历        (這个用不到递归，所以可以不用這样写)
	{
		_LevelOrder(_root);
	}
	size_t Size()                                            //结点个数
	{
		return _Size(_root);
	}
	size_t LeafSize()                                         //叶子结点个数
	{
		return _LeafSize(_root);
	}
	size_t GetKLevel(size_t k)                                 //K层结点
	{
		return _GetKLevel(_root, k);
	}
	size_t Depth()                                            //树的深度
	{
		return _Depth(_root);
	}
	Node* Find(const T& d)                                    //查找
	{
		return _Find(_root, d);
	}
	~BinaryTree()                                             //析构
	{
		Destory(_root);
		_root = NULL;
		cout << "析构" << endl;
	}
};
void test()               //———————— 测试 ——————————
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
