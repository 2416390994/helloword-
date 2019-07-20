#if 0
#include<deque>
#include<iostream>
#include<algorithm>
using namespace std;
void printfs(const deque<int>& p)
{
	//iterator��ͨ������   reverse_iterator���������   const_iteratorֻ�������� 
	for (deque<int>::const_iterator it = p.begin(); it != p.end(); ++it)   //��������Ϊֻ���������Ͳ��ܹ����ڲ�������Ԫ���޸���
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
bool mycomparent(int a,int b)    //�ص�����
{
	return a > b; 
}
void  test()
{
	deque<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	printfs(v);
	deque<int>v1(v.begin(),v.end());
	v1.push_back(100);
	v1.swap(v);
	printfs(v);
}
void test1()
{
	deque<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_front(50);
	v.push_front(40);
	v.push_front(60);
	v.pop_back();
	v.pop_back();
	v.pop_front();
	printfs(v);
	cout << v.back() << endl;
	cout << v.front() << endl;
	//cout << v.capacity << endl;    deque����û���������޷���ѯ������С��
 }
//Ҫʹ��ϵͳ�Դ����㷨�ͱ���Ҫ����ͷ�ļ�#include<algorithm>
void test2()
{
	deque<int>v;
	v.push_back(4);
	v.push_back(9);
	v.push_back(6);
	v.push_back(7);
	v.push_back(2);

	sort(v.begin(), v.end());         //ֻ�ܽ��д�С���������
	printfs(v);
	sort(v.begin(), v.end(), mycomparent);
	printfs(v);
}
int main()
{
	test2();
	return 0;
}
#endif