/*
#include<iostream>
#include<assert.h>
using namespace std;
struct push
{
	int value;
	push * next;
};
struct slist
{
	push *first;
};
void init(slist * l)
{
	assert(l->first != nullptr);
	l->first = nullptr;
}
void headpush(slist * l, int num)  //β��
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
void recover(slist * l,push * p)    //������ָ�ԭ״
{
	push *p1 = p;
	push *p2 = p1->next;
	p1->next = nullptr;   //һ��Ҫ��p2�ѽ���¼֮������p1ָ���
	push *p3 = nullptr;
	while (p2!=nullptr)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	push * pp = l->first;    //��ת��֮�������ô�ӡ��һ��
	while (pp != nullptr)
	{
		cout << pp->value << endl;;
		pp = pp->next;
	}
}
void reverse(slist *l)
{
	push *slow = l->first;
	push *fast = l->first;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//��һ������ʱ����ʵ�����Ѿ��õ����������м�λ�ã���ʵ������Ҫ�õ���Ҳ�����м�λ�ã�fastָ��Ҳ��û��ʲô����
	push *p1 = slow;
	push *p2 = slow->next;
	push *p3 = nullptr;     //p3��������¼��һ��λ�õ�
	p1->next = nullptr;
	while (p2 != nullptr)    ////���ѭ������Ҳ�ͽ�����ĺ�벿����ȫ��ת����
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}//ִ�����֮��p1��ָ���������β��
	push *PUSH = p1;   //���������β��㱣���������Ҫ������ת�ָ�����
	//����p1,p2����ָ��һ����ǰһ���ں󣬿�ʼ������������
	p2 = l->first; //��p1���»ص���ʼ��λ��
	while (p2 != nullptr)  //��Ϊ֮ǰ��ʱ��������slowָ�����ҵ��е�λ��֮�����е�λ�õ�nextָ����nullptr
	{
		if (p1->value != p2->value)
		{
			cout << "���ǻ�������" << endl;
			recover(l,PUSH);
			return;    
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	cout << "�ǻ�������" << endl;
	recover(l ,PUSH);
	
}
void test1()
{
	slist s;
	init(&s);
	headpush(&s, 1);    //��������
	headpush(&s, 2);
	headpush(&s, 4);
	headpush(&s, 3);
	headpush(&s, 2);
	headpush(&s, 1);
	reverse(&s);
}
int main()
{
	test1();
	return 0;
}
*/
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;
struct push
{
	int value;
	push * next;
};
struct slist
{
	push *first;
};
void init(slist * l)
{
	assert(l->first != nullptr);
	l->first = nullptr;
}
void headpush(slist * l, int num)  //β��
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
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func(slist *l,int num)    //��ʽ��ʼ�ĺ���
{
	vector<int>v;
	push *cur = l->first;   //�����ݿ�������
	while (cur != nullptr)
	{
		v.push_back(cur->value);
		cur = cur->next;
	}
	int size = v.size();   //���Ǹ����￪ʼ���к�����������
	int L = 0;
	int less = L -1;
	int more = size - 1;
	while (L < more)
	{
		if (v[L] > num)
		{
			swap(&v[L], &v[more--]);
		}
		else if (v[L] < num)
		{
			swap(&v[++less], &v[L++]);   //�ͺ�������һ����һ����Ϊ�˴����������
		}
		else
		{
			L++;
		}
	}
	cur = l->first;    //Ȼ���ź������������������д������
	for (int i = 0; i < size; ++i)
	{
		cur->value = v[i];
		cur = cur->next;
	}
	cur = l->first;    //������ָΪ�˴�ӡ��֤
	while (cur != nullptr)
	{
		cout << cur->value;
		cur = cur->next;
	}
}
void test()
{
	slist s;
	init(&s);
	headpush(&s, 1);    //��������
	headpush(&s, 2);
	headpush(&s, 4);
	headpush(&s, 3);
	headpush(&s, 3);
	headpush(&s, 6);
	headpush(&s, 4);
	headpush(&s, 7);
	headpush(&s, 6);
	func(&s,6);
}
int main()
{
	test();
	return 0;
}


















