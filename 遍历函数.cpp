#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>//1.添件头文件functional
#include<string>
using namespace std;
#if 0
//第一个就是：for_each前面我们已经学过了利用仿函数，或者回调函数打印的方法
//第二种我们介绍其他的用法：可以利用for_each的返回值记录数据
//因为伪函数本身就是一个类，内部可以维护很多的数据
class person
{
public:
	void operator()(int v)
	{
		count++;
		cout << v << endl;
	}
	int count;
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	person p1 = for_each(v.begin(), v.end(), person());    //函数返回值，函数就是返回一个类类型的对象
	cout << p1.count << endl;;
}
//第三种for_each可以绑定参数进行输出，利用适配器
class person01:public binary_function<int,int,void>
{
public:
	void operator()(int v,int start)const
	{
		cout << v + start << endl;
	}
};
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	for_each(v.begin(), v.end(), bind2nd(person01(),100));    //在第三个参数进行绑定目的是让在插入数据的基础上+100
}
#endif
class person02 :public binary_function<int, int, int>
{
public:
	int operator()(int v, int start)const
	{
		return v + start;
	}
};
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	vector<int>v1;
	v1.resize(v.size());     //申请空间
	transform(v.begin(), v.end(), v1.begin(), bind2nd(person02(), 10));   //按照需求搬移元素
	for_each(v.begin(), v.end(), [](int val){cout << val << endl; });    //打印
}
class func
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
void test04()
{
	vector<int>p1;
	vector<int>p2;
	for (int i = 0; i < 10; ++i)
	{
		p1.push_back(i + 10);
		p2.push_back(i + 20);
	}
	vector<int>p3;
	p3.resize(p1.size());
	transform(p1.begin(), p1.end(), p2.begin(), p3.begin(),func()); 
	for_each(p3.begin(), p3.end(), [](int val){cout << val << endl; });    
}
int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}