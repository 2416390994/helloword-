/*
#include<iostream>
#include<stack>
#include<time.h>
using namespace std;
//template<class T>
class stack1
{
public:
	stack1()
	{}
	~stack1()
	{}
	void push(int num)               //压入元素
	{
		if (p1.size() == 0)
		{
			this->p1.push(num);
			this->p2.push(num);
		}
		else
		{
			this->p1.push(num);
			push1(num);
		}
	}
	void push1(int num)       //p2压入规则
	{
		if (p2.top() > num)
		{
			p2.push(num);
		}
		else
		{
			p2.push(p2.top());
		}
	}
	void pop()
	{
		if (p1.size() == 0)
		{
			cout << "栈已空，无法弹出" << endl;
		}
		p1.pop();
		p2.pop();
	}
	int get_min()
	{
		if (p2.size() == 0)
		{
			cout << "栈已空，无法弹出" << endl;
		}
		return p2.top();
	}
	int top()
	{
		if (p1.size() == 0)
		{
			perror("已空");
		}
		p2.top();
		return p1.top();
	}	
private:
	stack<int>p1;
	stack<int>p2;
};
int main()
{
	srand((unsigned int)time(NULL));
	stack1 v;
	for (int i = 0; i < 10; ++i)
	{
		v.push(rand() % 5);
	}
	for (int i = 0; i < 10; ++i)
	{	
		cout << v.get_min() ;
		cout << v.top() << endl;
		v.pop();
	}
	return 0;
}
*/
/*
#include<iostream>
#include<stack>
using namespace std;
class stack1
{
public:
	stack1()
	{}
	~stack1()
	{}
	void push(int num)               //压入元素
	{
		if (p1.size() == 0)
		{
			this->p1.push(num);
			this->p2.push(num);
		}
		else
		{
			this->p1.push(num);
			push1(num);
		}
	}
	void push1(int num)       //p2压入规则
	{
		if (p2.top() >= num)   //堆顶元素大于或者等于新压入的元素，压入
		{
			p2.push(num);
		}
		else       //否则不做任何处理
		{}
	}
	void pop()           //弹出
	{
		if (p1.size() == 0)
		{
			cout << "栈已空，无法弹出" << endl;
		}
		pop1();
		p1.pop();	
	}
	void pop1()
	{
		if (p1.top() > p2.top())
		{
		}
		if (p1.top() == p2.top())
		{
			p2.pop();
		}
	}
	int get_min()
	{
		if (p2.size() == 0)
		{
			cout << "栈已空，无法弹出" << endl;
		}
		return p2.top();
	}
	int top()
	{
		if (p1.size() == 0)
		{
			perror("已空");
		}
		p2.top();
		return p1.top();
	}
private:
	stack<int>p1;
	stack<int>p2;
};
int main()
{
	stack1 v;
		v.push(3);
		v.push(5);
		v.push(1);
		v.push(2);
		v.push(1);
	for (int i = 0; i < 5; ++i)
	{
		cout << v.get_min();
		cout << v.top() << endl;
		v.pop();
	}
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
#include<queue>
class MYstack
{
public:
	void push1(int num)  //插入
	{
		this->p1.push(num);
	}
	void pop()   //弹出
	{
		while (p2.size() > 0)//复用，完了之后再将p2搬移回p1
		{
			swap(p1, p2);
		}
		while (p1.size() > 1)      //搬移直到p1只剩下一个元素
		{
			p2.push(p1.front());   //将第一个队列的首元素搬移到第二个队列
			p1.pop();//每次搬移完之后把这个元素弹走
		}
		p1.pop();    //然后将队中唯一元素弹掉
	}
	int top()   //查看
	{
		while (p2.size() > 0)
		{
			swap(p1, p2);
		}
		return p1.back();
	}
private:
	queue<int>p1;
	queue<int>p2;
};
int main()
{
	MYstack v;
	v.push1(1);
	v.push1(2);
	v.push1(3);
	v.push1(4);
	v.push1(5);
	for (int i = 0; i < 5; i++)
	{
		cout << v.top() << endl;
		v.pop();
	}
	return 0;
}
*/
#include<iostream>
#include<stack>
using namespace std;
class MYqueue
{
public:
	void mypush(int num)
	{
		this->p1.push(num);
	}
	int mytop()
	{
		while (p1.size() > 0 && p2.size()==0)
		{
			p2.push(p1.top());
			p1.pop();
		}
		return p2.top();
	}

private:
	stack<int>p1;
	stack<int>p2;
};
int main()
{

	return 0;
}















