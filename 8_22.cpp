/*
#include<iostream>
#include<map>
using namespace std;
struct Node   //���ṹ
{
	int value;
	Node * next;
	Node * rand;
	Node(int data)   //Ĭ�Ϲ��캯���������������ʱ��ͱ�������ֵ
	{
		value = data;
	}
};
Node* FindConnect(map<Node*, Node*>&v,Node * l)    //���ؿ�����������ͷ���
{
	Node *cur = l;   //���ȴ�ͷ��ʼ���ȸ�next�󶨹�ϵ
	while (cur->next != nullptr)//Ϊ�˷�ֹԽ�磬������cur->next==nullptrʱֹͣ
	{
		(*(v.find(cur))).second->next = (*(v.find(cur->next))).second;   //Խ��ԭ������ڲ�����һ��cur->next
		cur = cur->next;
	}
	(*(v.find(cur))).second->next = nullptr;  //Ȼ�����ⲿ�Կ�������������һ���ڵ���а󶨿�
	cur = l;   //��rand��ϵҲ��ͬ���ĵ���
	while (cur != nullptr)   //�������ﲻ��Ҫ->next����Ϊ�ڲ���rand��������ѭ��ָ��ģ�������Խ��
	{
		(*(v.find(cur))).second->rand = (*(v.find(cur->rand))).second;
		cur = cur->next;
	}
	cur = l;
	map<Node*, Node*>::iterator it3 = v.find(cur);   //�õ������õķ���
	return (*it3).second;
}
void getmap(Node * l)   //��Ҫ����������
{
	map<Node*, Node*>v;    //�ȸ�һ��map����
	Node * cur = l;
	while (cur != nullptr)    //Ȼ��ԭ������а���������Ȼ����map�����а󶨹�ϵ
	{
		Node * p = new Node(cur->value);//Ϊ�������ռ�
		v.insert(make_pair(cur, p));   //����󶨵���ָ�룬����map����ʹ�õ���Node*
		cur = cur->next;
	}
	Node * p = FindConnect(v , l);   //ִ�зֺ����������᷵�ؿ����õ������ͷ���
	cur = p;         //�����Ǽ������ݣ���������next��ϵ�Ƿ񿽱����
	while (cur != nullptr)
	{
		cout << cur->value;
		cur = cur->next;
	}
	cout << endl;
	cur = p;         //�����Ǽ������ݣ���������rand�Ƿ񿽱����
	while (cur != nullptr)
	{
		cout << cur->rand->value;
		cur = cur->next;
	}
	cout << endl;
}
void test()
{
	Node s1(0);   //������㣬��������
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
	s1.rand = &s3;//��Ϊ����ǲ�ȷ�������Բ����������������ֶ� �󶨹�ϵ
	s2.rand = &s1;
	s3.rand = &s5;
	s4.rand = &s6;
	s5.rand = &s4;
	s6.rand = &s2;
	getmap(&s1);   //ִ����Ҫ��������
}
int main()
{
	test();
	return 0;
}
*/



















