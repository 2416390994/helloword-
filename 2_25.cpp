#include<iostream>
#include<vector>
#include<time.h>
#include<string>
#include<stack>
#include<queue>
using namespace std;
#define INT 100;
#define SUN(a , b) a + b;
typedef   int uns;
void func(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = 0; j < vec.size() - 1 - i; ++j)
		{
			if (vec[j] < vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
}

void func1(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		int max = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[j] > vec[max])
				max = j;
		}
		swap(vec[i], vec[max]);
	}
}
void func2(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j > 0 && vec[j] > vec[j - 1]; --j)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
}
void func3(vector<int>& vec)
{
	int ges = vec.size() / 3;
	while (ges >= 1)
	{
		for (int i = ges; i < vec.size(); i += ges)
		{
			for (int j = i; j > 0 && vec[j] > vec[j - ges]; j -= ges)
			{
				swap(vec[j], vec[j - ges]);
			}
		}
		ges = ges / 3;
	}

}
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val)
		:val(_val)
		, left(nullptr)
		, right(nullptr)
	{
	}
};

bool func5(TreeNode* tree)
{
	if (tree == nullptr)
		return false;
}

void func6(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int j = i;
		while (vec[j] > vec[(j - 1) / 2])
		{
			swap(vec[j], vec[(j - 1) / 2]);
			j = (j - 1) / 2;
		}
	}
	int size = vec.size();
	while (--size)
	{
		swap(vec[0], vec[size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int great = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
			great = vec[great] > vec[index] ? great : index;
			if (great == index)
			{
				break;
			}
			swap(vec[great], vec[index]);
			index = left;
			left = index * 2 + 1;
		}
	}
}


int* func8(vector<int>& vec, int L, int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (vec[L] < vec[R])
		{
			swap(vec[++less], vec[L++]);
		}
		else if (vec[L] > vec[R])
		{
			swap(vec[L], vec[--more]);
		}
		else
		{
			L++;
		}
	}
	swap(vec[R], vec[more]);
	return new int[]{less, more + 1};
}
void func7(vector<int>& vec, int L, int R)
{
	if (L < R)
	{

		swap(vec[R], vec[L + rand() % (R - L) + 1]);
		int* p = func8(vec, L, R);
		func7(vec, L, p[0]);
		func7(vec, p[1], R);
	}
}


void func10(vector<int>& vec,int L,int M,int R)
{
	int *p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = vec[p1] > vec[p2] ? vec[p1++] : vec[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = vec[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = vec[p2++];
	}
	for (int i = 0; i < R - L + 1; ++i)
	{
		vec[L + i] = p[i];
	}

}
void func9(vector<int>& vec,int L,int R)
{
	if (L < R)
	{
		int M = L + (R - L) / 2;
		func9(vec, L, M);
		func9(vec, M + 1, R);
		func10(vec, L, M, R);
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
}

int func11(vector<int>& vec,int x)
{
	int L = 0;
	int R = vec.size();
	int M;
	while (L <= R)
	{
		M = (R + L) / 2;
		if (vec[M] > x)
		{
			R = M + 1;
		}
		else if (vec[M] < x)
		{
			L = M;
		}
		else
		{
			return M;
		}
	}
	return -1;
}

struct Node
{
	int val;
	Node* next;
	Node(int _val)
		: val(_val)
		, next(nullptr)
	{}
};
Node* func12(Node* tree)
{
	if (tree->next == nullptr || tree == nullptr)
	{
		return tree;
	}
	Node* pp = func12(tree->next);

	tree->next->next = tree;
	tree->next = nullptr;

	return pp;
}


Node* func13(Node* tree)
{
	Node* p1 = nullptr;
	Node* p2 = tree;
	Node* p3 = tree->next;
	while (p2 != nullptr)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3!=nullptr)
			p3 = p3->next;
	}
	return p1;
}

void func14(string str, int from, int to)
{
	if (from == to)
	{
		cout << str << endl;
		return;
	}
	for (int i = from; i <= to; ++i)
	{
		if (i != from && str[i] == str[from])
			continue;
		swap(str[i], str[from]);
		func14(str, from + 1, to);
	}
}
struct List
{
	Node* head;
};

void init(List* list)
{
	list->head = nullptr;
}
void push_back(List* list, int val)
{
	Node* p = new Node(val);
	if (list->head == nullptr)
		list->head = p;
	else
	{
		Node* cur = list->head;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = p;
	}
}
void pop_front(List* list)
{
	if (list->head == nullptr)
		return;
	list->head = list->head->next;
}

void pop_back(List* list)
{
	if (list->head == nullptr)
		return;
	Node* cur = list->head;
	while (cur->next->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = nullptr;
}




void func15()
{
	List list;
	init(&list);
	push_back(&list, 1);
	push_back(&list, 2);
	push_back(&list, 3);
	push_back(&list, 4);
	pop_front(&list);
	push_back(&list, 5);
	pop_back(&list);


	Node* cur = list.head;
	while (cur != nullptr)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}

}

void func16(vector<int>& vec)
{
	int L = 0;
	int R = vec.size() - 1;
	while (L < R)
	{
		if (vec[L] % 2 == 1)
		{
			L++;
		}
		else
		{
			swap(vec[L], vec[R--]);
		}
	}
}
class Queue
{
public:
	void push(int val)
	{
		sta1.push(val);
	}
	void pop()
	{
		if (sta1.empty() && sta2.empty())
			return;
		if (!sta2.empty())
		{
			sta2.pop();
			return;
		}
		while (!sta1.empty())
		{
			int a = sta1.top();
			sta2.push(a);
			sta1.pop();
		}
		sta2.pop();
		return;
	}


	stack<int> sta1;
	stack<int> sta2;
};
class Queue2
{
public:
	Queue2(int size)
		:size(0)
		, capacity(0)
		, front(0)
		, end(0)

	{
		vec.resize(size);
	}

	void push(int val)
	{
		if (size == capacity)
		{
			cout << "²åÈëÊ§°Ü" << endl;
			return;
		}
		vec[front] = val;
		size++;
		end = (end + 1) % capacity;
	}
	void pop()
	{
		if (size == 0)
		{
			cout << "µ¯³öÊ§°Ü" << endl;
			return;
		}
		size--;
		front = (front + 1) % capacity;
	}
	int _front()
	{
		if (size == 0)
			return -1;
		return vec[front];
	}
	int _back()
	{
		if (size == 0)
			return -1;
		return vec[(end - 1 + capacity) % capacity];
	}
private:
	vector<int> vec;
	int size;
	int capacity;
	int front;
	int end;
};
void func18(char* str,int size)
{
	int count = 0;
	for (int i = 0; i <= size; ++i)
	{
		if (str[i] == ' ')
			count++;
	}
	for (int i = size; i >= 0; --i)
	{
		if (str[i] != ' ')
		{
			str[i + count] = str[i];
		}
		else
		{
			count--;
			str[i + count] = '%';
			str[i + count + 1] = '2';
			//str[i + count * 2 + 2] = '0';
		}
	}
}

int func19(int val)
{
	if (val == 1 || val == 2)
		return 1;
	return func19(val - 1) + func19(val - 2);
}

void func20()
{
	cout <<  INT_MAX << endl;
	int a = 15;
	int count = 0;
	while (a)
	{
		if (a & 0x00000001 == 1)
			count++;
		a >>= 1;
	}
	cout << count << endl;
}



int main()
{




	//func20();
	/*vector<int> vec;
	vec.reserve(10);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;*/
	//cout<<func19(5);
	//char array[100] = "i love you";
	//func18(array,9);
	//cout << array << endl;
	//vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//func16(vec);
	/*Queue que;
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	que.push(5);
	que.pop();
	que.pop();
	que.pop();*/

	//func15();
	//func14("aac", 0, 2);

	/*Node* p1 = new Node(1);
	Node* p2 = new Node(2);
	Node* p3 = new Node(3);
	Node* p4 = new Node(4);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	Node* pp = func13(p1);
	Node* cur = pp;
	while (cur)
	{
		cout << cur->val;
		cur = cur->next;
	}*/



	srand((unsigned int)time(NULL));
	//vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//func(vec);
	//func1(vec);
	//func2(vec);
	//func3(vec);
	//func6(vec);
	//func7(vec,0, 9);
	//func9(vec, 0, 9);
	//cout << func11(vec, 9) << endl;

	/*int g_a = 10;
	int a = 3, b = 4;
	auto fs = [=, &g_a]{return a + 3; };
	*/
	/*for (auto e : vec)
		cout << e << endl;*/
	return 0;
}