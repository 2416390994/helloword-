//#include<iostream>
//#include<assert.h>
//using namespace std;
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int num)
//		:val(num)
//		, next(nullptr)
//	{}
//};
//struct List
//{
//	Node* first;
//};
//void init(List* list)
//{
//	assert(list->first);
//	list->first = nullptr;
//}
//
//void push_back(List* list, int num)
//{
//	Node* p = new Node(num);
//	if (list->first == nullptr)
//	{
//		list->first = p;
//	}
//	else
//	{
//		Node* cur = list->first;
//		while (cur->next != nullptr)
//		{
//			cur = cur->next;
//		}
//		cur->next = p;
//	}
//}
//Node* dada(Node* head)
//{
//	if (head == nullptr || head->next == nullptr)
//		return head;
//	Node* p = dada(head->next);
//	head->next->next = head;
//	head->next = nullptr;
//	return p;
//}
//void func()
//{
//	List list;
//	init(&list);
//	push_back(&list, 1);
//	push_back(&list, 2);
//	push_back(&list, 3);
//	push_back(&list, 4);
//	push_back(&list, 5);
//	push_back(&list, 6);
//	push_back(&list, 7);
//	Node* p = list.first;
//	while (p != nullptr)
//	{
//		cout << p->val << endl;
//		p = p->next;
//	}
//	Node* s = dada(list.first);
//	while (s != nullptr)
//	{
//		cout << s->val << endl;
//		s = s->next;
//	}
//}
//void mymemset(void* s,int c,size_t n)
//{
//	char* p = (char*) s;
//	while (n--)
//	{
//		*p = c;
//		p++;
//	}
//}
//void mymemcpy(void* s,const void* c,size_t n)
//{
//	char* p1 = (char*)s;
//	char* p2 = (char*)c;
//	while (n--)
//	{
//		*p1 = *p2;
//		p1++;
//		p2++;
//	}
//}
//void mystrcpy(char* s,const char* c)
//{
//	char* p1 = (char*)s;
//	char* p2 = (char*)c;
//	while (*p1++ = *p2++)
//	{
//	}
//}
//void func2()
//{
//	char c;
//	while ((c = getchar()) != '\n')
//	{
//		putchar(c);
//	}
//
//}
//
//int main()
//{
//	func2();
//	char* s = "asdfghjkl";
//	//mymemset(s, 65, 10);
//	
//	char* c = new char[strlen(s)];
//	//mymemcpy(c, s, 10);
//	mystrcpy(c, s);
//	cout << c << endl;
//
//
//
//	/*int s = 1;
//	char* p = (char*)&s;
//	cout << *p << endl;*/
//	//func();
//	/*int b[][2][2][2] = { 0 };
//	int a[10][10] = { 0 };
//	cout << a << endl;
//	cout << a + 0 << endl;
//	cout << a + 1 << endl;
//	cout << a[0] + 1 << endl;
//	cout << a[0] + 2 << endl;
//	cout << a[0][0] + 1 << endl;
//	cout << a[0][0] + 2 << endl;*/
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include<iostream>
using namespace std;

extern int errno;

int main()
{
	FILE * pf;
	int errnum;
	pf = fopen("1.txt", "w");
	if (pf == NULL)
	{
		errnum = errno;
		fprintf(stderr, "错误号: %d\n", errno);
		perror("通过 perror 输出错误");
		fprintf(stderr, "打开文件错误: %s\n", strerror(errnum));
	}
	else
	{
		fclose(pf);
	}
	return 0;
}

