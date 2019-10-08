//#include<iostream>
//using namespace std;
///*
//void func(char *a,int k,int length)
//{
//	if (k == length)
//	{
//		cout << a << endl;
//		return;
//	}
//	for (int i = k; i < length; ++i)
//	{
//		swap(a[i], a[k]);
//		func(a, k+1, length);
//		swap(a[i], a[k]);
//	}
//}
//*/
///*
//int test(int num)
//{
//	if (num <= 1)
//		return 1;
//	return num * test(num - 1);
//}
//int test4(int num)
//{
//	if (num < 1)
//		return 0;
//	return test4(num - 1) + test(num);
//}
//int test2(int num)
//{
//	if (num <= 2)
//	{
//		return 1;
//	}
//	return test2(num - 1) + test2(num - 2);
//}
//int test3(int num)
//{
//	if (num < 1)
//		return 0;
//	return test2(num) + test3(num - 1);
//}
//*/
////class add
////{
////private:
////	static int a;
////	static int b;
////public:
////	add()
////	{
////		a += b;
////		b++;
////	}
////	int geta()
////	{
////		return a;
////	}
////};
////int add::a = 0;
////int add::b = 1;
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//	void* operator new(size_t n)
//	{
//		void* p = nullptr; p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//int main()
//{
//	List l;
//	int * p = new int[10];
//	cout << p[0] << endl;
//	memset(p, 0, 2);
//	//cout << *p << endl;
//	cout << p[0] << endl;
//	//cout << p[2] << endl;
//	return 0;
//}
////int main()
////{
////
////	//int n;
////	//cin >> n;
////	//add * p = new add[n];
////	//char a[] = "abcdf";
////	//int length = strlen(a);
////	//func(a,0,length);  // 数组的全排列
////	//int ret = test4(4);
////	//cout << ret << endl;
////	//cout << p->geta() << endl;
////	return 0;
////}
#include<iostream>
using namespace std;
class a
{
private:
	a()
	{}

};
int main()
{

	//a b;
	return 0;
}















