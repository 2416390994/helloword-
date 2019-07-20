#if 0
#include<deque>
#include<iostream>
#include<algorithm>
using namespace std;
void printfs(const deque<int>& p)
{
	//iterator普通迭代器   reverse_iterator逆序迭代器   const_iterator只读迭代器 
	for (deque<int>::const_iterator it = p.begin(); it != p.end(); ++it)   //这里设置为只读迭代器就不能够在内部对容器元素修改了
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
bool mycomparent(int a,int b)    //回调函数
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
	//cout << v.capacity << endl;    deque容器没有容量，无法查询容量大小啊
 }
//要使用系统自带的算法就必须要包含头文件#include<algorithm>
void test2()
{
	deque<int>v;
	v.push_back(4);
	v.push_back(9);
	v.push_back(6);
	v.push_back(7);
	v.push_back(2);

	sort(v.begin(), v.end());         //只能进行从小到达的排序
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