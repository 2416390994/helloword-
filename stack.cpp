#if 0
void test()
{
	stack<int>v;
	v.push(10);
	v.push(20);
	v.push(30);
	v.push(40);
	v.push(50);             
	stack<int>v1(v);        
	stack<int>v2 = v1;
	v2.pop();
	v2.pop();
	v2.pop();
	cout << v2.top() << endl;     
	if (v2.empty())
	{
		cout << "为空" << endl;
	}
	else
	{
		cout << "非空" << endl;
	}
	cout << v2.size() << endl;
	v2.pop();
	v2.pop();
	if (v2.empty())
	{
		cout << "为空" << endl;
	}
	else
	{
		cout << "非空" << endl;
	}
	cout << v2.size() << endl;
}
#endif
#if 0
#include<iostream>
#include<queue>
using namespace std;
void test()
{
	queue<int>v;
	v.push(10);
	v.push(20);
	v.push(30);
	v.push(40);
	v.push(50);
	while (!v.empty())
	{
		cout << "队头" << v.front() << endl;     //查看
		cout << "队尾" << v.back() << endl;
		v.pop();            //弹出
	}
	cout << v.size();
}
int main()
{
	test();
	return 0;
}
#endif