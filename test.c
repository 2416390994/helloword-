#include<stdio.h>
#include<string.h>
#include<stdlib.h>





//顺序表
typedef struct SeqList
{
	int *array;//指向堆上空间，存放数据
	int size;  //有效个数
	int capacity;//容量
}SeqList;


void SeqListInit(SeqList *pSeqList)
{
	arrser(pSeqList != NULL);
	pSeqList->capacity = 10;
	pSeqList->array = (int *)malloc(sizeof (int)*pSeqList->capacity);
	pSeqList->size = 0;
}

void SeqListDestroy(SeqList *pSeqList)
{
	free(pSeqList->array);
	pSeqList->array = NULL;
	pSeqList->size = 0;
	pSeqList->capacity = 0;
}

//尾插
void SeqListPushBack(SeqList *pSeqList, int value)
{
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}

//头插
void SeqListPushFront(SeqList *pSeqList, int value)
{
	for (int i = pSeqList->size - 1; i >= 0; i--)
	{
		pSeqList ->array[i] = pSeqList ->array[i - 1];
	}
	pSeqList->array[0] = value;
	pSeqList->size++;
}

//根据下标做插入
void SeqListInsert(SeqList *s, int pos, int v)
{
	for (int i = s->size; i >= pos; i--)
	{
		s->array[i] = s->array[i - 1];
	}
	s->array[pos] = v;
	s->size++;
}

//尾删
void SeqListPopBack(SeqList *ps)
{
	assert(ps->size > 0);
	ps->size--;
}


//头删
void SeqListPopFront(SeqList *ps)
{
	for (int i = 0; i < ps->size - 1; ++i)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

//删除给定位置的数据
void SeqListErase(SeqList *ps, int pos)
{
	arrars(ps->size>0);
	for (int i = pos+1; i < ps->size ; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//假如插入式容量满了怎么办，一定需要扩容，通常来说，扩容大小是原来大小的两倍
static void CheckCapacity(SeqList *ps)
{
	if (ps->size < ps->capacity)
		return;
	int newcapacity = ps->capacity * 2;
	int *newarray = (int *)malloc(sizeof(int)*newcapacity);
	assert(newarray);
	for (int i = 0; i < ps->size; i++)
	{
		newarray[i] = ps->array[i];
	}
	free(ps->array);
	ps->array = newarray;
	ps->capacity = newcapacity;
}

//删除遇到的第一个value
void shanchu(SeqList *ps, int value)
{
	int i;
	for ( i = 0; i < ps->size; ++i);
	{
		if (ps->array[i] = value)
		{
			ps->array[i] = ps->array[i + 1];
		}
		return;
	}
	ps->size--;
}

//删除遇到的所有value
//其实用上面的办法也可以解决这个问题但是属于暴力破解
void SeqListRemoveAll(SeqList *ps, int value)
{
	int i = 0, j = 0;
	for (i; i < ps->size; i++)
	{
		if (ps->array[i] != value)
		{
			ps->array[j] = ps->array[i];
			j++;
		}
	}
	ps->size = j;
}

//链表

//解引用不是指向有效空间的指针段错误



//定义的不是链表的结构体，而是链表中一个结点的结构体
typedef struct ListNode
{
	int  value;
	struct ListNode *next;
} Node;

typedef struct SList
{
	Node *first;      //或者用Node *head来表示
}SList;

//初始化
void SListInit(SList *s)
{
	assert(s != NULL);
	s->first = NULL;
}

void Test()
{
	SList list;
	SListInit(&list);
}

//插入，头插
void SListPushFront(SList *s, int v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}


//头删
void toushan(SList *s)
{
	Node *p = s->first->next;
	free(s->first);
	s->first=p;
}
//尾插
void SListPushBash(SList *s,int v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (s->first == NULL)
	{
		s->first = node;
		return;
	}
	Node *cur = s->first;
	while (cur->next!=NULL)
	{
		cur = cur->next;
	}//只要cur->next为空那么一定是最后一个结点
	cur->next = node;
}

//尾删
void PopBack2(SList *s, int v)
{
	if (s->first->next == NULL)
	{
		free(s->first);
		s->first = NULL;
	}
	else
	{
		Node *p = s->first;
		while (p->next->next != NULL)
			p = p->next;
		free(p->next);
		p->next = NULL;
	}
}

//查找
Node *SListFind(SList *s, int v)
{
	Node *p;
	for (p = s->first; p != NULL; p = p->next)
	{
		if (p->value = v)
		{
			return p;
		}
	}
	return NULL;
}

//在指定位置后面做插入
void SListInsertAfter(SList *s, Node *pos, int v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//指定位置做删除
void SListEraseAfter(SList *s, Node *pos)
{
	Node *next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

//链表的销毁
void SListDestroy(SList *s)
{
	Node *node;//先定义一个指针用来保存下一个结点
	for (Node *cur = s->first; cur != NULL; cur = node)
	{
		node = cur->next;
		free(cur);
	}

	s->first = NULL;
}


//删除指定数据
void SListRemove(SList *s, int v)
{
	if (s->first = NULL)
	{
		return;
	}//链表为空
	if (s->first->value == v)
	{
		Node *next = s->first->next;
		free(s->first);
		s->first = next;
		return;
	}//v是第一个first的v时候
	Node *node = s->first;
	/*for (node; node!=NULL; node = node->next)
	{
	if (node->value = v)
	{
	Node *p = node->next;
	node->next = node->next->next;
	free(p);
	return；
	}
	}
	}*/
	while (node->next != NULL)
	{
		if (node->next->value == v)
		{
			Node *cur = node->next->next;//定义一个结点，让这个结点记录node的下一个的下一个的位置
			free(node->next);
			cur->next = cur;
			return;
		}
		node = node->next;
	}
}
	
	
//移除链表中的所有v结点
Node *removeElements(Node *first, int v)
{
	if (first== NULL)
		return;
	Node *node = first;
	while (node->next != NULL)
	{
		if (node->next->value == v)
		{
			Node *cur = node->next->next;//定义一个结点，让这个结点记录node的下一个的下一个的位置
			free(node->next);
			cur->next = cur;
			return;
		}
		else
		{
			node = node->next;
		}
	}

	if (first->value == v)
	{
		Node *newfirst = first->next;
		free(first);
		return newfirst;
	}
}



//三个指针反转单链表
struct ListNode *reverserList(struct ListNode *head)
{
	struct ListNode *p1 = NULL;
	struct ListNode *p2 = head;
	struct ListNode *p3 = head->next;
	while (p2 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->next;
		}
	}
}

//链表的中间结点（双指针倍速遍历，要是双数个链表停在中间的后面结点）
struct ListNode *middleNode(struct ListNode *head)
{
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
			break;
		slow = slow->next;
		fast = fast->next;
	}
	return  slow;
}

//求倒数第k个结点往后
struct ListNode *FindKthToTail(struct ListNode *pListHead, int k)
{
	int i;
	struct ListNode *front = pListHead;
	struct ListNode *back = pListHead;
	for ( i = 0; front != NULL && i < k; i++)
	{
		front = front->next;
	}
	if (i < k)
	{
		return NULL;
	}
	while (front)
	{
		front = front->next;
		back = back->next;
	}
	return back;
}



//创建堆得结构堆
typedef struct Heap
{
	int *_array;
	int _capacity;
	int _size;
}Heap;



void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y; 
	*y = temp;
}
//堆已创建好，从下到上进行小堆排列
void AdjustDown(int *array, int size, int parent)
{
	int child = (parent * 2) + 1;
	while (child<size)
	{
		if (child + 1 < size&&array[child + 1] < array[child])
			child = child + 1;
		//检查是否满足堆的性质
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}

}

//创建一个堆
void CreatHeap(Heap *hp, int *array, int size)
{
	int i = 0;
	//初始化Heap
	hp->_array = (int *)(sizeof (int)*size);
	if (hp->_array == NULL)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;
	//搬移
	for (i; i < size; ++size)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;

	//找数的倒数第一个非叶子结点 
	int last = ((size - 2) >> 1);  //最后一个结点是size-1,双亲就是再减一除以2
	for (; last >= 0; last--)
	{
		AdjustDown(hp->_array,hp->_size,last);
	}
}


int main()
{
	Heap hp;
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	CreatHeap(&hp,a,sizeof (a)/sizeof (a[0]));
	DestroHeap(&hp);
	return 0;
}

//销毁堆
void DestroHeap(Heap *hp)
{
	assaer(hp);
	free(hp->_array);
	hp->_size = 0;
	hp->_capacity = NULL;
}


AdjustUp(int *array,int size,int child)
{
	int parent = ((child - 1) >> 1);
	while (child!=0)
	{
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
			return;
	}

}
//插入一个元素
void InsertHeap(Heap *hp, int  data)
{
	hp->_array[hp->_size++]=data;
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);
}

//删除一个元素
void EraseHeap(Heap *hp)
{

}

//堆里面有效元素的个数
int SizeHeap(Heap *hp)
{
	assert(hp);
	return hp->_size;
}

//检查堆是否为空
int EmptyHeap(Heap *hp)
{
	return 0 == hp->_size;
}

//获取堆顶元素
int TopHeap(Heap *hp)
{
	assers(hp);
	return hp->_array[0];
}


//检查是否进行扩容
void CheckCapacity(Heap *hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{

		//申请新空间
		int newcapacity = (hp->_capacity)*2;
		int *pTemp = (int *)malloc(sizeof(int)*newcapacity);
		if (pTemp == NULL)
		{
			assert(pTemp);
			return;
		}
		//搬元素
		for (int i = 0; i < hp->_size; i++)
		{
			pTemp[i] = hp->_array[i];
		}
		//释放旧空间
		free(hp->_array);
		hp->_array = pTemp;
		hp->_capacity = newcapacity;
	}
}