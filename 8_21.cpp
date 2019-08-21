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
			swap(&a[++less], &a[L++]);   //和荷兰国旗一样这一步是为了处理相等问题
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
//空间复杂度为0（1）的方法使一个链表的左边是大于，中间等于，右边小于某个数字的
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
void find(slist *l,int num)    //主操作函数
{
	push *cur = l->first;   
	push * big = nullptr;     //定义了六个push类型的指针，其中每一组有两个指针，一个是记录头结点的，一个是记录下一个节点的位置的
	push * big2 = nullptr;   //也就是说一个指针是不动的，只用来标记头结点，一个是动的，随着元素的增加他始终记录的是这个链表的尾，用来下一次的插入
	push * small = nullptr;
	push * small2 = nullptr;
	push * equal = nullptr;
	push * equal2 = nullptr;
	while (cur != nullptr)   //cur用来遍历整个链表，遍历的同时比较链表元素和num的大小
	{
		if (cur->value < num)    //如果小的话
		{
			if (small == nullptr)   //如果是小的是第一次的话就直接让两个指针都指向这个结点
			{
				small = cur;
				small2 = cur;
			}
			else   //如果不是第一个的话
			{
				small2->next = cur;  //那么就让small2指向的结点连接下一个位置
				small2 = small2->next;  //不要忘记让small2也跟着移动，始终指向尾
			}
		}
		if (cur->value > num)    //道理和上面的一样
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
		cur = cur->next;   //每次判断完，则主链表后移一个位置
	}
	//三个分链表，进行整和，整和需要注意的有两点
	//1.首先给定的划分之不一定会在这个链表的中间位置，也就是说，big,small，equal，三个链表不一定每一个链表都是有值的，有可能
	//一个或者两个为空的情况，但是三个链表不一定都为空，所以首先要对判断三个链表哪个不为空之后再对链表进行连接
	//2 .因为在链表还是一个整链表的时候，只有尾部是指向nullper，但是分成三个链表之后，
	//最后一个值不一定在哪个分链表，他有可能大于，小于，或者等于划分值，如果这个时候直接将三个链表首尾整合，结果肯定是无法预知
	//所以在整和前首先要进行的就是让big链表的最后一个结点指向空，再进行连接
	if (small == nullptr)    //如果small链表为空       
	{
		if (equal != nullptr && big != nullptr)   //但是equal和big不为空
		{	   
			big2->next = nullptr;//那么就让big指向空
			l->first = equal;//因为之前的结构体已经被破坏，所以要重新给头指针赋值
			equal2->next = big;  //让不为空的两个链表连接
		}
		else if (equal == nullptr && big != nullptr)    //如果equal为空big不为空
		{
			big2->next = nullptr;
			l->first = big;
		}
		else if (equal !=nullptr && big == nullptr)  //如果equal不为空，big为空
		{
			equal2->next = nullptr;
			l->first = equal;
		}
	}
	if (equal == nullptr)    //和上面一样
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
	if (big == nullptr)   //和上面一样
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
	if (small != nullptr && equal != nullptr && big != nullptr)   //这个就是刚好划分之就是中间的位置，三个链表都不为空
	{
		big2->next = nullptr;
		small2->next = equal;
		equal2->next = big;
	}
}
void printfs(slist *l)    ///打印函数用来检验代码是否正确
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
	printfs(&s);    //尝试打印一下看看是否正确
}
int main()
{
	test();
	return 0;
}



















