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
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "�ǿ�" << endl;
	}
	cout << v2.size() << endl;
	v2.pop();
	v2.pop();
	if (v2.empty())
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "�ǿ�" << endl;
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
		cout << "��ͷ" << v.front() << endl;     //�鿴
		cout << "��β" << v.back() << endl;
		v.pop();            //����
	}
	cout << v.size();
}
int main()
{
	test();
	return 0;
}
#endif