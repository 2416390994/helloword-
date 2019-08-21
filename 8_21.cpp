/*
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func(int *a,int size,int num)
{
	int L = 0;
	int less = L - 1;
	int more = size - 1;
	while (L < more)
	{
		if (a[L] > num)
		{
			swap(&a[L], &a[more--]);
		}
		else if (a[L] < num)
		{
			swap(&a[++less], &a[L++]);   //�ͺ�������һ����һ����Ϊ�˴����������
		}
		else
		{
			L++;
		}
	}
}
int main()
{
	int a[] = { 2, 5, 4, 8, 9, 7, 5, 6, 5, 5, 5, 4, 1, 3, 2 };
	func(a, 15,5);
	for (int i = 0; i < 15; ++i)
	{
		cout << a[i] << endl;
	}
	return 0;
}
*/
//�ռ临�Ӷ�Ϊ0��1���ķ���ʹһ�����������Ǵ��ڣ��м���ڣ��ұ�С��ĳ�����ֵ�
#include<iostream>
#include<assert.h>
using namespace std;
struct push
{
	push * next;
	int value;
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
void backpush(slist *l,int num)
{
	push *p = new push;
	p->next = nullptr;
	p->value = num;
	if (l->first == nullptr)
	{
		l->first = p;
		return;
	}
	push * cur = l->first;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = p;
}
void find(slist *l,int num)    //����������
{
	push *cur = l->first;   
	push * big = nullptr;     //����������push���͵�ָ�룬����ÿһ��������ָ�룬һ���Ǽ�¼ͷ���ģ�һ���Ǽ�¼��һ���ڵ��λ�õ�
	push * big2 = nullptr;   //Ҳ����˵һ��ָ���ǲ����ģ�ֻ�������ͷ��㣬һ���Ƕ��ģ�����Ԫ�ص�������ʼ�ռ�¼������������β��������һ�εĲ���
	push * small = nullptr;
	push * small2 = nullptr;
	push * equal = nullptr;
	push * equal2 = nullptr;
	while (cur != nullptr)   //cur����������������������ͬʱ�Ƚ�����Ԫ�غ�num�Ĵ�С
	{
		if (cur->value < num)    //���С�Ļ�
		{
			if (small == nullptr)   //�����С���ǵ�һ�εĻ���ֱ��������ָ�붼ָ��������
			{
				small = cur;
				small2 = cur;
			}
			else   //������ǵ�һ���Ļ�
			{
				small2->next = cur;  //��ô����small2ָ��Ľ��������һ��λ��
				small2 = small2->next;  //��Ҫ������small2Ҳ�����ƶ���ʼ��ָ��β
			}
		}
		if (cur->value > num)    //����������һ��
		{
			if (big == nullptr)
			{
				big = cur;
				big2 = cur;
			}
			else
			{
				big2->next = cur;
				big2 = big2->next;
			}
		}
		if (cur->value == num)
		{
			if (equal == nullptr)
			{
				equal = cur;
				equal2 = cur;
			}
			else
			{
				equal2->next = cur;
				equal2 = equal2->next;
			}
		}
		cur = cur->next;   //ÿ���ж��꣬�����������һ��λ��
	}
	//�����������������ͣ�������Ҫע���������
	//1.���ȸ����Ļ���֮��һ���������������м�λ�ã�Ҳ����˵��big,small��equal����������һ��ÿһ����������ֵ�ģ��п���
	//һ����������Ϊ�յ������������������һ����Ϊ�գ���������Ҫ���ж����������ĸ���Ϊ��֮���ٶ������������
	//2 .��Ϊ��������һ���������ʱ��ֻ��β����ָ��nullper�����Ƿֳ���������֮��
	//���һ��ֵ��һ�����ĸ����������п��ܴ��ڣ�С�ڣ����ߵ��ڻ���ֵ��������ʱ��ֱ�ӽ�����������β���ϣ�����϶����޷�Ԥ֪
	//����������ǰ����Ҫ���еľ�����big��������һ�����ָ��գ��ٽ�������
	if (small == nullptr)    //���small����Ϊ��       
	{
		if (equal != nullptr && big != nullptr)   //����equal��big��Ϊ��
		{	   
			big2->next = nullptr;//��ô����bigָ���
			l->first = equal;//��Ϊ֮ǰ�Ľṹ���Ѿ����ƻ�������Ҫ���¸�ͷָ�븳ֵ
			equal2->next = big;  //�ò�Ϊ�յ�������������
		}
		else if (equal == nullptr && big != nullptr)    //���equalΪ��big��Ϊ��
		{
			big2->next = nullptr;
			l->first = big;
		}
		else if (equal !=nullptr && big == nullptr)  //���equal��Ϊ�գ�bigΪ��
		{
			equal2->next = nullptr;
			l->first = equal;
		}
	}
	if (equal == nullptr)    //������һ��
	{
		if (small != nullptr && big != nullptr)
		{
			small2->next = nullptr;
			big2->next = nullptr;
			l->first = small;
			small2->next = big;
		}
		else if (small == nullptr && big != nullptr)
		{
			big2->next = nullptr;
			l->first = big;
		}
		else if (small != nullptr && big == nullptr)
		{
			small2->next = nullptr;
			l->first = small;
		}
	}
	if (big == nullptr)   //������һ��
	{
		if (small != nullptr && equal != nullptr)
		{
			small2->next = nullptr;
			equal2->next = nullptr;
			l->first = small;
			small2->next = equal;
		}
		else if (small == nullptr && equal != nullptr)
		{
			equal2->next = nullptr;
			l->first = equal;
		}
		else if (small != nullptr && equal == nullptr)
		{
			small2->next = nullptr;
			l->first = small;
		}
	}
	if (small != nullptr && equal != nullptr && big != nullptr)   //������Ǹպû���֮�����м��λ�ã�����������Ϊ��
	{
		big2->next = nullptr;
		small2->next = equal;
		equal2->next = big;
	}
}
void printfs(slist *l)    ///��ӡ����������������Ƿ���ȷ
{
	push *cur = l->first;
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
	backpush(&s, 1);
	backpush(&s, 6);
	backpush(&s, 5);
	backpush(&s, 4);
	backpush(&s, 8);
	backpush(&s, 5);
	backpush(&s, 6);
	backpush(&s, 6);
	backpush(&s, 4);
	find(&s, 5);
	printfs(&s);    //���Դ�ӡһ�¿����Ƿ���ȷ
}
int main()
{
	test();
	return 0;
}



















