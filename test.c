#include<stdio.h>
#include<string.h>
#include<stdlib.h>





//˳���
typedef struct SeqList
{
	int *array;//ָ����Ͽռ䣬�������
	int size;  //��Ч����
	int capacity;//����
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

//β��
void SeqListPushBack(SeqList *pSeqList, int value)
{
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}

//ͷ��
void SeqListPushFront(SeqList *pSeqList, int value)
{
	for (int i = pSeqList->size - 1; i >= 0; i--)
	{
		pSeqList ->array[i] = pSeqList ->array[i - 1];
	}
	pSeqList->array[0] = value;
	pSeqList->size++;
}

//�����±�������
void SeqListInsert(SeqList *s, int pos, int v)
{
	for (int i = s->size; i >= pos; i--)
	{
		s->array[i] = s->array[i - 1];
	}
	s->array[pos] = v;
	s->size++;
}

//βɾ
void SeqListPopBack(SeqList *ps)
{
	assert(ps->size > 0);
	ps->size--;
}


//ͷɾ
void SeqListPopFront(SeqList *ps)
{
	for (int i = 0; i < ps->size - 1; ++i)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

//ɾ������λ�õ�����
void SeqListErase(SeqList *ps, int pos)
{
	arrars(ps->size>0);
	for (int i = pos+1; i < ps->size ; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//�������ʽ����������ô�죬һ����Ҫ���ݣ�ͨ����˵�����ݴ�С��ԭ����С������
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

//ɾ�������ĵ�һ��value
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

//ɾ������������value
//��ʵ������İ취Ҳ���Խ��������⵫�����ڱ����ƽ�
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

//����

//�����ò���ָ����Ч�ռ��ָ��δ���



//����Ĳ�������Ľṹ�壬����������һ�����Ľṹ��
typedef struct ListNode
{
	int  value;
	struct ListNode *next;
} Node;

typedef struct SList
{
	Node *first;      //������Node *head����ʾ
}SList;

//��ʼ��
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

//���룬ͷ��
void SListPushFront(SList *s, int v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}


//ͷɾ
void toushan(SList *s)
{
	Node *p = s->first->next;
	free(s->first);
	s->first=p;
}
//β��
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
	}//ֻҪcur->nextΪ����ôһ�������һ�����
	cur->next = node;
}

//βɾ
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

//����
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

//��ָ��λ�ú���������
void SListInsertAfter(SList *s, Node *pos, int v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//ָ��λ����ɾ��
void SListEraseAfter(SList *s, Node *pos)
{
	Node *next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

//���������
void SListDestroy(SList *s)
{
	Node *node;//�ȶ���һ��ָ������������һ�����
	for (Node *cur = s->first; cur != NULL; cur = node)
	{
		node = cur->next;
		free(cur);
	}

	s->first = NULL;
}


//ɾ��ָ������
void SListRemove(SList *s, int v)
{
	if (s->first = NULL)
	{
		return;
	}//����Ϊ��
	if (s->first->value == v)
	{
		Node *next = s->first->next;
		free(s->first);
		s->first = next;
		return;
	}//v�ǵ�һ��first��vʱ��
	Node *node = s->first;
	/*for (node; node!=NULL; node = node->next)
	{
	if (node->value = v)
	{
	Node *p = node->next;
	node->next = node->next->next;
	free(p);
	return��
	}
	}
	}*/
	while (node->next != NULL)
	{
		if (node->next->value == v)
		{
			Node *cur = node->next->next;//����һ����㣬���������¼node����һ������һ����λ��
			free(node->next);
			cur->next = cur;
			return;
		}
		node = node->next;
	}
}
	
	
//�Ƴ������е�����v���
Node *removeElements(Node *first, int v)
{
	if (first== NULL)
		return;
	Node *node = first;
	while (node->next != NULL)
	{
		if (node->next->value == v)
		{
			Node *cur = node->next->next;//����һ����㣬���������¼node����һ������һ����λ��
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



//����ָ�뷴ת������
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

//������м��㣨˫ָ�뱶�ٱ�����Ҫ��˫��������ͣ���м�ĺ����㣩
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

//������k���������
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



//�����ѵýṹ��
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
//���Ѵ����ã����µ��Ͻ���С������
void AdjustDown(int *array, int size, int parent)
{
	int child = (parent * 2) + 1;
	while (child<size)
	{
		if (child + 1 < size&&array[child + 1] < array[child])
			child = child + 1;
		//����Ƿ�����ѵ�����
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

//����һ����
void CreatHeap(Heap *hp, int *array, int size)
{
	int i = 0;
	//��ʼ��Heap
	hp->_array = (int *)(sizeof (int)*size);
	if (hp->_array == NULL)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;
	//����
	for (i; i < size; ++size)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;

	//�����ĵ�����һ����Ҷ�ӽ�� 
	int last = ((size - 2) >> 1);  //���һ�������size-1,˫�׾����ټ�һ����2
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

//���ٶ�
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
//����һ��Ԫ��
void InsertHeap(Heap *hp, int  data)
{
	hp->_array[hp->_size++]=data;
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);
}

//ɾ��һ��Ԫ��
void EraseHeap(Heap *hp)
{

}

//��������ЧԪ�صĸ���
int SizeHeap(Heap *hp)
{
	assert(hp);
	return hp->_size;
}

//�����Ƿ�Ϊ��
int EmptyHeap(Heap *hp)
{
	return 0 == hp->_size;
}

//��ȡ�Ѷ�Ԫ��
int TopHeap(Heap *hp)
{
	assers(hp);
	return hp->_array[0];
}


//����Ƿ��������
void CheckCapacity(Heap *hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{

		//�����¿ռ�
		int newcapacity = (hp->_capacity)*2;
		int *pTemp = (int *)malloc(sizeof(int)*newcapacity);
		if (pTemp == NULL)
		{
			assert(pTemp);
			return;
		}
		//��Ԫ��
		for (int i = 0; i < hp->_size; i++)
		{
			pTemp[i] = hp->_array[i];
		}
		//�ͷžɿռ�
		free(hp->_array);
		hp->_array = pTemp;
		hp->_capacity = newcapacity;
	}
}