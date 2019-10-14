#include<iostream>
using namespace std;
#if 0
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	ListNode* p1_pre = nullptr;
	ListNode* p1 = pHead;
	ListNode* p2 = pHead->next;
	ListNode* result = pHead;
	while (p2 != nullptr)
	{
		if (p1->val != p2->val)
		{
			p1_pre = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else
		{
			while (p2!=nullptr&&p2->val==p1->val)
				p2 = p2->next;
			if (p1_pre==nullptr)
				result = p2;
			else
				p2->next = p2;
			p1 = p2;
			if (p2 != nullptr)
				p2 = p2->next;
		}
	}
	return result;
}

ListNode* str(ListNode* A, ListNode* B)
{
	if (A == nullptr)
		return B;
	if (B == nullptr)
		return A;
	ListNode* p1 = A;    //����A����
	ListNode* p2 = B;   //����B����
	ListNode* p3 = nullptr;    //��¼�������ͷ
	ListNode* p4 = nullptr;   //��¼�������β
	while (p1 != nullptr&&p2 != nullptr)
	{
		if (p1->val <= p2->val)
		{
			ListNode* next = p1->next;  //��ʱ����A�������һ�����
			if (p3 == nullptr)
			{
				p3 = p1;
				p4 = p1;
			}
			else
			{
				p4->next = p1;
				p4 = p1;
			}
			p1 = next;
		}
		else
		{
			ListNode* next = p2->next;//��ʱ����B�������һ�����
			if (p4 == nullptr)
			{
				p3 = p2;
				p4 = p2;
			}
			else
			{
				p4->next = p2;
				p4 = p2;
			}
			p2 = next;
		}
	}
	if (A == nullptr)
		p4->next = p2;
	else
		p4->next = p1;
	return p3;
}
#endif
int main()
{

	return 0;
}
