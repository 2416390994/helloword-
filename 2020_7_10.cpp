#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;

void printf_(vector<int> vec)
{
	for (auto e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
}

void func1(vector<int>& vec)
{
	int L = 0;
	int less = L - 1;
	int more = vec.size();
	while (L < more)
	{
		if (vec[L] < 2)
		{
			swap(vec[L++], vec[++less]);
		}
		else if (vec[L] > 2)
		{
			swap(vec[L], vec[--more]);
		}
		else
			L++;
	}
}

void func2(vector<int> vec)
{
	int L = 0;
	int less = L - 1;
	int more = vec.size();
	while (L < more)
	{
		if (vec[L] % 2 == 1)
		{
			L++;
			less++;
		}
		else
		{
			swap(vec[L], vec[--more]);
		}
	}
	printf_(vec);
}

void func3(vector<int> vec,int find)
{
	int L = 0;
	int R = vec.size();
	while (L < R)
	{
		int M = (R + L) / 2;
		if (vec[M] > find)
		{
			R = M - 1;
		}
		else if (vec[M] < find)
		{
			L = M;
		}
		else
		{
			cout << M << endl;
			return;
		}
	}
	cout << "ɵ��" << endl;
}

//����ʵ��ջ�Ͷ���
//����ʵ��ջ
class zhan
{
public:
	zhan()
	{
		vec1.resize(10);
		size = 0;
	}

	bool push(int val)
	{
		if (size + 1 < 10)
		{
			size++;
		}
		else
		{
			cout << "ջ����" << endl;
			return false;
		}

		vec1[(back++) % 10] = val;
	}
	bool  pop()
	{
		if (size == 0)
		{
			cout << "ջ��" << endl;
		}
		size--;
		front++;
	}
private:
	vector<int> vec1;
	int size;
	int back = 0;
	int front = 0;
};

//���ζ���
class ���ζ���
{
public:
	���ζ���()
	{
		vec.resize(10);
		size = 0;
		back = 0;
		front = 0;
	}

	bool push(int val)
	{
		if (size == 10)
		{
			cout << "��������" << endl;
			return false;
		}
		size++;
		vec[(back++) % 10] = val;
	}

	bool pop()
	{
		if (size == 0)
		{
			cout << "�����ѿ�" << endl;
			return  false;
		}
		size--;
		front = (front++) % 10;
	}

	int front_()
	{
		return vec[front];
	}

	int back_()
	{
		return  vec[(back + 10 - 1) % 10];
	}
private:
	vector<int> vec;
	int size;
	int back;
	int front;
};
//��Сջ
class ��Сջ
{
public:
	void push(int val)
	{
		if (sta1.size() == 0)
		{
			sta1.push(val);
			sta2.push(val);
			return;
		}
		else
		{
			sta1.push(val);
			if (val < sta2.top())
			{
				sta2.push(val);
			}
			else
			{
				sta2.push(sta2.top());
			}
		}
	}
	
	void pop()
	{
		sta1.pop();
		sta2.pop();
	}
	
	int front()
	{
		return sta1.top();
	}


private:
	stack<int> sta1;
	stack<int> sta2;
};


//��ջʵ�ֶ���
class ��ջʵ�ֶ���
{
public:
	bool push(int val)
	{
		sta1.push(val);
		return true;
	}
	bool pop()
	{
		if (sta2.empty())
		{
			while (!sta1.empty())
			{
				sta2.push(sta1.top());
				sta1.pop();
			}
			sta2.pop();
		}
		return true;
	}
private:
	stack<int> sta1;
	stack<int> sta2;
};


//�ö���ʵ��ջ
class �ö���ʵ��ջ
{
public:
	bool push(int val)
	{
		que1.push(val);
		return true;
	}

	int front()
	{
		if (que1.size() != 1)
		{
			que2.push(que1.front());
		}
		int ret = que1.front();
		que1.pop();
		swap(que1, que2);
		return ret;
	}

	bool pop()
	{
		if (que1.size() != 1)
		{
			que2.push(que1.front());
		}
		que1.pop();
		swap(que1, que2);
		return true;
	}
private:
	queue<int> que1;
	queue<int> que2;
};

int main()
{
	vector<int> vec = { 2, 2, 2, 1, 1, 0, 1, 3, 0, 1, 2, 5, 1, 2, 0, 3 };
	func1(vec);
	printf_(vec);
	func2(vec);
	vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	func3(vec1,1);


	��ջʵ�ֶ��� p;
	p.push(1);
	p.push(2);
	p.pop();
	p.pop();
	p.push(3);
	p.pop();
	p.push(4);
	p.push(5);
	p.push(6);
	p.pop();



	return 0;
}