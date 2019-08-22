/*
#include<iostream>
#include<map>
using namespace std;
struct Node   //结点结构
{
	int value;
	Node * next;
	Node * rand;
	Node(int data)   //默认构造函数，所以在申请的时候就必须设置值
	{
		value = data;
	}
};
Node* FindConnect(map<Node*, Node*>&v,Node * l)    //返回拷贝完成链表的头结点
{
	Node *cur = l;   //首先从头开始，先给next绑定关系
	while (cur->next != nullptr)//为了防止越界，这里在cur->next==nullptr时停止
	{
		(*(v.find(cur))).second->next = (*(v.find(cur->next))).second;   //越界原因就是内部还有一次cur->next
		cur = cur->next;
	}
	(*(v.find(cur))).second->next = nullptr;  //然后在外部对拷贝的链表的最后一个节点进行绑定空
	cur = l;   //绑定rand关系也是同样的道理
	while (cur != nullptr)   //但是这里不需要->next是因为内部的rand本来就是循环指向的，不存在越界
	{
		(*(v.find(cur))).second->rand = (*(v.find(cur->rand))).second;
		cur = cur->next;
	}
	cur = l;
	map<Node*, Node*>::iterator it3 = v.find(cur);   //拿到拷贝好的返回
	return (*it3).second;
}
void getmap(Node * l)   //主要操作函数中
{
	map<Node*, Node*>v;    //先搞一个map容器
	Node * cur = l;
	while (cur != nullptr)    //然后将原链表进行挨个拷贝，然后在map容器中绑定关系
	{
		Node * p = new Node(cur->value);//为结点申请空间
		v.insert(make_pair(cur, p));   //这里绑定的是指针，所以map类型使用的是Node*
		cur = cur->next;
	}
	Node * p = FindConnect(v , l);   //执行分函数，函数会返回拷贝好的链表的头结点
	cur = p;         //以下是检验内容，检验链表next关系是否拷贝完成
	while (cur != nullptr)
	{
		cout << cur->value;
		cur = cur->next;
	}
	cout << endl;
	cur = p;         //以下是检验内容，检验链表rand是否拷贝完成
	while (cur != nullptr)
	{
		cout << cur->rand->value;
		cur = cur->next;
	}
	cout << endl;
}
void test()
{
	Node s1(0);   //建立结点，插入数据
	Node s2(1);
	Node s3(2);
	Node s4(3);
	Node s5(4);
	Node s6(5);
	s1.next = &s2;
	s1.next->next = &s3;
	s1.next->next->next = &s4;
	s1.next->next->next->next = &s5;
	s1.next->next->next->next->next = &s6;
	s1.next->next->next->next->next->next =nullptr;
	s1.rand = &s3;//因为这个是不确定的所以不依靠函数，而是手动 绑定关系
	s2.rand = &s1;
	s3.rand = &s5;
	s4.rand = &s6;
	s5.rand = &s4;
	s6.rand = &s2;
	getmap(&s1);   //执行主要操作函数
}
int main()
{
	test();
	return 0;
}
*/



















