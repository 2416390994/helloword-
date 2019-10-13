#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
};
struct List
{
	ListNode* head ;
};
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* p1 = nullptr;
		ListNode* p2 = nullptr;
		ListNode* p3 = pHead;
		ListNode* p4 = p1;
		ListNode* p5 = p2;
		while (p3 != nullptr)
		{
			if (p3->val < x)
			{
				if (p1 == nullptr)
				{
					p1 = p3;
					p4 = p1;
				}
				else
				{
					p4->next = p3;
					p4 = p4->next;
				}
			}
			else if (p3->val >= x)
			{
				if (p2 == nullptr)
				{
					p2 = p3;
					p5 = p2;
				}
				else
				{
					p5->next = p3;
					p5 = p5->next;
				}
			}
			p3 = p3->next;
		}
		p4->next = nullptr;
		p5->next = nullptr;
		/*for (ListNode* p = p1; p != nullptr; p = p->next)
			cout << p->val << endl;
		for (ListNode* p = p2; p != nullptr; p = p->next)
			cout << p->val << endl;*/
		p4->next = p2;
		pHead = p1;
		return pHead;
	}
	void _push_back(ListNode** list, int x)
	{
		ListNode* p = new ListNode;
		p->val = x;
		if (*list == nullptr)
		{
			*list = p;
			p->next = nullptr;
			return;
		}
		ListNode* cur = *list;
		*list = p;
		p->next = cur;
	}
int main()
{
	ListNode* list = nullptr;
	_push_back(&list, 1);
	_push_back(&list, 5);
	_push_back(&list, 3);
	_push_back(&list, 6);
	_push_back(&list, 9);
	_push_back(&list, 2);
	_push_back(&list, 7);
	_push_back(&list, 5);
	ListNode * cur = list;
	ListNode* ret = partition(list, 5);
	cur = ret;
	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	return 0;
}