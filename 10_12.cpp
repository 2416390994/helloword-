//#include<iostream>
//#include<assert.h>
//using namespace std;
////˫���ͷѭ������
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
////ͷ��
//void List_Push_Front(List* list,int number)
//{
//	assert(list);
//	Node* p = new Node;
//	p->value = number;
//	//ԭ����Ϊͷ�������������������ͨ���ٴ���֮���ֲ�û���κ����⣬���Կ���ֱ��ʹ�������ͳһ�Ĵ���
//	//if (list->first->next == list->first)    //�����ͷ����Ҫ���ǲ����һ������ʱ��
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
////β��
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
////ͷɾ
//void List_Pop_Front(List* list)
//{
//	assert(list);
//	assert(list->first->next != list->first);
//	//֮ǰ������д�ģ����Ǽ�������д�Ļ������������Ҫ��������㣬
//	//����ֻʣ��һ�����Ļ�����Ҫ����������¿��ǣ�̫�鷳��
//	//Node* p = list->first->next->next;   
//	//delete list->first->next;
//	//list->first->next = p;
//	//p->before = list->first;
//	Node* p = list->first->next;
//	list->first->next = p->next;
//	p->next->before = list->first;
//	delete p;
//	//����д��ûë���ˣ�����ֻʣ��һ���������������㶨�����Ҳ��ÿ����������
//}
////βɾ
//void List_Pop_Back(List* list)
//{
//	assert(list);
//	assert(list->first->before != list->first);
//	//βɾ��ͷɾҲ����ͬ�����
//	//Node* p = list->first->before->before;
//	//delete list->first->before;
//	//list->first->before = p;
//	//p->next = list->first;
//	Node* p = list->first->before;
//	list->first->before = p->before;
//	p->before->next = list->first;
//	delete p;
//}
////���٣���Ϊ����
////һ���ǽ������е���Ч�ڵ�ɾ������������ͷ��㻹��
////һ���ǽ���������������ȫɾ��
////��һ���������
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
////�ڶ��ֳ�����������
//void List_delete(List* list)
//{
//	List_clear(list);
//	delete list->first;
//	list->first = nullptr;
//}
////�����⣺ɾ�����и���value�����н��
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
////������м�������
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
 //������Ҫ������������
 //1.���紫�����������������һ����ȫ���ǿ���ô��
 //2.�൱�ڲ��ϵĸ������¶����������β�壬β���ʱ��Ҫ���Ǽ���Ҫ�����Ԫ���ǵ�һ����ô��
 //3.����Ĳ��ǵ�һ����ô��
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)   //�������1
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode* L1 = l1;
		ListNode* L2 = l2;
		ListNode* newlist = nullptr;
		ListNode* newlist_last = nullptr;   //��������������β��������ÿ��β���ʱ��Ҫ���±�������

		while (L1 != nullptr && L2 != nullptr)   //��������������һ��Ϊ�յ�ʱ����ֹͣѭ��
		{
			if (L1->val <= L2->val)
			{
				if (newlist_last)   //�������Ĳ��ǵ�һ��Ԫ��
				{
					newlist_last->next = L1;
					newlist_last = L1;
				}
				else     //���������ǵ�һ��Ԫ��
				{
					newlist = L1;
					newlist_last = L1;
				}
				L1 = L1->next;    //����������
			}
			else
			{
				if (newlist_last)    //�������Ĳ��ǵ�һ��Ԫ��
				{
					newlist_last->next = L2;
					newlist_last = L2;
				}
				else              //���������ǵ�һ��Ԫ��
				{
					newlist = L2;
					newlist_last = L2;
				}
				L2 = L2->next;        //����������
			}
		}
		if (L1 != nullptr)   //����ѭ����֮��ض���һ��������Ϊ�գ�����������Ͼͺ���
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