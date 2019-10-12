//#include<iostream>
//#include<assert.h>
//using namespace std;
////双向带头循环链表
//typedef struct Node
//{
//	int value;
//	struct Node* next;
//	struct Node* before;
//}Node;
//typedef struct List
//{
//	Node* first;
//}List;
//void ListInit(List* list)
//{
//	assert(list);
//	assert(list->first);
//	list->first = new Node;
//	list->first->next = list->first;
//	list->first->before = list->first;
//}
////头插
//void List_Push_Front(List* list,int number)
//{
//	assert(list);
//	Node* p = new Node;
//	p->value = number;
//	//原本以为头插会存在特殊情况，但是通过抠代码之后发现并没有任何问题，所以可以直接使用下面的统一的代码
//	//if (list->first->next == list->first)    //链表的头插需要考虑插入第一个结点的时候
//	//{
//	//	list->first->next = p;
//	//	list->first->before = p;
//	//	p->before = list->first;
//	//	p->next = list->first;
//	//	return;
//	//}                          
//	p->before = list->first;   
//	p->next = list->first->next;
//	list->first->next->before = p;
//	list->first->next = p;
//}
////尾插
//void List_Push_Back(List* list, int number)
//{
//	assert(list);
//	Node* p = new Node;
//	p->value = number;
//	p->next = list->first;
//	p->before = list->first->before;
//	list->first->before->next = p;
//	list->first->before = p;
//}
////头删
//void List_Pop_Front(List* list)
//{
//	assert(list);
//	assert(list->first->next != list->first);
//	//之前是这样写的，但是加入这样写的话你的链表最少要有两个结点，
//	//假如只剩下一个结点的话就需要特殊情况重新考虑，太麻烦了
//	//Node* p = list->first->next->next;   
//	//delete list->first->next;
//	//list->first->next = p;
//	//p->before = list->first;
//	Node* p = list->first->next;
//	list->first->next = p->next;
//	p->next->before = list->first;
//	delete p;
//	//这样写就没毛病了，就算只剩下一个结点可以以完美搞定，并且不用考虑特殊情况
//}
////尾删
//void List_Pop_Back(List* list)
//{
//	assert(list);
//	assert(list->first->before != list->first);
//	//尾删和头删也是相同的情况
//	//Node* p = list->first->before->before;
//	//delete list->first->before;
//	//list->first->before = p;
//	//p->next = list->first;
//	Node* p = list->first->before;
//	list->first->before = p->before;
//	p->before->next = list->first;
//	delete p;
//}
////销毁：分为两种
////一个是将链表中的有效节点删除，但是链表头结点还在
////一种是将所创建的链表完全删除
////第一种清空链表
//void List_clear(List* list)
//{
//	Node* cur;
//	Node* p = list->first->next;
//	while (p != list->first)
//	{
//		cur = p->next;
//		delete p;
//		p = cur;
//	}
//	list->first->before = list->first->next = list->first;
//}
////第二种彻底销毁链表
//void List_delete(List* list)
//{
//	List_clear(list);
//	delete list->first;
//	list->first = nullptr;
//}
////面试题：删除表中给定value的所有结点
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* removeElements(struct ListNode* head, int number)
//{
//	ListNode* p = head;
//	ListNode* p2 = head->next;
//	while (p2 != nullptr)
//	{
//		if (p2->val == number)
//		{
//			p->next = p2->next;
//			delete p2;
//			p2 = p->next;
//		}
//		else
//		{
//			p = p2;
//			p2 = p2->next;
//		}
//	}
//	if (head->val == number)
//	{
//		ListNode* p = head;
//		head = head->next;
//		delete p;
//	}
//	return head;
//}
////链表的中间结点问题
//
//int main()
//{
//	List list;
//	ListInit(&list);
//	List_Push_Front(&list, 1);
//	List_Push_Front(&list, 2);
//	List_Push_Front(&list, 3);
//	List_Push_Front(&list, 4);
//	List_Push_Front(&list, 5);
//	List_Push_Back(&list, 10);
//	List_Push_Back(&list, 11);
//	List_Push_Back(&list, 12);
//	List_Push_Back(&list, 13);
//	List_Pop_Front(&list);
//	List_Pop_Front(&list);
//	List_Pop_Back(&list);
//	List_Pop_Back(&list);
//	Node* p = list.first->next;
//	while (p!= list.first)
//	{
//		cout << p->value << " ";
//		p = p->next;
//	}
//	cout << endl;
//	return  0;
//}

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr)
	 {}
 };
 //这里需要考虑三个问题
 //1.假如传进来的两个链表就有一个或全部是空怎么办
 //2.相当于不断的给我们新定义的链表做尾插，尾插的时候要考虑假如要插入的元素是第一个怎么办
 //3.插入的不是第一个怎么办
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)   //解决问题1
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode* L1 = l1;
		ListNode* L2 = l2;
		ListNode* newlist = nullptr;
		ListNode* newlist_last = nullptr;   //用来标记新链表的尾，来避免每次尾插的时候要重新遍历链表

		while (L1 != nullptr && L2 != nullptr)   //当两个链表中有一个为空的时候则停止循环
		{
			if (L1->val <= L2->val)
			{
				if (newlist_last)   //假如插入的不是第一个元素
				{
					newlist_last->next = L1;
					newlist_last = L1;
				}
				else     //假如插入的是第一个元素
				{
					newlist = L1;
					newlist_last = L1;
				}
				L1 = L1->next;    //链表往后走
			}
			else
			{
				if (newlist_last)    //假如插入的不是第一个元素
				{
					newlist_last->next = L2;
					newlist_last = L2;
				}
				else              //假如插入的是第一个元素
				{
					newlist = L2;
					newlist_last = L2;
				}
				L2 = L2->next;        //链表往后走
			}
		}
		if (L1 != nullptr)   //上面循环完之后必定有一个链表还不为空，让新链表接上就好了
		{
			newlist_last->next = L1;
		}
		else
		{
			newlist_last->next = L2;
		}
		return newlist;
	}
};