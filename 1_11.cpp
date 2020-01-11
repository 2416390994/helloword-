//#include<iostream>
//#include<vector>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//int func(ListNode* l1)
//{
//	unsigned long long ret = 0;
//	if (l1->next)
//	{
//		ret = func(l1->next);
//	}
//	return (ret * 10) + l1->val;
//}
//
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//	vector<int> vec1;
//	vector<int> vec2;
//	ListNode* cur = l1;
//	while (cur != nullptr)
//	{
//		vec1.push_back(cur->val);
//		cur = cur->next;
//	}
//	cur = l2;
//	while (cur != nullptr)
//	{
//		vec2.push_back(cur->val);
//		cur = cur->next;
//	}
//	if (vec1.size() < vec2.size())
//	{
//		swap(vec1, vec2);
//	}
//	//reverse(vec1.begin(), vec1.end());
//	//reverse(vec2.begin(), vec2.end());
//	vector<int> vec3;
//	vec3.resize(vec1.size() + 1);
//	int size1 = vec1.size();
//	int size2 = vec2.size();
//	int i = 0;
//	int flag = 0;
//	while (i < size1)
//	{
//		if (i < size2)
//		{
//			int ret = vec1[i] + vec2[i] + flag;
//			flag = 0;
//			if (ret >= 10)
//			{
//				vec3[i] = ret % 10;
//				flag = 1;
//			}
//			else
//				vec3[i] = ret;
//		}
//		else
//		{
//			int ret = vec1[i] + flag;
//			flag = 0;
//			if (ret >= 10)
//			{
//				vec3[i] = ret % 10;
//				flag = 1;
//			}
//			else
//				vec3[i] = ret;
//		}
//		i++;
//	}
//	if (flag == 1)
//	{
//		vec3[i] = 1;
//	}
//	else
//		vec3.erase(vec3.end() - 1);
//	//reverse(vec3.begin(), vec3.end());
//	ListNode* p = new ListNode(vec3[0]);
//	ListNode* p1 = p;
//	for (int i = 1; i < vec3.size(); ++i)
//	{
//		p1->next = new ListNode(vec3[i]);
//		p1 = p1->next;
//	}
//	p1->next = nullptr;
//	return p;
//}
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     ListNode *next;
//*     ListNode(int x) : val(x), next(NULL) {}
//* };
//*/
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		vector<int> vec1;
//		vector<int> vec2;
//		ListNode* cur = l1;
//		while (cur != nullptr)
//		{
//			vec1.push_back(cur->val);
//			cur = cur->next;
//		}
//		cur = l2;
//		while (cur != nullptr)
//		{
//			vec2.push_back(cur->val);
//			cur = cur->next;
//		}
//		if (vec1.size() < vec2.size())
//		{
//			swap(vec1, vec2);
//		}
//		vector<int> vec3;
//		vec3.resize(vec1.size() + 1);
//		int size1 = vec1.size();
//		int size2 = vec2.size();
//		int i = 0;
//		int flag = 0;
//		while (i < size1)
//		{
//			if (i < size2)
//			{
//				int ret = vec1[i] + vec2[i] + flag;
//				flag = 0;
//				if (ret >= 10)
//				{
//					vec3[i] = ret % 10;
//					flag = 1;
//				}
//				else
//					vec3[i] = ret;
//			}
//			else
//			{
//				int ret = vec1[i] + flag;
//				flag = 0;
//				if (ret >= 10)
//				{
//					vec3[i] = ret % 10;
//					flag = 1;
//				}
//				else
//					vec3[i] = ret;
//			}
//			i++;
//		}
//		if (flag == 1)
//		{
//			vec3[i] = 1;
//		}
//		else
//			vec3.erase(vec3.end() - 1);
//		ListNode* p = new ListNode(vec3[0]);
//		ListNode* p1 = p;
//		for (int i = 1; i < vec3.size(); ++i)
//		{
//			p1->next = new ListNode(vec3[i]);
//			p1 = p1->next;
//		}
//		p1->next = nullptr;
//		return p;
//	}
//};
//
//
//
//int main()
//{
//	ListNode* p1 = new ListNode(2);
//	ListNode* p2 = new ListNode(4);
//	ListNode* p3 = new ListNode(3);
//	ListNode* p4= new ListNode(5);
//	ListNode* p5 = new ListNode(6);
//	ListNode* p6 = new ListNode(4);
//	/*
//	ListNode* p7 = new ListNode(9);
//	ListNode* p8 = new ListNode(9);
//	ListNode* p9 = new ListNode(9);
//	ListNode* p10 = new ListNode(9);*/
//	p1->next = p2;
//	p2->next = p3;
//	p3->next = nullptr;
//	p4->next = p5;
//	p5->next = p6;
//	p6->next = nullptr;
//	/*p6->next = p7;
//	p7->next = p8;
//	p8->next = p9;*/
//	//p9->next = nullptr;
//	//p9->next = p10;
//	//p10->next = nullptr;
//	ListNode * p = addTwoNumbers(p1, p4);
//
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	char _ch;
	vector<char> vec;
	Node* next;
	Node(char ch)
	{
		_ch = ch;
		vec.reserve(26);
		next = nullptr;
	}
};
void func(string str)
{
	Node* p = nullptr;
	for (int i = 0; i < str.size(); ++i)
	{
		if (i == 0)
		{
			p = new Node(str[0]);
		}
		for (int j = )
	}

}
int main()
{

	return 0;
}