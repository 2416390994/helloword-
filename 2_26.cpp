#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct Node
{
	int val;
	Node* next;
};
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
//最小栈
template<class T>
class MIN_STACK
{
public:
	void push(T&& val)
	{
		if (sta1.empty() && sta2.empty())
		{
			sta1.push(val);
			sta2.push(val);
			return;
		}
		if (sta2.top() < val)
		{
			sta2.push(sta2.top());
		}
		else
		{
			sta2.push(val);
		}
		sta1.push(val);
	}
	void pop()
	{
		sta1.pop();
		sta2.pop();
	}

private:
	stack<T> sta1;
	stack<T> sta2;
};

struct LS
{
	int a;
	int b;
};
class MIN_STACK2
{
public:
	void push(int val)
	{
		if (sta.empty())
		{
			LS a;
			a.a = val;
			a.b = val;
			sta.push(a);
		}
		else
		{
			if (sta.top().b < val)
			{
				LS a;
				a.a = val;
				a.b = sta.top().b;
				sta.push(a);
			}
			else
			{
				LS a;
				a.a = val;
				a.b = val;
				sta.push(a);
			}
		}
	}
	void pop()
	{
		sta.pop();
	}
	int min()
	{
		return sta.top().b;
	}


private:
	stack<LS> sta;
};

class MYqueue
{
public:
	void push(int val)
	{
		que1.push(val);
	}
	void pop()
	{
		if (que1.empty())
			return;
		while (que1.size() > 1)
		{
			que2.push(que1.front());
			que1.pop();
		}
		que1.pop();
		while (!que2.empty())
		{
			que1.push(que2.front());
			que2.pop();
		}
	}
	int top()
	{
		return que1.back();
	}
private:
	queue<int> que1;
	queue<int> que2;
};

void func1(vector<vector<int>>& vec,int num,int a,int b)
{
	int p1 = 0;
	int p2 = b;
	while (p1 <= a && p2 >= 0)
	{
		if (vec[p1][p2] > num)
		{
			p2--;
		}
		else
		{
			if (num == vec[p1++][p2])
			{
				cout << "找到了" << endl;
				return;
			}
		}
	}
	cout << "没找到" << endl;
}


//打印两个有序数组的共有数字
void func2(vector<int>& vec1,vector<int>& vec2)
{
	int size1 = vec1.size() - 1;
	int size2 = vec2.size() - 1;
	int i = 0;
	int j = 0;
	while (size1 >=0 && size2 >=0)
	{
		if (vec1[i] > vec2[j])
		{
			j++;
			size2--;
		}
		else if (vec1[i] < vec2[j])
		{
			i++;
			size1--;
		}
		else
		{
			cout << vec1[i] << endl;
			size1--;
			size2--;
			i++;
			j++;
		}
	}
}




int main()
{










	/*vector<int> vec1 = { 1, 2, 5, 8, 9 };
	vector<int> vec2 = { 2, 7, 8, 10 };
	func2(vec1, vec2);*/
	/*vector<vector<int>> vec = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	func1(vec, 1, 3, 3);
	func1(vec, 2, 3, 3);
	func1(vec, 3, 3, 3);
	func1(vec, 4, 3, 3);
	func1(vec, 5, 3, 3);
	func1(vec, 6, 3, 3);
	func1(vec, 7, 3, 3);
	func1(vec, 8, 3, 3);
	func1(vec, 9, 3, 3);
	func1(vec, 10, 3, 3);
	func1(vec, 11, 3, 3);
	func1(vec, 12, 3, 3);
	func1(vec, 13, 3, 3);
	func1(vec, 14, 3, 3);
	func1(vec, 15, 3, 3);
	func1(vec, 17, 3, 3);*/
	
	/*MYqueue A;
	A.push(1);
	A.push(2);
	A.pop();
	A.push(3);
	A.push(4);
	A.pop();
	A.push(5);
	A.push(6);*/

	/*MIN_STACK2 l;
	l.push(1);
	l.push(5);
	l.push(6);
	l.push(3);
	cout << l.min() << endl;*/
	return 0;
}