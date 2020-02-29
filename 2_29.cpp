//#include<vector>
//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//int main()
//{
//
//
//	vector<int> vec{ 5, 8, 9, 4, 7, 6, 1, 3, 2, 0 };
//
//	priority_queue<int,vector<int>,greater<int> > que(vec.begin(),vec.end());
//
//	cout << que.top() << endl;
//	que.pop();
//	cout << que.top() << endl;
//	/*make_heap(vec.begin(), vec.end());
//	cout << vec.front() << endl;
//	pop_heap(vec.begin(), vec.end());
//	vec.push_back(6);
//	vec.pop_back();
//	cout << vec.front() << endl;
//	cout << vec.front() << endl;*/
//	return 0;
//}

// constructing priority queues
//#include <iostream>
//#include <queue>
//using namespace std;
//
//class mycomparison
//{
//	bool reverse;
//public:
//	mycomparison(const bool& revparam = false)
//	{
//		reverse = revparam;
//	}
//	bool operator() (const int& lhs, const int&rhs) const
//	{
//		if (reverse) return (lhs>rhs);
//		else return (lhs<rhs);
//	}
//};
//
//int main()
//{
//	int myints[] = { 10, 60, 50, 20 };
//
//	priority_queue<int> first;
//	priority_queue<int> second(myints, myints + 4);
//	priority_queue< int, vector<int>, greater<int> > third(myints, myints + 4);
//
//	// using mycomparison:
//	priority_queue< int, vector<int>, mycomparison > fourth;
//
//	typedef priority_queue<int, vector<int>, mycomparison> mypq_type;
//	mypq_type fifth(mycomparison());
//	mypq_type sixth(mycomparison(true));
//
//	return 0;
//
//}
//#include <stdio.h>
//#include <queue>
//#include<functional>
//#include <iostream>
//using namespace std;
//int main(){
//	priority_queue<int, vector<int>, greater<int> > small_heap;
//	small_heap.push(2);
//	small_heap.push(3);
//	small_heap.push(5);
//	small_heap.push(0);
//	while (!small_heap.empty()){
//		cout << small_heap.top() << endl;
//		small_heap.pop();
//
//	}
//
//}

//冒泡排序：时间复杂度o(n^2),空间复杂度o(1),稳定性:稳定
//插入排序：时间复杂度o(n^2),空间复杂度o(1),稳定性:稳定
//选择排序：时间复杂度o(n^2),空间复杂度o(1),稳定性:不稳定
//归并排序：时间复杂度o(nlogn),空间复杂度o(n),稳定性：稳定
//希尔排序：
//堆排序：时间复杂度o(nlogn),空间复杂度o(1),稳定性：
//快排：时间复杂度o(nlongn),空间复杂度o(longn),稳定性：不稳定

#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* next;
};
struct List
{
	Node* head = nullptr;
};
Node* test1(List* list,int pos)
{
	if (list->head == nullptr)
		return nullptr;
	Node* cur = list->head;
	Node* z1 = nullptr;
	Node* z2 = nullptr;
	Node* x1 = nullptr;
	Node* x2 = nullptr;
	Node* c1 = nullptr;
	Node* c2 = nullptr;
	while (cur != nullptr)
	{
		if (cur->val < pos)
		{
			if (z1 == nullptr)
			{
				z1 = cur;
				z2 = cur;
			}
			else
			{
				z2->next = cur;
				z2 = z2->next;
			}
		}
		if (cur->val = pos)
		{
			if (x1 == nullptr)
			{
				x1 = cur;
				x2 = cur;
			}
			else
			{
				x2->next = cur;
				x2 = x2->next;
			}
		}
		if (cur->val > pos)
		{
			if (c1 == nullptr)
			{
				c1 = cur;
				c2 = cur;
			}
			else
			{
				c2->next = cur;
				c2 = c2->next;
			}
		}
		cur = cur->next;
	}
	if (z1 == nullptr && x1 == nullptr && c1 != nullptr)
		list->head = c1;
	else if (z1 == nullptr && x1 != nullptr && c1 == nullptr)
		list->head = x1;
	else if (z1 != nullptr && x1 == nullptr && c1 == nullptr)
		list->head = z1;
	else if (z1 == nullptr && x1 != nullptr && c1 != nullptr)
	{
		x2->next = nullptr;
		c2->next = nullptr;
		list->head = x1;
		x2->next = c1;
	}
	else if (z1 != nullptr && x1 != nullptr && c1 != nullptr)
	{
		z2 = nullptr;
		x2 = nullptr;
		c2 = nullptr;
		list->head = z1;
		z2->next = c1;
	}
	else if (z1 != nullptr && x1 == nullptr && c1 != nullptr)
	{
		z2 = nullptr;
		c2 = nullptr;
		list->head= z1;
		z2->next = c1;
	}
	else if (z1 != nullptr && x1 != nullptr && c1 == nullptr)
	{
		z2 = nullptr;
		x2 = nullptr;
		list->head = z1;
		z2->next = x1;
	}
}


Node* func2(Node* list)
{
	if (list == nullptr || list->next == nullptr)
		return list;
	Node* p = func2(list->next);
	list->next->next = list;
	list = nullptr;
	return p;
}



int main()
{
	List list;
	test1(&list, 3);
	return 0;
}
















