#include<iostream>
#include<vector>
#include<string>
using namespace std;
//struct Node
//{
//	Node* next;
//	int val;
//};
//
//Node* func1(Node* head)
//{
//	Node* fast = head;
//	Node* slow = head;
//	while (fast != nullptr && fast->next != nullptr)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//		if (fast == slow)
//			return fast;
//	}
//	return nullptr;
//}
//
//Node* func2(Node* head)
//{
//	if (head != nullptr)
//	{
//		Node* ms = func1(head);
//		if (ms != nullptr)
//		{
//			Node* p = head;
//			while (p != ms)
//			{
//					p = p->next;
//					ms = ms->next;
//			}
//			return ms;
//		}
//	}
//	return nullptr;
//}
//
//int func3(vector<int>& vec,int val)
//{
//	int L = 0;
//	int R = vec.size() - 1;
//	int  M = 0;
//	while (L <= R)
//	{
//		M = (R + L) / 2;
//		if (vec[M] < val)
//		{
//			L = M + 1;
//		}
//		else if (vec[M] > val)
//		{
//			R = M - 1;
//		}
//		else
//			return M;
//	}
//}
//
//class my_queue
//{
//public:
//	my_queue(int size)
//		:queue(new int[size])
//		, size(0)
//		, capacity(size)
//		, back(0)
//		, front(0)
//	{}
//	bool empty()
//	{
//		return (size == capacity);
//	}
//	void push(int num)
//	{
//		if (size == capacity)
//			return;
//		queue[back] = num;
//		back = (back + 1) % capacity;
//		size++;
//	}
//	void pop()
//	{
//		if (size == capacity)
//			return;
//		front = (front + 1) % capacity;
//		size--;
//	}
//	int myfront()
//	{
//		if (size == 0)
//			return -1;
//		return queue[front];
//	}
//	int myback()
//	{
//		if (size == 0)
//			return -1;
//		return queue[(back - 1 + capacity) % capacity];
//	}
//private:
//	int size;
//	int capacity;
//	int* queue;
//	int back;
//	int front;
//};
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int num)
//		:val(num)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//};
//bool func(TreeNode* p1,TreeNode* p2)
//{
//	if (p1 == nullptr && p2 == nullptr)
//		return true;
//	if (p1 == nullptr || p2 == nullptr)
//		return true;
//	return p1->val == p2->val && func(p1->left, p2->left) && func(p1->right, p2->right);
//}

void func(string s,int from,int to)
{
	if (to == from)
	{
		cout << s << endl;
		return;
	}
	for (int i = from; i < s.size(); ++i)
	{
		swap(s[from], s[i]);
		func(s, from + 1, to);
		swap(s[from], s[i]);
	}
}
int main()
{
	string s = "abc";
	func(s, 0, 3);
	return 0;
}













//class A
//{
//public:
//	A()
//	{
//	
//	}
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	int a;
//};
//class B
//{
//public:
//	static B* func()
//	{
//		return  new B;
//	}
//	int c;
//private:
//	B()
//	{
//
//	}
//	int a;
//
//};
//int main()
//{
//	B* c = B::func();
//	return 0;
//}