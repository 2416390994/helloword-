//#include<iostream>
//using namespace std;
//namespace vs
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			, count(nullptr)  //如果刚开始资源指向空，就让资源计数也为空
//		{
//			if (_ptr)
//				count =new int(1);
//		}
//		~shared_ptr()
//		{
//			if (_ptr && --(*count) == 0)
//			{
//				delete _ptr;
//				_ptr = nullptr;
//				delete count;
//				count = nullptr;
//			}
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		shared_ptr(shared_ptr<T>& sp)
//			:_ptr(sp._ptr)
//			, count(sp.count)
//		{
//			if (_ptr)
//				++(*count);
//		}
//		shared_ptr<T>& operator=(shared_ptr<T>& sp)
//		{
//			if (this != &sp)
//			{
//				if (_ptr && --(*count) == 0)
//				{
//					delete sp._ptr;
//					delete sp.count;
//				}
//				_ptr = sp._ptr;
//				count = sp.count;
//				if (_ptr)
//					++(*count);
//			}
//			return *this;
//		}
//		int use_count()
//		{
//			return *count;
//		}
//	private:
//		T* _ptr;
//		int *count;
//	};
//}
//void test()
//{
//	vs::shared_ptr<int> p1 = new int(10);
//	cout << p1.use_count() << endl;
//	vs::shared_ptr<int> p2(p1);
//	cout << p2.use_count() << endl;
//	vs::shared_ptr<int> p3;
//	p3 = p1;
//	cout << p3.use_count() << endl;
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<memory>
//using namespace std;
//struct ListNode
//{
//	ListNode(int data = 0)
//	:_pre(nullptr)
//	, _next(nullptr)
//	, _data(data)
//	{
//		cout << "ListNode" << endl;
//	}
//	~ListNode()
//	{
//		cout << "~ListNode" << endl;
//	}
//	shared_ptr<ListNode> _pre;
//	shared_ptr<ListNode> _next;
//	int _data;
//};
//void Test()
//{
//	shared_ptr<ListNode> sp1(new ListNode(10));
//	shared_ptr<ListNode> sp2(new ListNode(20));
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	sp1->_next = sp2;  //这两句代码属于循环引用
//	sp2->_pre = sp1;
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//}
//struct ListNode
//{
//	ListNode(int data = 0)
//	:_data(data)
//	{
//		cout << "ListNode" << endl;
//	}
//	~ListNode()
//	{
//		cout << "~ListNode" << endl;
//	}
//	weak_ptr<ListNode> _pre;
//	weak_ptr<ListNode> _next;
//	int _data;
//};
//void Test()
//{
//	shared_ptr<ListNode> sp1(new ListNode(10));
//	shared_ptr<ListNode> sp2(new ListNode(20));
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	sp1->_next = sp2;  //这两句代码属于循环引用
//	sp2->_pre = sp1;
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//#include<iostream>
//#include<assert.h>
//using namespace std;
//
//	template<class T>
//	struct Node
//	{
//		Node()
//		{}
//		Node(T c)
//		:value(c)
//		, next(nullptr)
//		{}
//		Node* next;
//		T value;
//	};
//	template<class T>
//	struct List
//	{
//		Node<T>* head;
//	};
//	template<class T>
//	void InitList(List<T>& list)
//	{
//		assert(list.head);
//		list.head = nullptr;
//	}
//	template<class T>
//	void Head(List<T>& list,T c)
//	{
//		Node<T>* p = new Node<T>(c);
//		if (list.head == nullptr)
//		{
//			list.head = p;
//			return;
//		}
//		Node<T>* sp = list.head;
//		list.head = p;
//		p->next = sp;
//	}
//	void test()
//	{
//		List<int> list;
//		InitList(list);
//		Head(list, 1);
//		Head(list, 2);
//		Head(list, 3);
//		Node<int>* ps;
//		ps = list.head;
//		while (ps != nullptr)
//		{
//			cout << ps->value << endl;
//			ps = ps->next;
//		}
//	}
//	int main()
//	{
//		test();
//		return 0;
//	}

#include<iostream>
#include<stack>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	TreeNode(int c = 0)
		:value(c)
		, left(nullptr)
		, right(nullptr)
	{}
	int value;
};
void xianxubianli(TreeNode*& tree)
{
	if (tree == nullptr)
		return;
	stack<TreeNode*> sta;
	sta.push(tree);
	while (!sta.empty())
	{
		tree = sta.top();
		sta.pop();
		cout << tree->value << " ";
		if (tree->right != nullptr)
			sta.push(tree->right);
		if (tree->left != nullptr)
			sta.push(tree->left);
	}
	return;
}
int main()
{
	TreeNode* tree = new TreeNode;
	TreeNode* right1 = new TreeNode(1);
	TreeNode* left1 = new TreeNode(2);
	TreeNode* right2 = new TreeNode(3);
	TreeNode* left2 = new TreeNode(4);
	TreeNode* right3 = new TreeNode(5);
	TreeNode* left3 = new TreeNode(6);
	tree->left = left1;
	tree->right = right1;
	left1->left = left2;
	left1->right = right2;
	right1->left = left3;
	right1->right = right3;
	xianxubianli(tree);
	return 0;
}