/*
#include<iostream>
using namespace std;
void find(int a[4][4] ,int num,int b,int c)   //�����ֱ������飬��ѯ�����֣��;�����������½ǵĽ���
{
	int p1 = 0;
	int p2 = c;
	while (p1 <= b || p2 >= 0)
	{
		if (num < a[p1][p2])
		{
			p2--;
		}
		else
		{
			if (num == a[p1++][p2])
			{
				cout << "���ҵ�" << endl;
				return;
			}
		}
	}
	cout << "δ�ҵ�" << endl;
}
int main()
{
	int a[][4] = { 0, 1, 2, 5, 2, 3, 4, 7, 4, 4, 4, 8, 5, 7, 7, 9 };
	find(a, 3,3,3);
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
void MYprintf(int *a,int *b,int La,int Lb)
{
	int *p1 = &a[0];
	int *p2 = &b[0];
	while (La > 0 && Lb > 0)
	{
		if (*p1 < *p2)
		{
			p1++;
			La--;
		}
		else if (*p1 > *p2)
		{
			p2++;
			Lb--;
		}
		else
		{
			cout << *p1 << endl;
			p1++;
			p2++;
			La--;
			Lb--;
		}
	}
}
int main()
{
	int a[] = { 2, 5, 8, 9, 12, 15, 16, 19 };
	int b[] = { 2,3, 6, 10, 12, 15, 17 };
	MYprintf(a, b,8,7);
	return 0;
}
*/
//#include<iostream>
//#include<assert.h>
//#include<stack>
//using namespace std;
//struct push   //������ṹ��
//{
//	int value;
//	push *next;
//};
//struct slist   //��������ṹ��
//{
//	push *first;
//};
//void init(slist * l)   //��ʼ������Ҳ��������������ͷ���ָ���
//{
//	assert(l != nullptr);
//	l->first = nullptr;
//}
//void add(slist * l ,int num)//β��
//{
//	push* p = new push;
//	p->value = num;	
//	p->next = nullptr;
//	if (l->first == nullptr)  //����ǵ�һ����������ݵĻ���ôֱ�Ӳ���
//	{
//		l->first = p;
//		return;
//	}
//	push * cur =l->first;  //����Ļ����������ҵ����һ�����
//	while (cur->next!=nullptr)
//	{
//		cur = cur->next;
//	}
//	cur->next = p;
//}
//bool func(stack<int>v,slist *s)
//{
//	push * p1 = s->first;
//	while (p1->next != nullptr)
//	{
//		if (p1->value != v.top())
//		{
//			return false;
//		}
//		p1 = p1->next;
//		v.pop();
//	}
//	return true;
//}
//void mystack(slist * l)
//{
//	stack<int>v;
//	push * p1 = l->first;
//	while (p1 != nullptr)
//	{
//		v.push(p1->value);
//		p1 = p1->next;
//	}
//	bool ret = func(v, l);
//	if (ret == true)
//		cout << "��������" << endl;
//	else
//		cout << "�ǻ�������" << endl;
//}
//void test()
//{
//	slist s;  //������һ������
//	init(&s);//Ȼ���ʼ��
//	add(&s, 1);
//	add(&s, 2);
//	add(&s, 3);
//	add(&s, 2);
//	add(&s, 1);
//	mystack(&s);
//}
//int main()
//{
//	test();
//	return 0;
//}
#include<iostream>
using namespace std;
struct push
{
	push * next;
	int value;
};
struct slist
{
	push* first = nullptr;
};
void add(slist * l, int num)
{
	push * p = new push;
	p->next = nullptr;
	p->value = num;
	if (l->first == nullptr)
	{
		l->first = p;
		return;
	}
	push *cur = l->first;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = p;
}
void printfs(slist * l)
{
	push *cur = l->first;
	while (cur != nullptr)
	{
		cout << cur->value << endl;
		cur = cur->next;
	}
}
void test()
{
	slist p;
	add(&p, 1);
	add(&p, 2);
	add(&p, 3);
	add(&p, 4);
	add(&p, 5);
	printfs(&p);
}
int main()
{
	test();
	return 0;
}






















