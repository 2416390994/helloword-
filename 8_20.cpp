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
void headpush(slist * l, int num)  //尾插
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
void recover(slist * l,push * p)    //将链表恢复原状
{
	push *p1 = p;
	push *p2 = p1->next;
	p1->next = nullptr;   //一定要在p2把结点记录之后再让p1指向空
	push *p3 = nullptr;
	while (p2!=nullptr)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	push * pp = l->first;    //反转完之后我又让打印了一下
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
	//这一步的是时候其实我们已经拿到这个链表的中间位置，其实我们想要拿到的也就是中间位置，fast指针也就没有什么用了
	push *p1 = slow;
	push *p2 = slow->next;
	push *p3 = nullptr;     //p3是用来记录下一个位置的
	p1->next = nullptr;
	while (p2 != nullptr)    ////这个循环结束也就将链表的后半部分完全翻转过来
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}//执行完毕之后p1就指向了链表的尾部
	push *PUSH = p1;   //用这个结点把尾结点保存下来最后要用来反转恢复链表
	//再用p1,p2两个指针一个在前一个在后，开始遍历整个链表
	p2 = l->first; //让p1重新回到开始的位置
	while (p2 != nullptr)  //因为之前的时候我们让slow指针在找到中点位置之后，让中点位置的next指向了nullptr
	{
		if (p1->value != p2->value)
		{
			cout << "不是回文链表" << endl;
			recover(l,PUSH);
			return;    
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	cout << "是回文链表" << endl;
	recover(l ,PUSH);
	
}
void test1()
{
	slist s;
	init(&s);
	headpush(&s, 1);    //插入数据
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
void headpush(slist * l, int num)  //尾插
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
void func(slist *l,int num)    //正式开始的函数
{
	vector<int>v;
	push *cur = l->first;   //将数据拷进容器
	while (cur != nullptr)
	{
		v.push_back(cur->value);
		cur = cur->next;
	}
	int size = v.size();   //从那个这里开始进行荷兰国旗排序
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
			swap(&v[++less], &v[L++]);   //和荷兰国旗一样这一步是为了处理相等问题
		}
		else
		{
			L++;
		}
	}
	cur = l->first;    //然后将排好序的数组数据又重现写入链表
	for (int i = 0; i < size; ++i)
	{
		cur->value = v[i];
		cur = cur->next;
	}
	cur = l->first;    //这里是指为了打印验证
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
	headpush(&s, 1);    //插入数据
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


















