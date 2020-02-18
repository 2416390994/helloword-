#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class myqueue
{
public:
	bool push(int num)
	{
		sta1.push(num);
		return true;
	}
	int pop()
	{
		if (sta1.empty() && sta2.empty())
			return -1;
		if (sta2.empty())
		{
			while (!sta1.empty())
			{
				sta2.push(sta1.top());
				sta1.pop();
			}
		}
		int s = sta2.top();
		sta2.pop();
		return s;
	}
private:
	stack<int> sta1;
	stack<int> sta2;
};


int main()
{
	myqueue que;
	cout << que.pop() << endl;
	que.push(1);
	que.push(2);
	que.push(3);
	que.pop();
	cout << que.pop() << endl;
	return 0;
}